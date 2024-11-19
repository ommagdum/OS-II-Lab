// Write a C program to create a file and without holes as the same size as in program Exp5a.c.
// Display the this block required and the the file size as well as display contents of the file.
#include "files.h"
int main(){
    int fd, readVal;
    fd = open("withoutHoles.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if(fd < 0){
        printf("File Opening Error\n");
        exit(0);
    }else{
        printf("File Opened Successfully\n");
    }
    for(long i = 0; i < 500; i++){
        write(fd, "a", 1);
    }
    close(fd);
}