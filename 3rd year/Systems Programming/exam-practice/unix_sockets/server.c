#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>

//Task is to create a UNIX domain socket where client sends a word to server, Server reverses the word and sends it back to client.

int main()
    //1. Making the socket
    int server_sock = socket(AF_UNIX, SOCK_STREAM, 0);

    //2. Making the address structures
    struct sockaddr_un local; 

    local.sun_family = AF_UNIX;
    strcpy(local.sun_path, "unix_socket");

    //2. Binding the socket
    bind(server_sock, (struct sockaddr *)&local, sizeof(local)); 
    
    //3. Listening for connections
    listen(server_sock, 5); // assume 5 is the queue size

    while (1) {
        //To ALWAYS accept connections use infinite while loop
        accept_connection;
        int client_sock = accept(server_sock, NULL, NULL);
    }



