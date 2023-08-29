#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

int main()
{
    pthread_mutex_t mutex;
    pthread_mutexattr_t mtxAttr;

    int ret, type;
    ret = pthread_mutexattr_init(&mtxAttr);
    if(ret != 0){
        printf("error to init the mutex attr, ret=%d \n", ret);
        exit(-1);
    }

    ret = pthread_mutexattr_settype(&mtxAttr, PTHREAD_MUTEX_ERRORCHECK);
    if(ret != 0){
        printf("error to set the mutex type , ret=%d \n", ret);
        exit(-1);
    }
    
    ret = pthread_mutex_init(&mutex, &mtxAttr);
    if(ret != 0){
        printf("error to init the mutex , ret=%d \n", ret);
        exit(-1);
    }
    
    printf("start \n");
    ret = pthread_mutex_lock(&mutex);
    if(ret != 0){
        printf("error to lock the mutex , ret=%d \n", ret);
        exit(-1);
    }

    printf("first lock done, ret=%d, errno=%d\n", ret, errno);

    ret = pthread_mutex_lock(&mutex);
    if(ret != 0){
        printf("error to lock the mutex , ret=%d \n", ret);
        exit(-1);
    }
    printf("second lock done, ret=%d, errno=%d\n", ret, errno);
    return 0;
}
