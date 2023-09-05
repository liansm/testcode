#include <stdio.h>
#include <unistd.h>
#include <signal.h>  

int global;
void swap(int * x, int * y)
{
    printf("start swapping, x=%d, y=%d \n", *x, *y);

    global = *x;
    printf("sleep 30 seconds \n");
    sleep(30);
    *x = *y;
    *y = global;
    printf("end swapping, x=%d, y=%d \n", *x, *y);
}


void handle_signal()
{
    int x = 1, y = 2;
    swap(&x, &y);
} 

int main()
{
    signal(SIGINT, handle_signal);
    int x = 5;
    int y = 10;
    swap(&x, &y);
    return 0;
}
