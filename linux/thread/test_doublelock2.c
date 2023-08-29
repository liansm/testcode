#include <stdio.h>
#include <pthread.h>
#include <errno.h>

int main()
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    int ret;

    printf("start \n");
    ret = pthread_mutex_lock(&mutex);
    printf("first lock done, ret=%d, errno=%d\n", ret, errno);

    ret = pthread_mutex_trylock(&mutex);
    printf("second lock done, ret=%d, errno=%d\n", ret, errno);
    return 0;
}
