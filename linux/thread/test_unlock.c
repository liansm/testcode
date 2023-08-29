#include <stdio.h>
#include <pthread.h>

int main()
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    printf("start \n");
    int ret = pthread_mutex_lock(&mutex);
    printf("first lock done, ret=%d\n", ret);

    ret = pthread_mutex_unlock(&mutex);
    printf("first unlock done, ret=%d\n", ret);

    ret = pthread_mutex_unlock(&mutex);
    printf("second unlock done, ret=%d\n", ret);
    return 0;
}
