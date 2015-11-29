#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define FIFO_NAME "./myfifo"

int main()
{
	int res;
	int pipe_id;
	char buffer[] = "Hello world";

	if(access(FIFO_NAME, F_OK) == -1){
		res = mkfifo(FIFO_NAME, 0644);

		if(res != 0){
			printf("Error in creating fifo. \n");
			exit(-1);
		}
	}

	pipe_id = open(FIFO_NAME, O_WRONLY);
	if(fcntl(pipe_id, F_SETFL, fcntl(pipe_id, F_GETFD, 0) | O_NONBLOCK) == -1) 
	{
		printf("error to change the pipe to non blocking \n");
		exit(-1);
	}

	if(pipe_id != -1){
		if(write(pipe_id, buffer, PIPE_BUF) > 0){
			printf("close the pipe\n");
			close(pipe_id);
		}
		else{
			printf("Error in writing . \n");
			exit(1);
		}
	}
	else{
		printf("Error in opening. error=%d\n", errno);
		exit(1);
	}

}

