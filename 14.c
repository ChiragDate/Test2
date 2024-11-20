/*
============================================================================
Name : 14.c
Author : Chirag Date 
Description : Write a program to find the type of a file. 
    1. Input should be taken from command line. 
    2. Program should be able to identify any type of a file.
Date: 29th Aug, 2024.
============================================================================
*/
    
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc,char *argv[]){
  
  struct stat statbuffer;
  char *fileName;
  int fd;
  
  if(argc != 2){
    printf("Enter file name as arguements \n");
  }
  else{
    fileName = argv[1];
    fd = open(fileName, O_RDONLY);
    
    fstat(fd, &statbuffer);
    
    if(S_ISREG(statbuffer.st_mode)){
      write(STDOUT_FILENO,"Regular File\n",13);
    }
    else if(S_ISDIR(statbuffer.st_mode)){
      write(STDOUT_FILENO,"Directory File\n",15);
    }
    else if(S_ISCHR(statbuffer.st_mode)){
      write(STDOUT_FILENO,"Character File\n",13);
    }
    else if(S_ISBLK(statbuffer.st_mode)){
      write(STDOUT_FILENO,"Block File\n",11);
    }
    else if(S_ISFIFO(statbuffer.st_mode)){
      write(STDOUT_FILENO,"FIFO File\n",10);
    }
    else if(S_ISLNK(statbuffer.st_mode)){
      write(STDOUT_FILENO,"SLink File\n",12);
    }
    else if(S_ISSOCK(statbuffer.st_mode)){
      write(STDOUT_FILENO,"Socket \n",8);
    }
    else{
      write(STDOUT_FILENO,"UNKNOWN \n",7);
    }
  }
  return 0;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/14$ gcc 14.c -o 14.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/14$ ./14.out
Enter file name as arguements 
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/14$ ./14.out hello.txt
Regular File

============================================================================
*/
