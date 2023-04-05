#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/msg.h>


#define MSG_FILE "./msgfile"

#define BUFFER 255
#define PERM S_IRUSR|S_IWUSR

struct msgbuf
{
	long mtype;
	char mtext[BUFFER+1];
};

int main()
{
	struct msgbuf msg;
	key_t key;
	int msgid;
	int i;

	char * mytask = "I 'm a receiver, 3 messages received from you.";

	if((key = ftok(MSG_FILE, 66)) == -1){
		printf("Create Key Error: %s\n", strerror(errno));
		exit(-1);
	}

	if((msgid = msgget(key, PERM|IPC_CREAT)) == -1){
		printf("Create Message Queue Error: %s\n", strerror(errno));
		exit(-1);
	}

	int k_msgid = msgid;
	for(i = 0; i < 3; ++i){
		printf("before msgid=%d\n", msgid);
		msgrcv(msgid, &msg, sizeof(struct msgbuf), 1, 0);
		printf("Receiver receive: %s\n", msg.mtext);
//		printf("after msgid=%d\n", msgid);
	}

	msg.mtype = 2;
	strncpy(msg.mtext, mytask, BUFFER);
	msgsnd(msgid, &msg, sizeof(struct msgbuf), 0);
	return 0;
}
