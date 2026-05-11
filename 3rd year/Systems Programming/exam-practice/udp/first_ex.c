#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main() {
    //1. Create socket

    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    //2. Create address
    struct sockaddr_in address_rec

    address_rec.sin_family = AF_INET;
    address_rec.sin_port = htons(1000);
    address_rec.sin_addr.s_addr = INADDR_ANY;
    
    //3. Bind
}