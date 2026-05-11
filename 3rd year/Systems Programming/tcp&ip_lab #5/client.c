#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 7000
#define SERVER_IP "127.0.0.1"

int main() {
    int sock;
    struct sockaddr_in server;
    char message[100], server_reply[100];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed");
        return 1;
    }

    printf("Connected to server. Type expressions like: 5 + 3\n");

    while (1) {
        printf("> ");
        fgets(message, 100, stdin);

        if (send(sock, message, strlen(message), 0) < 0) {
            puts("Send failed");
            break;
        }

        int read_size = recv(sock, server_reply, 100, 0);
        if (read_size > 0) {
            server_reply[read_size] = '\0';
            printf("Result: %s", server_reply);
        }
    }

    close(sock);
    return 0;
}