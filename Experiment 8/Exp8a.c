// Write a C program which will create a unnamed pipe. Perform the commmunication between parent and child process using this unnamed pipe.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int pipefd[2];
    pid_t pid;
    char write_msg[] = "Hello from parent process";
    char read_msg[100];

    if(pipe(pipefd)==-1){
        perror("Pipe Failed");
        return 1;
    }

    pid = fork();
    if(pid<0){
        printf("Fork Faield");
        return 1;
    }

    if(pid>0){
        //Parent Process 
        close(pipefd[0]);
        write(pipefd[1],write_msg,strlen(write_msg)+1);
        close(pipefd[1]);
        wait(NULL);
    }else{
        close(pipefd[1]);
        read(pipefd[0],read_msg,sizeof(read_msg));
        printf("Child process received message : %s\n",read_msg);
        close(pipefd[1]);
    }
    return 0;
}