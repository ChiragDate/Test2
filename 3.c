/*
============================================================================
Name : 3.c
Author : Chirag Date 
Description :Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 25th Aug, 2024.
============================================================================
*/

#include <unistd.h>   
#include <stdio.h>  
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>

void main(int argc,char *argv[]) {
  char *filename;
  int fd;

  if(argc != 2){
    printf("Enter file name as argument");
  }
  else{

    filename = argv[1];

    fd = creat(filename,S_IRWXU);

    if(fd == -1){
      perror("Error in creating file \n");
    }
    else{
      printf("The file was created with fd %d \n ",fd);
    }
  }
}

/*
============================================================================
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/3$ gcc 3.c -o 3.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/3$ ./3.out newFile
The file was created with fd 3 

============================================================================
*/
