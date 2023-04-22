#include <sys/time.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

void test_gettimeofday();
void test_ctime();
void test_asctime();
void test_clock(const char * msg);

int main()
{
    test_clock("start");
    test_ctime();
    test_asctime();
    test_gettimeofday();
    test_clock("end");
    return 0;
}

void test_gettimeofday()
{
    timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    sleep(5);
    gettimeofday(&tv2, NULL);

        
    printf("tv_sec=%d tv_usec=%d\n", tv2.tv_sec-tv1.tv_sec, tv2.tv_usec-tv1.tv_usec);
    return;
}


void test_ctime()
{
    time_t t1;
    time(&t1);

    const char* current_time = ctime(&t1);
    printf("current_time=%s\n", current_time);
    return;
}

void test_asctime()
{
    tm* t1;
    time_t t2;

    time(&t2);
    t1 = gmtime(&t2);

    char * current_time = asctime(t1);
    printf("current_time=%s\n", current_time);
    return;
}

void test_clock(const char * msg)
{
    if( msg != NULL){
        printf("%s\n", msg);
    }

    int clockTicks = sysconf(_SC_CLK_TCK);
    printf("CLOCKS_PER_SEC=%ld sysconf(_SC_CLK_TCK)=%ld\n\n", (long) CLOCKS_PER_SEC, clockTicks);

    struct tms t;
    clock_t clockTime = clock();
    times(&t);
    

    printf("clocks: %ld, clocks-per-sec (%.2f secs) \n", (long)clockTime, (double)clockTime/CLOCKS_PER_SEC);
    printf("times, utime=%ld, stime=%ld, user CPU=%.2f system CPU=%.2f\n", t.tms_utime, t.tms_stime, (double)(t.tms_utime/clockTicks), (double)(t.tms_stime/clockTicks));
    return;
}
