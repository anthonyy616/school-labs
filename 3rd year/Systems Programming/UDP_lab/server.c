#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
    fprintf(stderr, "We are using: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int sock;
    char buffer[BUFFER_SIZE];

    struct sockaddr_in servaddr, cliaddr;

    // 1. Create a UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // 2. Fill server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY; // Any network interface
    servaddr.sin_port = htons(port); // Convert port to network byte order

    // 3. Bind the socket to the port
    if (bind(sock, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", port);

    while (1) {
        socklen_t len = sizeof(cliaddr);
        
        // 4. receive data from client
        int n = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &len);
        if (n < 0) continue;
        
        buffer[n] = '\0';
        printf("Received request: %s\n", buffer);

        // 5. To parse COMMAND:TEXT
        char *separator = strchr(buffer, ':');
        if (separator == NULL) {
            char *error_msg = "Error: Invalid format. Use COMMAND:TEXT";
            sendto(sock, error_msg, strlen(error_msg), 0, (struct sockaddr *)&cliaddr, len);
            continue;
        }

        *separator = '\0'; // Split the string into command and text
        char *command = buffer;
        char *text = separator + 1;

        // 6. performing string manipulation
        if (strcmp(command, "UPPER") == 0) {
            for (int i = 0; text[i]; i++) text[i] = toupper(text[i]);
        } else if (strcmp(command, "LOWERC") == 0) {
            for (int i = 0; text[i]; i++) text[i] = tolower(text[i]);
        } else if (strcmp(command, "REV") == 0) {
            reverse_string(text);
        } else {
            text = "Error: Unknown command";
        }

        // 7. Send result back to client
        sendto(sock, text, strlen(text), 0, (struct sockaddr *)&cliaddr, len);
        printf("Sent response: %s\n", text);
    }

    close(sock);
    return 0;
}
