// Write a C program to open a file in read-write mode, read the contents of the file , write in file and check for reading and writing errors.
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd, readVal, writeVal;
    char buff[50];
    fd = open("abc.txt", O_RDWR);
    if(fd < 0){
        printf("File Opening Error\n");
        exit(0);
    }else{
        printf("File Opened Successfully\n");
        printf("File Descriptor Value: %d\n", fd);
    }

    readVal = read(fd, buff, 11);
    if(readVal < 0){
        printf("File Reading Error\n");
    }else{
        printf("File Reading Successful\n");
        printf("Number Of Bytes Read : %d\n", readVal);
        buff[readVal]='\0';
        printf("Read File Contents : %s\n", buff);
    }

    writeVal = write(fd, " Welcome", 8);
    if(writeVal < 0){
        printf("File Writing Error\n");
    }else{
        printf("File Writing Successful\n");
        printf("Number Of Bytes Written : %d\n", writeVal);
    }
    close(fd);
}

