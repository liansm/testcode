#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>


#define PATH "./sm3"
#define SIZE 512
#define ID 0

int main()
{
	char * shmAddr;
	int key = ftok(PATH, 'R');
	int shmID = shmget(key, SIZE, 0);
	shmAddr = shmat(shmID, NULL, 0);

	printf("%s\n", shmAddr);
	shmdt(shmAddr);
	shmctl(shmID, IPC_RMID, NULL);
	exit(0);
}
