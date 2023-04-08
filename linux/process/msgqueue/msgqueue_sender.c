#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>


#define MSG_FILE "./msgfile"

#define BUFFER 255
#define PERM S_IRUSR|S_IWUSR

struct msgbuf
{
	long mtype;
	char mtext[BUFFER+1];
};


char * message[3] = {"I'm sender, there are some messages for you", "Message1", "Message2"};

int main()
{
	struct msgbuf msg;
	key_t key;
	int msgid;
	
	if((key = ftok(MSG_FILE, 66)) == -1){
		printf("error in creating key\n");
		exit(-1);
	}

	if((msgid = msgget(key, PERM|IPC_CREAT)) == -1){
		printf("error in creating get message\n");
		exit(-1);
	}

	msg.mtype = 1;
	int i;

	for(i = 0; i < 3; i++){
		strncpy(msg.mtext, message[i], BUFFER);
		msgsnd(msgid, &msg, sizeof(struct msgbuf), 0);
	}

	printf("wating for receive\n");
	memset(&msg, '\0', sizeof(struct msgbuf));
	msgrcv(msgid, &msg, sizeof(struct msgbuf), 2, 0);
	printf("%s\n", msg.mtext);

	if(msgctl(msgid, IPC_RMID, 0) == -1){
		printf("error in deleting msg queue\n");
		exit(-1);
	}
	return 0;
}
