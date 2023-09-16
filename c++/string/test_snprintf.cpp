#include <stdio.h>

int main()
{
    char buf1[100];
    char buf2[100];
    char buf3[100];

    snprintf(buf1, sizeof(buf1), "hello, world");
    snprintf(buf2, sizeof(buf2), "%s",  "hello, world");
    snprintf(buf3, sizeof(buf3), "%s%d",  "hello, world", 10);

    char buf4[8];
    snprintf(buf4, sizeof(buf4), "helloworldyes");

    char buf5[32];
    snprintf(buf5, sizeof(buf5), "%d", 3233333);

    return 0;
}
