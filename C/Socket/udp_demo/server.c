#include <stdio.h>
#include <string.h>
#include <arpa/inet.h> /* usage */
#include <unistd.h>
#include <fcntl.h> /* file control */
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int socketfd;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);
    int flags;

    int connected = 0;
    uint8_t client_ip[4];
    int client_port = 0;

    int message_counter = 0;

    /* create udp socket */
    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(socketfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    /* server addr initialization */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    /* bind the socket to the given port */
    if(bind(socketfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind Failed");
        close(socketfd);
        return 1;
    }

    /* set socket to non-block mode */
    flags = fcntl(socketfd, F_GETFL, 0);
    fcntl(socketfd, F_SETFL, flags | O_NONBLOCK);

    printf("UDP server is running on port %d...\n", PORT);

    while(1) {
        ssize_t byte_received = recvfrom(socketfd, buf, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);
        if(byte_received < 0) {
            if(errno == EAGAIN || errno == EWOULDBLOCK) {
                printf("No data available now, would continue...\n");
            }
            else {
                perror("Receive Failed");
                break;
            }
        }
        else if(byte_received == 0) {
            printf("Connection closed by peer\n");
            break;
        }
        else {
             if(connected == 0) {
                connected = 1;
                memcpy(client_ip, &client_addr.sin_addr.s_addr, 4);
                client_port = ntohs(client_addr.sin_port);
            }

            buf[byte_received] = '\0';
            printf("Received message from client %u.%u.%u.%u port %d: %s\n", 
                    client_ip[0], client_ip[1], client_ip[2], client_ip[3], client_port, buf);

            message_counter++;
            char response[BUFFER_SIZE];
            snprintf(response, sizeof(response), "Server received msg%d", message_counter);

            sleep(1);
            ssize_t byte_send = sendto(socketfd, response, strlen(response), 0, (struct sockaddr*)&client_addr, addr_len);
            if(byte_send < 0) {
                perror("Send response failed");
            }
        }

        sleep(1);
    }

    close(socketfd);
    return 0;    
}