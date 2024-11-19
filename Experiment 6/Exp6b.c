// Write a C program to which will write the character 'A' as the size of the previous file created in Exp6b.c .
// After execution of this file display the size of the file also display actual no. of blocks used by that file and 
// display content of that file using od command with different options.

#include "files.h"
int main(){
    int fd;
    fd = open("withoutHoles.txt", O_WRONLY);
    if(fd == -1){
        printf("File Opening Error\n");
        exit(0);
    }

    // Writing 'A' 2087 times
    for(int i = 0; i < 2087; i++){
        write(fd, "A", 1);
    }
    close(fd);
}