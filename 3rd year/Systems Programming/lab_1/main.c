#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//Function for string reversal using strlen
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    pid_t pid;
    char input[256];

    printf("Parent process started. PID: %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child process started. PID: %d\n", getpid());

        while (1) {
            printf("Child: Enter a string (or 0 to exit): ");
            fflush(stdout);

            // Read input from parent via stdin (we'll simulate with scanf)
            if (fgets(input, sizeof(input), stdin) == NULL) {
                break;
            }

            if (strcmp(input, "0") == 0) {
                printf("Child: Received 0. Exiting...\n");
                break;
            }

            reverse_string(input);
            printf("Child: Reversed string: %s\n", input);
        }

        exit(0); // Child exits
    }
    else {
        // Parent process
        printf("Parent: Child PID is %d\n", pid);

        while (1) {
            printf("Parent: Enter a string to send to child (or 0 to stop): ");
            fflush(stdout);

            if (fgets(input, sizeof(input), stdin) == NULL) {
                break;
            }

            // Remove newline
            input[strcspn(input, "\n")] = 0;

            // Send string to child by printing it (child reads from stdin)
            printf("%s\n", input);
            fflush(stdout);

            if (strcmp(input, "0") == 0) {
                printf("Parent: Sent 0. Waiting for child to terminate...\n");
                break;
            }
        }

        // Wait
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Parent: Child terminated normally with exit status %d\n", WEXITSTATUS(status));
        }

        printf("Parent: Resuming normal execution...\n");
        // Parent continues here after child exits
        printf("Parent: Hello from parent after child finished!\n");
    }

    return 0;
}