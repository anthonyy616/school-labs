#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

// Signal handler for SIGINT (Ctrl+C)
void sigint_handler(int sig) {
    printf("\n[Manager] SIGINT received. Shutting down...\n");
    exit(0);
}

// Signal handler for SIGCHLD (child terminated)
void sigchld_handler(int sig) {
    int status;
    pid_t child_pid = waitpid(-1, &status, WNOHANG);
    if (child_pid > 0) {
        printf("[Manager] Worker (PID: %d) has terminated.\n", child_pid);
    }
}

int main() {
    // Set up signal handlers
    signal(SIGINT, sigint_handler);
    signal(SIGCHLD, sigchld_handler);

    pid_t pid = fork();

    if (pid < 0) {
        perror("[Manager] fork failed");
        exit(1);
    }

    if (pid == 0) {
        // --- CHILD PROCESS (worker) ---
        // Set environment variable WORKER_ID = "A2"
        setenv("WORKER_ID", "A2", 1);

        // Execute worker program
        execl("./worker", "worker", NULL);

        // If execl fails
        perror("[Manager] execl failed");
        exit(1);
    } else {
        // --- PARENT PROCESS (manager) ---
        printf("[Manager] Launched worker with PID: %d\n", pid);
        printf("[Manager] Waiting for child to finish...\n");

        // Wait for child to terminate
        int status;
        waitpid(pid, &status, 0);

        // After child ends, get its PID and WORKER_ID
        char *worker_id = getenv("WORKER_ID");
        if (worker_id != NULL) {
            printf("[Manager] Worker PID: %d | WORKER_ID: %s\n", pid, worker_id);
        } else {
            printf("[Manager] WORKER_ID not found in environment.\n");
        }

        printf("[Manager] Child has been reaped. Manager exiting.\n");
    }

    return 0;
}