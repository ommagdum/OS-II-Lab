// Write a C program which will open a file in write only mode and check for file opening errors during file opening,
// otherwsie display value of file descriptor. Write any string by checking writting errors and display wrinting error.
// Also try to read the file and check for errors or display file reading sucessful message.

#include "files.h"
int main(){
    int fd, writeVal;
    fd = open("demo.txt", O_WRONLY);
    if(fd < 0){
        printf("File Opening Error\n");
        exit(0);
    }
    printf("File Opened Successfully\n");
    printf("File Descriptor Value: %d\n",fd);

    writeVal = write(fd, " Welcome", 8);
    if(writeVal == -1){
        printf("File Writing Error\n");
        exit(0);
    }
    printf("File Written Successfully\n");
    printf("Number Of Bytes Written : %d\n", writeVal);

    int readVal = read(fd, &writeVal, 1);
    if(readVal == -1){
        printf("File Reading Error As File Is Opened In Write Only Mode\n");
        exit(0);
    }
    printf("File Reading Successful\n");
    printf("Number Of Bytes Read : %d\n", readVal);
    close(fd);
}