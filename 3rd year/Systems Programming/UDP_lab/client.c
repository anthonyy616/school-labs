#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <COMMAND:TEXT>\n", argv[0]);
        fprintf(stderr, "Example: %s 127.0.0.1 9000 UPPER:hello\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *message = argv[3];

    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in servaddr;

    // 1. Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // 2. to fill server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    // 3. send requested command to server
    sendto(sockfd, message, strlen(message), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Request sent: %s\n", message);

    // 4. Receive updated text from server
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
    if (n < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}
