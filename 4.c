/*
============================================================================
Name : 4.c
Author : Chirag Date 
Description :Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 25th Aug, 2024.
============================================================================
*/

#include <unistd.h>   
#include <stdio.h>  

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>

void main(int argc, char *argv[]){
  char *filename;
  int fd; 

  if(argc != 2){
    printf("Enter filename as argument");
  }
  else{
  
  filename = argv[1];

  fd = open(filename,O_RDWR); 
  // open file with read write permissions or if not found then create using O_RDWR|O_CREAT

  if(fd == -1){
      perror("Error in creating file");
    }
    else{
      printf("The file was opened successfully with fd %d \n",fd);
      close(fd);
    }
  }
 // Only works with O_CREAT 
  fd = open(filename,O_CREAT|O_EXCL);
    if(fd == -1){
      perror("Error in creating file");
    }
    else{
      printf("The file was opened successfully using O_EXCL with fd %d \n",fd); // If file already exists O_EXCL flag throws error. Open file exclusively
      close(fd);
    }
}

/*
============================================================================
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/4$ touch test.txt
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/4$ gcc 4.c -o 4.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/4$ ./4.out test.txt
The file was opened successfully with fd 3 
The file was opened successfully using O_EXCL with fd 3 
============================================================================
*/
