// Write a C program that will create 3 different holes of size 75 kb, 150 kb and 12000 kb. 
// See the file size, observe file also this block requirement using ls -ls in "filename" also display contents using cat command.
#include "files.h"
int main(){
    int fd, readValue;
    char ch;
    fd = open("holes.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if(fd < 0){
        printf("File Opening Error\n");
        exit(0);
    }else{
        printf("File Opening Successfully\n");
    }

    readValue = write(fd, "Hole One Start", 15);
    if(readValue < 0){
        printf("File Writing Error\n");
    }

    lseek(fd, 75000, SEEK_CUR);
    readValue = write(fd, "Hole End", 8);
    readValue = write(fd, "Hole Second Start", 17);
    if(readValue < 0){
        printf("Writing Error\n");
    }

    lseek(fd, 150000, SEEK_CUR);
    readValue = write(fd, "Second Hole End", 15);
    readValue = write(fd, "Hole Third Start", 16);
    if(readValue < 0){
        printf("Writing Error\n");
    }

    lseek(fd, 1200000, SEEK_CUR);
    readValue = write(fd, "Third Hole End", 14);
    if(readValue < 0){
        printf("Writing Error\n");
    }
    close(fd);

}