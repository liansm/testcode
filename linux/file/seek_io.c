#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
	size_t len;
	off_t offset;
	int fd, ap, j;
	char * buf;
	ssize_t numRead, numWritten;

	fd = open(argv[1], O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	if(fd == -1){
		printf("fail to open the file \n");
		exit(-1);
	}

	for(ap = 2; ap < argc; ap++){
		switch(argv[ap][0]){
			case 'r':
			case 'R':
				len = strtol(&argv[ap][1], &argv[ap], 10);
				buf = malloc(len);
				if(buf == NULL){
					printf("fail to malloc the memory\n");
					exit(-2);
				}
	
				numRead = read(fd, buf, len);

				if(numRead == -1){
					printf("error to read the buf \n");
					exit(-3);
				}

				if (numRead == 0) {
					printf("end of the file \n");
				}
				else {
					printf("%s: ", argv[ap]);
					for(j = 0; j < numRead; j++){
						if (argv[ap][0] == 'r'){
							printf("%c", isprint((unsigned char) buf[j]) ? buf[j] : '?');
						}
						else {
							printf("%02x", (unsigned int) buf[j]);

						}
					}
					printf("\n");

				}
				free(buf);
				break;


			case 'w':
				numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
				if(numWritten == -1){
					printf("error to write the buf \n");
					exit(-4);
				}

				printf("%s: wrote %ld bytes \n", argv[ap], (long)numWritten);
				break;


			case 's':
				offset = strtol(&argv[ap][1], &argv[ap], 10);
				if (lseek(fd, offset, SEEK_SET) == -1){
					printf("fail to seek the file \n");
					exit(-4);
				}

				printf("%s: seek succeeded\n", argv[ap]);
				break;

			default:
				printf("wrong argument \n");
		}
	}
}

