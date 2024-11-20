/*
============================================================================
Name : 1c.c
Author : Chirag Date 
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 25th Aug, 2024.
============================================================================
*/

#include <unistd.h>   
#include <stdio.h>  
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>  

void main(){
 
  char *fifoname = "mkfifofile";
  char *mkfifoname = "mknodefifofile";

  int fifostatus,sysfifostatus;

  // used mkfifo library
  fifostatus = mkfifo(fifoname,S_IRWXU); 

  if(fifostatus == -1){
    perror("error while creating FIFO pipe");
  }
  else{
    printf("Created a FIFO file using mkfifo \n");
  }

  //use mknod sys call

  sysfifostatus = mknod(mkfifoname,__S_IFIFO | S_IRWXU, 0);
  
  if(fifostatus == -1){
    perror("error while creating FIFO pipe");
  }
  else{
    printf("Created a FIFO file using mknod \n");
  }

}

/*
============================================================================
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/1/1c$ gcc 1c.c -o 1c.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/1/1c$ ./1c.out
Created a FIFO file using mkfifo 
Created a FIFO file using mknod 

---------------------------------------
Shell command

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/1/1c$ mkfifo cmdpipe

============================================================================
*/
