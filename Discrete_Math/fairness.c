#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t resource;       // Semaphore to control access to the shared resource
sem_t queue;          // Semaphore to ensure fair queue access
int reader_count = 0; // Number of active readers
pthread_mutex_t r_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex to protect reader_count

void *reader(void *arg) {
    int reader_id = *((int *)arg);
    while (1) {
        sem_wait(&queue);          // Request to enter the queue
        pthread_mutex_lock(&r_mutex);
        reader_count++;
        if (reader_count == 1) {
            sem_wait(&resource);   // First reader locks the resource
        }
        pthread_mutex_unlock(&r_mutex);
        sem_post(&queue);          // Release queue to let others in line

        // Reading section
        printf("Reader %d is reading\n", reader_id);
        usleep(100000);  // Simulate reading time

        pthread_mutex_lock(&r_mutex);
        reader_count--;
        if (reader_count == 0) {
            sem_post(&resource);   // Last reader releases the resource
        }
        pthread_mutex_unlock(&r_mutex);

        sleep(100);  // Delay before next read attempt
    }
    return NULL;
}

void *writer(void *arg) {
    int writer_id = *((int *)arg);
    while (1) {
        sem_wait(&queue);          // Request to enter the queue
        sem_wait(&resource);       // Lock the resource
        sem_post(&queue);          // Release queue to let others in line

        // Writing section
        printf("Writer %d is writing\n", writer_id);
        usleep(150000);  // Simulate writing time

        sem_post(&resource);       // Release the resource
        sleep(100);  // Delay before next write attempt
    }
    return NULL;
}

int main() {
    pthread_t readers[5], writers[3];
    int reader_ids[5] = {1, 2, 3, 4, 5};
    int writer_ids[3] = {1, 2, 3};

    // Initialize semaphores
    sem_init(&resource, 0, 1);
    sem_init(&queue, 0, 1);

    // Create reader threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Join threads (they run indefinitely in this example)
    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&resource);
    sem_destroy(&queue);

    return 0;
}
