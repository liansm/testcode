#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define PATH "./sm"
#define SIZE 512
#define ID 0

int main()
{
	char * shmAddr;
	char * dataAddr = "Hello";
	key_t key = ftok("/home/liansm/project/testcode/process/sm3", 'R');
	
	int shmID = shmget(key, SIZE, 0644|IPC_CREAT);
	shmAddr = shmat(shmID, (void*)0, 0);
	if(shmAddr == (char*)(-1)){
		printf("shmat error\n");
		exit(-1);
	}

	strcpy(shmAddr, dataAddr);
	shmdt(shmAddr);
	exit(0);
}
