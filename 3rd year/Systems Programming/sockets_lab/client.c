#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>


int main() {
    int sock;
    struct sockaddr_un server;
    char c, buf[100];

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, "/tmp/stock_socket");

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    while (printf("> "), (c = getchar()) != 'q') {
        while (getchar() != '\n');
        if (c == '+'c == '-' c== '=') {
            write(sock, &c, 1);
            int n = read(sock, buf, sizeof(buf));
            write(1, buf, n);
        }
    }
    close(sock);
}