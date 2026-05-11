#include <unistd.h>
#include <fcntl.h>

int main() {
    // 1. Open (or create) the file "list.txt" for writing
    // O_WRONLY is used for writing; O_CREAT is typically used to create it if it doesn't exist
    int fd = open("list.txt", O_WRONLY | O_CREAT, 0644);

    // 2. Redirect Standard Output (1) to the file descriptor (fd)
    // This makes anything that would normally print to the screen go to the file instead
    dup2(fd, 1);

    // 3. Execute the 'ls' program
    // The exec function replaces the current process with 'ls'
    execlp("ls", "ls", NULL);

    return 0;
}