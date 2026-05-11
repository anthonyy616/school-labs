#include <pthread.h>  // Required for POSIX threads [1]
#include <stdio.h>

// You are building a system that tracks the number of visitors to a website using 20 concurrent threads.
// 1. Create a global integer visitor_count and a pthread_mutex_t.
// 2. Each thread should run a function that increments the visitor_count 10,000 times in a loop.
// 3. Ensure that there are no race conditions by locking the mutex during the increment and unlocking it immediately after.
// 4. The main function must wait for all threads to finish using pthread_join before printing the final total.

int visitor_count = 0; 
pthread_t workers[25];

pthread_mutex_t lock;
pthread_mutex_t unlock;

void *visitors (void *arg) { 
    printf("Thread starting to update visitors");
    printf("The total number of visitors at the beginning: %d\n", visitor_count);
     for (int j = 0; j<10000; j++)
        pthread_mutex_lock(&lock);
        
        visitor_count = visitor_count + 1; //critical condition

        pthread_mutex_unlock(&unlock);
        

    return NULL;
    
}

int main(){
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i<20; i++)
        pthread_create(&workers[i], NULL, visitors, &visitor_count);

    for (int i = 0; i<20; i++)
        pthread_join(workers[i], NULL);

    printf("New value of visitors count is: %d\n", visitor_count);

    return 0;
}
