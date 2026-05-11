#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

//Task is to create a TCP/IP socket where client sends a word to server, 
//Server reverses the word and sends it back to client.


    
int main() {
    //1. Make the sockets
    int server_sock;
    int client_sock;

    server_sock = socket (AF_INET, SOCK_STREAM, 0);

    //2. Making the address structures
    struct sockaddr_in server_address; // (struct sockaddr *) &server_address
    struct sockaddr_in client_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(1000); //Port number htons convert number tk usable port - we're using port 1000 here
    server_address.sin_addr.s_addr = INADDR_ANY; // (CRAM)

    //3. Binding the socket - bind the socket to that address

    bind(server_sock, (struct sockaddr *)&server_address, sizeof(server_address));

  
    //4. Listen
    listen(server_sock, 5);
    printf("Server's listening on port 1000, hurry up\n");

    //5. Accept (Always accept)
    socklen_t client_addr_len = sizeof(client_address);

    while (1){
        client_sock = accept(server_sock, (struct sockaddr *) &client_address, &client_addr_len);

        if (client_sock > 0) {
            printf("Welcome to Heaven\n");
        }
        else {
            perror("Accept failed");
            return 1;
        }
    }
    return 0;
}
