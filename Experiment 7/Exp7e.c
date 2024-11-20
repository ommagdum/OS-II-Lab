// Write a C program which will create a child process & execute different exec or execl command.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int pid = fork();
    if(pid ==0){
        printf("Child process will execute 'ls' command\n");
        execl("/bin/ls","ls",NULL);
        perror("execl failed");
    }else if(pid > 0){
        printf("Parent Process\n");
    }else{
        printf("Fork Failed\n");
    }
}