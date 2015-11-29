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
	char buffer[32];
	int pipe_id;

	pipe_id = open(FIFO_NAME, O_RDONLY);
	if(pipe_id != -1){
		read(pipe_id, buffer, 32);
		printf("%s", buffer);
	}
	else{
		printf("error in reading\n");
	}
}
