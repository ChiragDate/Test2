/*
============================================================================
Name : 16a.c
Author : Chirag Date 
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 30th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc,char *argv[]){

  char *fileName;
  struct flock lock,lockStatus;
  int fd;
  
  if(argc != 2){
    printf("Enter file name as argument\n");
  }
  else{
    fileName = argv[1];
    
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    
    lockStatus = lock;
    
    fd = open(fileName,O_RDWR);
    
    if(fd == -1){
      perror("Error while opening the file\n");
      return 1;
    }
    
    int val = fcntl(fd,F_GETLK,&lockStatus);
    
    if(val == -1){
      perror("Error while getting lock status\n");
      close(fd);
      return 1;
    }
    
    if(lockStatus.l_type == F_WRLCK){
      printf("File is already locked for writing \n");
      getchar();
    }
    if(lockStatus.l_type == F_RDLCK){
      printf("File is already locked for reading \n");
      getchar();
    }
      printf("==== Critical Section =====\n");
      fcntl(fd,F_SETLK,&lock);
      printf("File is locked now for writing\n");
      getchar();
    close(fd);
  }
  return 0;
  
}


/*
============================================================================

Process 1:- 

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/16/16a$ gcc 16a.c -o 16a.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/16/16a$ ./16a.out text.txt
==== Critical Section =====
File is locked now for writing

------------------------------------------------------------

Process 2:- 

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/16/16a$ ./16a.out text.txt
File is already locked for writing 

==== Critical Section =====
File is locked now for writing


============================================================================
*/

