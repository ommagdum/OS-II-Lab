// Write a C program to open file in read mode only and read the contents of the file and check for errors.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd, readVal;
    char buff[50];

    fd = open("abc.txt", O_RDONLY);
    if(fd < 0){
        printf("File Opening Error\n");
        exit(0);
    }else{
        printf("File Opened Successfully\n");
        printf("File Descriptor Value: %d\n", fd);
    }

    readVal = read(fd,buff,11);
    if(readVal < 0){
        printf("File Reading Error\n");
    }else{
        printf("File Reading Successful\n");
        printf("Number of Bytes Read: %d\n", readVal);
        buff[readVal] = '\0';
        printf("Read Character : %s", buff);
    }

    close(fd);
}