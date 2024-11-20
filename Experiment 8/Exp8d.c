// Write a C program that catches a signal (such as SIGUSR1 or SIGUSR2) and executes a function when the signal is received. 
// The function should perform a specific task, such as displaying the current file position or seeking to a specified position 
// in a file (using lseek).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

#define FILE_NAME "example.txt"
int fd;

void handle_sigusr1(int sig){
    off_t offset = 10;
    if(lseek(fd,offset,SEEK_SET)==-1){
        printf("lseek failed\n");
        exit(1);
    }

    printf("Caught SIGUSR1 : File Pointer moved to position : %d\n", offset);
    write(fd,"Hello from SIGUSR1\n", strlen("Hello from SIGUSR1\n"));
}

void handle_sigusr2(int sig){
    off_t offset = 30;
    if(lseek(fd,offset,SEEK_SET)==-1){
        printf("lseek failed\n");
        exit(1);
    }

    printf("Caught SIGUSR2 : File Pointer moved to position : %d\n", offset);
    write(fd,"Hello from SIGUSR2\n", strlen("Hello from SIGUSR2\n"));
}

int main(){
    fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if(fd == -1){
        printf("Error opening file\n");
        exit(1);
    }
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);
    printf("Program is running. Send SIGUSR1 or SIGUSR2 to trigger the corresponding signal handler.\n");
    while(1){
        pause();    }

    close(fd);
    return 0;
}
