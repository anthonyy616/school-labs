#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#define PORT 7000
#define BUFFER_SIZE 1024

int calculate(char *expr) { //This is our calculator function
    int num1, num2;
    char operand;

    if (sscanf(expr, "%d %c %d", &num1, &operand, &num2) != 3) {
        return -1 ; // error code
    }
    

    if (operand == '+')
        return num1 + num2;
    else if (operand == '-')
        return num1 - num2;
    else if (operand == '*')
        return num1 * num2;
    else if (operand == '/')
        return num1 / num2;
    else
        return -1; // Invalid operator: error
}


void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received string
        printf("Received expression: %s\n", buffer);

        int result = calculate(buffer);
        if (result == -1) {
            const char *error_msg = "Invalid expression\n";
            send(client_socket, error_msg, strlen(error_msg), 0);
        } else {
            char result_str[BUFFER_SIZE];
            snprintf(result_str, sizeof(result_str), "Result: %d\n", result);
            send(client_socket, result_str, strlen(result_str), 0);
        }
    }

    if (bytes_received < 0) {
        perror("recv");
    }

    close(client_socket);
    printf("Client disconnected.\n");
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any address
    server_addr.sin_port = htons(PORT); // Convert port number to network byte order

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("accept");
            continue; // Continue to accept other clients
        }

        printf("New client connected.\n");

        // Handle the client in a separate function
    
        if (fork() == 0) { //Child process
        close(server_socket); //child doesn't need to close the server socket
        handle_client(client_socket);
        exit(0);
        }
        else {
        //The parent process
        close(client_socket);
        }
    }
    close(server_socket);
    return 0;
}