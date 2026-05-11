#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // 1. Create UDP socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0); [3]

    // 2. Setup target address (Peer A's address)
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(8080);
    target.sin_addr.s_addr = inet_addr("127.0.0.1"); [4]

    // 3. Send data directly to that address
    char *msg = "Hello via UDP!";
    sendto(sock, msg, 15, 0, (struct sockaddr*)&target, sizeof(target)); [2, 5]

    close(sock);
    return 0;
}
