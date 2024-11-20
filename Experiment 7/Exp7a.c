// Write a  c program to create child process using fork() and display it with different id's as well as
// return value of fork in child and parent process.

#include <stdio.h>
#include <unistd.h>
int main (){
    int forket;
    forket = fork();
    if(forket == 0){
        printf("I am child process\n");
        printf("Return value of forket in child : %d\n", forket);
        printf("Process id of child : %d\n", getpid());
        printf("Parent process id : %d\n", getppid());
        printf("User Id : %d\n", getuid());
    }else if(forket > 0){
        printf("I am parent process\n");
        printf("Return value of forket in parent : %d\n", forket);
        printf("Process id of parent : %d\n", getpid());
        printf("Parent process id of parent : %d\n", getppid());
        printf("User Id : %d\n", getuid());
    }else{
        printf("Fork Failed\n");
    }
}