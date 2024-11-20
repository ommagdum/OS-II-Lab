// Write a C program to create process using vfork() and demonstrate effect of changes in variables in the child process on the parent process.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int globalVar = 5;
int main(){
    int localVar = 10;
    int pid = vfork();
    if(pid == 0 ){
        globalVar += 5;
        localVar += 5;
        printf("Child Process - Global Variable = %d, Local Variable  = %d\n", globalVar, localVar);
        exit(0);
    }else if(pid > 0){
        printf("Parent Process - Global Variable = %d, Local Variable = %d\n", globalVar, localVar);
    }else{
        printf("Vfork Failed!\n");
    }
}