// Write a C program to demonstrate the fork() function, showing how changes in variables in the child process do not affect their values in the parent process. 
// Additionally, demonstrate the effect of buffered and unbuffered output in the parent and child processes.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int globalVar = 5;

int main() {
    int localVar = 10;
    pid_t pid = fork(); // Fork a child process

    if (pid == 0) {
        // Child process
        globalVar += 5;
        localVar += 5;

        // Unbuffered output using write()
        write(STDOUT_FILENO, "Child Process - Unbuffered Output\n", 34);
        printf("Child Process - Global Variable: %d, Local Variable: %d\n", globalVar, localVar);
        printf("Buffered Output in Child Process\n");

    } else if (pid > 0) {
        // Parent process
        sleep(1); // Ensure child runs first
        write(STDOUT_FILENO, "Parent Process - Unbuffered Output\n", 35);
        printf("Parent Process - Global Variable: %d, Local Variable: %d\n", globalVar, localVar);
        printf("Buffered Output in Parent Process\n");

    } else {
        // Fork failed
        perror("Fork failed");
        return 1;
    }

    return 0;
}