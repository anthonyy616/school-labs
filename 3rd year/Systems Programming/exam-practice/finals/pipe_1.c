#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

//Write a C program that executes the command sort using a child process. The parent process should create an unnamed pipe, 
//write a list of unsorted names (e.g., "Charlie", "Alpha", "Bravo") into the pipe, and then close the writing end. 
//The child process must use dup2 to redirect its standard input (stdin) to the reading end of the pipe before calling execlp to run the 
// sort program.

int fds[2];

char buffer[1024];

int main(){
    

    pid_t pid = fork();

    if (pid > 0) { //Parent process
        pipe(fds);

        close(fds[0]);

        buffer[] = {'Charlie', 'Alpha', 'Brown'};

        write(fds[1], buffer, sizeof(buffer));
        close(fds[1]);
    }

    else if (pid == 0) { //Child process
        close(fds[1]);

        int bytes_read = read(fds[0], buffer, sizeof(buffer)-1);

        buffer[bytes_read] = '\0';

        dup2(bytes_read, 0); //redirect to read end of pipe

        close(fds[0]);
        close(fds[1]);

        execlp("./sort","sort", NULL);
    }

    else
        perror("Fork failed\n");
        exit(0);

    return 0;
}