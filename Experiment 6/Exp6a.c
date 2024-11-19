// Write a C program which will write a string "Welcome To TKIET" and then it will create a hole of 2k byte
// and write the string hole of 2k byte created. After execution of this program, see the size of the file.
// Also see how many actually diskblocks used by the file & display the contents of that file using OD command with different options.

#include "files.h"
int main(){
    int fd, newHole;
    fd = open("holes.txt", O_WRONLY);
    if(fd == -1){
        printf("Error Opening File\n");
        exit(0);
    }
    printf("File Opened Successfully\n");
    write(fd, "Welcome To TKIET", 16);
    newHole = lseek(fd, 2048, SEEK_CUR);
    printf("New Byte of set in the file : %d\n", newHole);
    write(fd, "Holes Of 2k Bytes Is Created", 28);
    close(fd);
}