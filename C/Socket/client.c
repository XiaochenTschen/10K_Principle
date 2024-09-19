#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // 创建socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    // 配置服务器地址
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 将IP地址转换为二进制并设置
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    // 连接服务器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }
    printf("Connected to server.\n");

    // 通信循环
    while (1) {
        printf("Enter message to send to server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // 移除换行符

        // 发送消息
        send(sock, buffer, strlen(buffer), 0);

        // 如果输入的是"exit"则退出
        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        // 接收服务器回复
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = read(sock, buffer, BUFFER_SIZE);
        if (bytes_received > 0) {
            printf("Server response: %s\n", buffer);
        }
    }

    // 关闭socket
    close(sock);

    return 0;
}
