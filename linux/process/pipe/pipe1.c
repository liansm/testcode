#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 16 

int main()
{
	int n;
	int fd[2];
	pid_t pid;
	char buf[BUFFER_SIZE];

	if(pipe(fd) == -1){
		printf("error in create the pipe\n");
		exit(-1);
	}

	if((pid = fork()) < 0){
		printf("error in fork a sub process\n");
		exit(-2);
	}

	if(pid > 0){
		close(fd[0]);
		write(fd[1], "Hello Pig", 10);
	}
	else{
		close(fd[1]);
		read(fd[0], buf, 9);
		buf[9] = '\0';
		printf("%s, son\n", buf);
	}
	return;

}
