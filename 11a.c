/*
============================================================================
Name : 11a.c
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
    printf("Enter file name as argument \n");
  }
  else{
    fileName = argv[1];
    fd = open(fileName,O_WRONLY | O_APPEND);
    if(fd == -1){
      perror("Error while opening file \n");
    }
    else{
      dfd = dup(fd);

      writecount = write(fd,"Using original fd \n",15);
      if(writecount == -1){
        perror("Error while writing main file \n");
      }
      writecount = write(dfd,"Using duplicated fd \n",16);
      if(writecount == -1){
        perror("Error while writing in duplicate fd\n");
      }
      close(fd);
    }
  }
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/11/11a$ touch file.txt
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/11/11a$ gcc 11a.c -o 11a.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/11/11a$ ./11a.out file.txt

============================================================================
*/ 

/*
============================================================================
Output in file.txt 
Using original Using duplicated 

============================================================================
*/
