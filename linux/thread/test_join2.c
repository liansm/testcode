//
//pthread_join will block the execution when waiting the thread1
//


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * thread1_func(void *arg)
{
    printf("start run thread1 \n");
    sleep(5);
    printf("end run thread1 \n");
    return NULL;
}

void * thread2_func(void *arg)
{
    printf("start run thread2 \n");
    sleep(1);
    printf("end run thread2 \n");
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int s1, s2;    

    s1 = pthread_create(&t1, NULL, thread1_func, NULL);
    if(s1 != 0){
        printf("error to create the thread 1 \n");
    }
 
    s2 = pthread_create(&t2,  NULL, thread2_func, NULL);
    if(s2 != 0){
        printf("error to create the thread2 \n");
    }


    if(pthread_join(t1, NULL) != 0){
        printf("error to join the thread1 \n");
    }
    printf("success to join the thread1 \n");

    if(pthread_join(t2, NULL) != 0){
        printf("error to join the thread2 \n");
    }
    printf("success to join the thread2 \n");
    return 0;
}
