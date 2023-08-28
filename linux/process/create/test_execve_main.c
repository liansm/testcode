/* execve.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int
main(int argc, char *argv[])
{
   char *newargv[] = { NULL, "hello", "world", NULL };
   char *newenviron[] = { NULL };
   pid_t pid1;

   if (argc != 2) {
       fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
       exit(EXIT_FAILURE);
   }

   newargv[0] = argv[1];
   pid1 = fork();

   if(pid1 == 0){
    execve(argv[1], newargv, newenviron);
     perror("execve");   /* execve() returns only on error */
   }
   else if(pid1 > 0){
    sleep(60);
   }
   else if(pid1 == -1){
    printf("error to fork the process \n");
   }
   else {
    printf("unknow error\n");
   }
    
   exit(EXIT_FAILURE);
}

