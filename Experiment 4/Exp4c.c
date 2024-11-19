// Write a C Program to open a file in read-write mode , check for any file opeing errors otherwise write "Welcome" to file .
// Write any string to the file and after executing the program check the contents of the file using cat command.
#include "files.h"
int main(){
    int fd, writeVal, readVal;
    fd = open("exp4c.txt", O_RDWR);
    if(fd < 0){
        printf("File Opening Error\n");
        exit(0);
    }
    printf("File Opened Successfully\n");
    writeVal = write(fd, "Welcome", 7);
    if(writeVal < 0){
        printf("File Writing Error\n");
        exit(0);
    }
    lseek(fd, 0, SEEK_CUR);
    readVal = read(fd, &readVal, 1);
    if(readVal < 0){
        printf("File Reading Error\n");
        exit(0);
    }
    printf("File Contents: ");
    while(read(fd, &readVal, 1) > 0){
        printf("%c", readVal);
    }
    write(fd, "Magdum", 6);
    close(fd);
}