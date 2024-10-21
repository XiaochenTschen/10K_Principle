import tkinter as tk
from tkinter import simpledialog
import socket
import threading

class UDPClient:
    def __init__(self, master):
        self.master = master
        master.title("UDP Client")

        # IP地址和端口的配置
        self.ip_label = tk.Label(master, text="IP Address:")
        self.ip_label.grid(row=0, column=0, sticky="e")
        self.ip_entry = tk.Entry(master)
        self.ip_entry.grid(row=0, column=1, columnspan=3, sticky="ew")

        self.port_label = tk.Label(master, text="Port:")
        self.port_label.grid(row=1, column=0, sticky="e")
        self.port_entry = tk.Entry(master)
        self.port_entry.grid(row=1, column=1, columnspan=3, sticky="ew")

        # 数据输入
        self.data_entries = []
        for i in range(8):
            label = tk.Label(master, text=f"Byte {i+1}:")
            label.grid(row=2, column=i, padx=5)
            entry = tk.Entry(master, width=5)
            entry.grid(row=3, column=i, padx=5)
            self.data_entries.append(entry)

        # 发送按钮
        self.send_button = tk.Button(master, text="Send", command=self.send_data)
        self.send_button.grid(row=4, column=0, columnspan=8)

        # 接收显示
        self.response_label = tk.Label(master, text="")
        self.response_label.grid(row=5, column=0, columnspan=8)

        # UDP socket
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind(("", 0))  # Bind to any available port
        self.sock.settimeout(1)  # Non-blocking mode

        # Start a thread to listen for responses
        self.thread = threading.Thread(target=self.receive_data)
        self.thread.daemon = True
        self.thread.start()

    def send_data(self):
        try:
            # 从文本框中读取数据，只包括非空的部分
            message = bytearray([int(entry.get()) for entry in self.data_entries if entry.get().strip()])

            if not message:
                # 如果没有有效的输入，显示错误消息
                self.response_label.config(text="Please enter at least one byte of data.")
                return

            server_ip = self.ip_entry.get()
            server_port = int(self.port_entry.get())

            # 发送数据到服务器
            self.sock.sendto(message, (server_ip, server_port))
            self.response_label.config(text="Data sent successfully.")
        except ValueError:
            # 显示错误信息，当输入非整数值时
            self.response_label.config(text="Invalid input: all entries must be integers.")
        except Exception as e:
            # 显示其他潜在的错误信息
            self.response_label.config(text=f"An error occurred: {e}")

    def receive_data(self):
        while True:
            try:
                data, addr = self.sock.recvfrom(1024)
                self.response_label.config(text=f"Received from {addr}: {data}")
            except socket.timeout:
                continue

root = tk.Tk()
client = UDPClient(root)
root.mainloop()
