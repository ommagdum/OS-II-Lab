// Write a C program which will create a pipe and two reading processes. The writing process will write a message to the pipe and the reading processes will read the message from the pipe.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define FIFO_NAME1 "/tmp/my_fifo1"
#define FIFO_NAME2 "/tmp/my_fifo2"
#define BUFFER_SIZE 100

void writer_process() {
    int fd1, fd2;
    char *message = "Hello from the writing process\n";

    fd1 = open(FIFO_NAME1, O_WRONLY);
    fd2 = open(FIFO_NAME2, O_WRONLY);

    if (fd1 == -1 || fd2 == -1) {
        perror("Failed to open pipe for writing");
        exit(EXIT_FAILURE);
    }

    write(fd1, message, strlen(message) + 1);
    write(fd2, message, strlen(message) + 1);
    printf("Writing Process Wrote: %s\n", message);
    close(fd1);
    close(fd2);
}

void reader_process(const char *pipe_name, int reader_id) {
    int fd;
    char buffer[BUFFER_SIZE];
    fd = open(pipe_name, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open pipe for reading");
        exit(EXIT_FAILURE);
    }

    read(fd, buffer, BUFFER_SIZE);
    printf("Reader %d received: %s\n", reader_id, buffer);
    close(fd);
}

int main() {
    pid_t pid1, pid2, pid3;

    // Create the named pipes (one for each reader)
    if (mkfifo(FIFO_NAME1, 0666) == -1) {
        perror("Failed to create FIFO 1");
        exit(EXIT_FAILURE);
    }
    if (mkfifo(FIFO_NAME2, 0666) == -1) {
        perror("Failed to create FIFO 2");
        exit(EXIT_FAILURE);
    }

    // Fork the writer process
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed for writer process");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) {
        writer_process();
        exit(EXIT_SUCCESS);
    }

    // Fork the first reader process
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed for reader process 1");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {
        reader_process(FIFO_NAME1, 1); // Reader 1 reads from FIFO_NAME1
        exit(EXIT_SUCCESS);
    }

    // Fork the second reader process
    pid3 = fork();
    if (pid3 < 0) {
        perror("Fork failed for reader process 2");
        exit(EXIT_FAILURE);
    }
    if (pid3 == 0) {
        reader_process(FIFO_NAME2, 2); // Reader 2 reads from FIFO_NAME2
        exit(EXIT_SUCCESS);
    }

    // Wait for all child processes to complete
    wait(NULL);
    wait(NULL);
    wait(NULL);

    // Remove the named pipes
    unlink(FIFO_NAME1);
    unlink(FIFO_NAME2);

    return 0;
}