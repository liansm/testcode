#include <stdio.h>  
#include <stdlib.h>  
#include <signal.h>  
#include <unistd.h>  
  
void handler(int signum) {  
    printf("Received SIGALRM signal!\n");  
}  

void handler2(int signum){
    printf("Received SIGTSTP signal!\n");
}

void handler3(int signum){
    printf("Received SIGSTOP signal!\n");
}

void handler4(int signum){
    printf("Received SIGINT signal!\n");
}
  
int main() {  
    signal(SIGALRM, handler); 
    signal(SIGTSTP, handler2);
    signal(SIGSTOP, handler3); 
    signal(SIGINT, handler4); 
  
    printf("Sending SIGALRM signal...\n");  
    alarm(5); // 在 5 秒后发送 SIGALRM 信号  
  
    while(1) {
        sleep(1);
    } // 无限循环，等待信号处理函数的调用  
  
    return 0;  
}
