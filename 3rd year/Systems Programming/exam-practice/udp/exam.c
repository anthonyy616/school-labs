#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>


int getdata(char*);

int main(){
    //1. Run myprogram
    int fds[2];
    pipe(fds);

    int fork();

    if (fork == 0)
        dup2(fds, 0) //reading end of the pipe
        close(fds[1]) //writing end of the pipe
        execlp("./myprogram", "myprogram", NULL)
        exit(0);

    //2. Send to the website
    struct addrinfo hints = {0} *res;
    hints.sin_family = AF_INET
    hints.sin_socktype = SOCK_DGRAM
    getaddrinfo("mydata.com", 1122, &hints &res);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    //3. Concurrent sending and receiving

    fork();
    
    if (fork == 0);
        char send_buf[1024];
        while(1)
            int size = getdata(send_buf);

    else {
        char recv_buf[1024];
        while(1)
            int receive = getdata(send_buf);
    }

}