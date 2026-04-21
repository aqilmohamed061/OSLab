#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t fork[N];

void *philosopher(void *num)
{
    int id = *(int *)num;
    int left = id;
    int right = (id + 1) % N;

    while(1)
    {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        // Deadlock prevention
        if(id == N - 1)
        {
            sem_wait(&fork[right]);
            printf("Philosopher %d picked up right fork %d.\n", id, right);

            sem_wait(&fork[left]);
            printf("Philosopher %d picked up left fork %d.\n", id, left);
        }
        else
        {
            sem_wait(&fork[left]);
            printf("Philosopher %d picked up left fork %d.\n", id, left);

            sem_wait(&fork[right]);
            printf("Philosopher %d picked up right fork %d.\n", id, right);
        }

        printf("Philosopher %d is eating.\n", id);
        sleep(2);

        sem_post(&fork[left]);
        sem_post(&fork[right]);

        printf("Philosopher %d put down forks %d and %d.\n", id, left, right);
    }
}

int main()
{
    pthread_t ph[N];
    int id[N];

    for(int i = 0; i < N; i++)
        sem_init(&fork[i], 0, 1);

    for(int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &id[i]);
    }

    for(int i = 0; i < N; i++)
        pthread_join(ph[i], NULL);

    return 0;
}
