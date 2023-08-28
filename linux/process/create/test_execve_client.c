/* myecho.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
   int j;

   for (j = 0; j < argc; j++)
       printf("argv[%d]: %s\n", j, argv[j]);

   sleep(60);
   exit(EXIT_SUCCESS);
}
