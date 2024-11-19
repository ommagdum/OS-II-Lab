// Write a C program which opens a file in read mode and checks for file operating errors. 
// If opened successfully, it prints the contents of the file until the end of file is reached. 
// Also write any message to the file and check for errors and display appropriate messages.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd, rv; 
    char rdata;
    fd = open("demo.txt", O_RDONLY);

    if(fd < 0){
        printf("File Opening Error");
        exit(0);
    }

    printf("\nFile Opened Successfully\nFile Descriptor value: %d\n", fd);
    
    printf("File Contents : \n");
    while(read(fd, &rdata, 1) > 0){
        printf("%c", rdata);
    }

    rv = write(fd, "Welcome", 7);
    if(rv < 0){
        printf("\nFile Writing Error");
        exit(0);
    }
    printf("\nFile Written Successfully\n");
    close(fd);
}