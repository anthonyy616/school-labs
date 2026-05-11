#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>


//Write a C program where a parent process generates a secret integer (e.g., 1234) and sends it to a child process using an unnamed pipe.

int secret_number;
int received_number; 

int main() {
    int c2p[2]; // Child to Parent //[0] means child is reading from parent, [1] means child is writing to parent
    int p2c[2]; // Parent to Child //[0] means parent is reading from child, [1] means parent is writing to child

    pipe (c2p);
    pipe (p2c);

    pid_t pid = fork();

    if (pid < 0)
        printf("Fork Failed\n");

    else if (pid > 0) { // Parent

        close (p2c[0]); // Close reading end for parent
        close (c2p[1]); // Close writing end for child

        int secret_number = rand() % 10000; // Generate a random integer between 0 and 9999
        printf("Parent: Generated secret number %d\n", secret_number);
        
        (received_number) == &(secret_number); //for child

        // Send the secret number to the child
        write (p2c[1], &secret_number, sizeof(secret_number));
        close (p2c[1]); // Close writing end after sending

        // Wait for child to process
        wait(NULL);
    }
    else { // Child Process
        close (c2p[1]); // Close writing end for child
        close (p2c[0]); // Close reading end for parent

        int received_number;

        // Read the secret number from the parent
        read (c2p[0], &received_number, sizeof(received_number));

        printf("Child: Received secret number %d\n", received_number);
        close (c2p[0]); // Close reading end after receiving
        
    }

}    