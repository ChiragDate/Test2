/*
============================================================================
Name : 11b.c
Author : Chirag Date 
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl 
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc,char *argv[]){
  char *fileName;
  int fd,dfd;
  int writecount;

  if(argc != 2){
    printf("Enter file name as arguement \n");
  }
  else{
    fileName = argv[1];
    fd = open(fileName,O_WRONLY | O_APPEND);
    if(fd == -1){
      perror("Error while opening file \n");
    }
    else{
      dfd = dup2(fd,111);

      writecount = write(fd,"Use original fd \n",15);
      if(writecount == -1){
        perror("Error while writing main file \n");
      }
      writecount = write(dfd,"Use duplicated fd \n",16);
      if(writecount == -1){
        perror("Error while writing in duplicate fd\n");
      }
      close(fd);
    }
  }
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/11/11b$ touch file.txt
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/11/11b$ gcc 11b.c -o 11b.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/11/11b$ ./11b.out file.txt


============================================================================
*/

/*
============================================================================

file output 
Use original fd Use duplicated fd


============================================================================
*/

