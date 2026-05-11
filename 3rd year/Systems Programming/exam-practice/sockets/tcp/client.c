#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

//Task is to create a TCP/IP socket where client sends a word to server, Server reverses the word and sends it back to client.

int main() {
    //1.
    int client_sock;

    client_sock = socket(AF_INET, SOCK_STREAM, 0);

    //2. 
    struct sockaddr_in client_address;
    struct sockaddr_in server_address;


    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(1000); //Port number htons convert number tk usable port - we're using port 1000 here
    client_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // (CRAM)
    
    //3.

    connect(client_sock, (struct sockaddr *)&client_address, sizeof(client_address));

    //4

    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);

    write(client_sock, word, strlen(word));
    read(client_sock, word, strlen(word));
    














    socklen_t server_addr_len = sizeof(client_address);







}
