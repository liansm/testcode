#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

void handle_child()
{
    printf("enter child process \n");

    while(1){
        printf("looping child process \n");
        sleep(5);
    }
}


void handle_main()
{
    printf("in main process\n");

    while(1){
        printf("looping main process \n");
        sleep(9);
    }
}



int main()
{

    pid_t pid1;
    printf("start main process \n");

    pid1 = fork();

    if(pid1 == 0){
       handle_child();
    }
    else if(pid1 > 0){
        handle_main(pid1);
    }
    else if(pid1 == -1){
        printf("error to create the child process");
    }
    else {
        printf("unknown error, pid=%d error=%d", pid1, errno);
    }

    return 0;

}
