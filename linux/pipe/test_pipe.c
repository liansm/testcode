#include <stdio.h>  
#include <unistd.h>  
  
int main() {  
    int pipefd[2];  
    pid_t pid;  
    char buf[1024];  
  
    if (pipe(pipefd) == -1) {  
        perror("pipe");  
        return 1;  
    }  
  
    pid = fork();  
    if (pid == -1) {  
        perror("fork");  
        return 1;  
    }  
  
    if (pid == 0) {  
        // 子进程（写入端）  
        close(pipefd[0]); // 关闭读取端  
        write(pipefd[1], "Hello from child process!", sizeof("Hello from child process!") - 1);  
        close(pipefd[1]); // 关闭写入端  
        _exit(0);  
    } else {  
        // 父进程（读取端）  
        close(pipefd[1]); // 关闭写入端  
        int num = read(pipefd[0], buf, sizeof(buf));  
        buf[num] = '\0';
        printf("Received message from child process: %s\n", buf);  
        close(pipefd[0]); // 关闭读取端  
    }  
  
    return 0;  
}
