#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  
  
void *thread_function(void *arg) {  
    int * result = malloc(sizeof(int));
    *result = 42; // 这是线程的返回值  
    pthread_exit(result);
}  
  
int main() {  
    pthread_t thread;  
    void *ret;
  
    // 创建一个线程并传递一个指向结果的指针给它  
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {  
        perror("pthread_create");  
        exit(EXIT_FAILURE);  
    }  
  
    // 等待线程结束并获取它的返回值  
    if (pthread_join(thread, &ret) != 0) {  
        perror("pthread_join");  
        exit(EXIT_FAILURE);  
    }  
  
    printf("Thread returned: ret=%d\n", *(int*)ret); // 输出 "Thread returned: 42"  
  
    return 0;  
}
