#include <pthread.h>  // Required for POSIX threads [1]
#include <stdio.h>

// 1. Shared resource and Synchronization tools
int total_balance = 0;          // Shared variables are accessible to all threads [1]
pthread_t workers[2];           // Array to hold thread identifiers [3]
pthread_mutex_t lock;           // Mutex variable to prevent race conditions [2]


void *add_money(void *arg) {

    printf("Thread starting to update balance...\n");
    total_balance += 100;
    printf("Thread updated balance. Current balance: %d\n", total_balance);
    
    return NULL; // Return value can be queried later if needed [3, 5]
}

int main() {
    // 3. Initialize the mutex before creating threads [2]
    pthread_mutex_init(&lock, NULL);

    // 4. Create 4 worker threads [3]
    for(int i = 0; i < 4; i++) {
        // pthread_create(thread_id, attributes, function, parameter)
        pthread_create(&workers[i], NULL, &add_money, NULL); 
    }

    // 5. Join threads: Wait for all workers to finish [5]
    // If the main process ends, all threads stop immediately [1]
    for(int i = 0; i < 4; i++) {
        pthread_join(workers[i], NULL); 
    }

    printf("Final total balance: %d\n", total_balance);

    return 0;
}