#include <pthread.h>

void * test(void *arg)
{
    

    pthread_join(pthread_self(), NULL);
    return NULL;

}

int main()
{
    pthread_t th1;

    pthread_create(&th1, NULL, test, NULL);
    return 0;
}
