#include <stdio.h>
#include <pthread.h>

int main()
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    printf("start \n");
    pthread_mutex_lock(&mutex);
    printf("first lock done\n");

    pthread_mutex_lock(&mutex);
    printf("second lock done\n");
    return 0;
}
