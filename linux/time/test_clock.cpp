#include <stdio.h>
#include <time.h>

int main()
{
    struct timespec ts;
    
    if(clock_getres(CLOCK_REALTIME, &ts) == -1){
        printf("clock_getres error \n");
        return 1;
    }

    printf("resolution of the system clock: %ld\n", ts.tv_sec*1000000000 + ts.tv_nsec);
    return 0;
}
