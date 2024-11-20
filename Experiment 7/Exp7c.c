// Write a C program which will open file in read-write mode and create a process using fork.
// Demonstrate how file sharing technique is used in parent and child process.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fd  = open("example.txt", O_RDWR | O_CREAT, 0666);
    if(fd == -1){
        printf("File Opening Error!");
        exit(0);
    }

    int pid = fork();
    if(pid == 0){
        write(fd, "Child Process\n",14);
    }else if(pid > 0){
        write(fd, "Parent Process\n", 15);
        sleep(1);
        close(fd);
    }else{
        printf("Fork Failed!");
        exit(0);
    }
}