#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>


int main() {


    
}
    //1. Creating the sockets

    int sock = socket (AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un local;
    local.sun_family = AF_UNIX ;
    strcpy("socket.temp", local.sun_path);

    //2. To bind to the server address
    bind(sock,(struct sockaddr *)&local, sizeof(local)); //struct pointer is the address of server

    //3. To listen for connections
    while (1) //im using a while loop on the condition it's always true to always listen for connections (infinite loop)
        listen(sock, 5) // 5 represents queue size

    //4. To accept 
    while (1) {
            int conn = accept(sock, (sockaddr_un *)&remote, &socketsize) //Passing the length as socksize integer instead

            while (read(conn, &ch, 1) == 1) {
                if (ch == '+')      stack_count++;
                else if (ch == '-') stack_count--;

                if (ch == '+' ch == '-' ch == '=') {
                    char resp[20];
                    sprintf(resp, "%d\n", stack_count);
                    write(conn, resp, strlen(resp));
                }
            }
            close(conn);   // if clienthas gone → go back to accept next one forever 
        }
    


    //5. To perform send/receive to Client

    int stack_count;
        if(read(conn,(char *)&num, sizeof(int))) {
            perror("Read");
            return 1;
        }
        char resp = 0;
        if(send_plus(char))

    typedef struct{
        char items[10];
        int stack_count;
    } OurStack; //the actual stack 
        
    stack_count = 0;
    total = total + count;

    printf("Enter a character (either +, - or =)", items);
    scanf("%c", &items);

    if ("%c" == '+')
        stack_count++;
        return total;
        
    else if ("%c" == '-')
        stack_count--;
    else if ("%c" == '=')
        return total;
    else
        return 1;


    return 0;
}    


        

    
        