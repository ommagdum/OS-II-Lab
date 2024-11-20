// Write a C program which will create a named pipe and write a message to it from one process and read the message from another process.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define PIPE_NAME "/tmp/my_named_pipe"
#define BUFFER_SIZE 100

void write_to_pipe() {
    int fd;
    char buffer[BUFFER_SIZE] = "Hello from the writing process";
    fd = open(PIPE_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Error opening the pipe for writing");
        exit(EXIT_FAILURE);
    }
    if (write(fd, buffer, strlen(buffer) + 1) == -1) {
        perror("Error writing to the pipe");
    }
    close(fd);
}

void read_from_pipe() {
    int fd;
    char buffer[BUFFER_SIZE];
    fd = open(PIPE_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening the pipe for reading");
        exit(EXIT_FAILURE);
    }
    if (read(fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error reading from the pipe");
    } else {
        printf("Reading process received message: %s\n", buffer);
    }
    close(fd);
}

int main(int argc, char *argv[]) {
    // Create the named pipe
    if (mkfifo(PIPE_NAME, 0666) == -1) {
        perror("Error creating the named pipe");
    }

    if (argc > 1 && strcmp(argv[1], "write") == 0) {
        write_to_pipe();
    } else if (argc > 1 && strcmp(argv[1], "read") == 0) {
        read_from_pipe();
    } else {
        fprintf(stderr, "Usage: %s [write|read]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return 0;
}