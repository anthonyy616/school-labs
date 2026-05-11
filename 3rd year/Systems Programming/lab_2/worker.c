#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *worker_id = getenv("WORKER_ID");

    if (worker_id != NULL) {
        printf("[Worker %s] Running... (PID: %d)\n", worker_id, getpid());
    } else {
        printf("[Worker] Running... (PID: %d) [WORKER_ID not set]\n", getpid());
    }

    // Simulate work
    sleep(3);

    printf("[Worker %s] Work complete. Exiting.\n", worker_id ? worker_id : "UNKNOWN");

    return 0;
}