import socket
import struct

udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 8080)

data1 = 255
data2 = 65500

packed_data = struct.pack('II', data1, data2)

udp_socket.sendto(packed_data, server_address)

udp_socket.close()