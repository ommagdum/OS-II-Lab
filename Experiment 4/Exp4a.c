// Write a C program which will open a file in read mode and check for file opening errors, other wise display a message 
// "File Opened Successfully" along with the file descriptor value and read the file till end of file is reached.
// Also check if the file is read successfully and check for errors. Write any string by checking writting errors and display wrinting error
// and display "Witten Successfully" message.

#include "files.h"
int main(){
    int fd, readVal;
    char ch;
    fd = open("demo.txt", O_RDONLY);
    if(fd < 0){
        printf("File Operating Error\n");
        exit(0);
    }

    printf("File Opened Successfully\n");
    printf("File Descriptor Value: %d\n",fd);
    
    readVal = read(fd, &ch, 1);
    // Reading Single Character Form File
    if(readVal == -1){
        printf("File Reading Errors\n");
        exit(0);
    }
    printf("File Reading Successful\n");
    printf("File Contents: \n");
    printf("%c", ch);
    while((readVal = read(fd, &ch,1)) > 0){
        printf("%c",ch);
    }

    readVal = write(fd, "Welcome", 7);
    if(readVal == -1){
        printf("\nFile Writing Error Beacuse File is Opened In Read Only Mode\n");
        exit(0);
    }else{
        printf("\nFile Written Successfully\n");
    }
    close(fd);
}