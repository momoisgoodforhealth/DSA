#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t sem;

void* worker(void* arg) {
    int id = *(int*)arg;

    sem_wait(&sem);   // acquire resource
    printf("Thread %d entering critical section\n", id);

    sleep(1);         // simulate work

    printf("Thread %d leaving\n", id);
    sem_post(&sem);   // release resource

    return NULL;
}

int main() {
    pthread_t threads[4];
    int ids[4] = {1, 2, 3, 4};

    sem_init(&sem, 0, 2);  // allow 2 threads at a time

    for (int i = 0; i < 4; i++)
        pthread_create(&threads[i], NULL, worker, &ids[i]);

    for (int i = 0; i < 4; i++)
        pthread_join(threads[i], NULL);

    sem_destroy(&sem);
    return 0;
}
