/*
============================================================================
Name : 16a.c
Author : Chirag Date 
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 29th Aug, 2024.
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
  //lock is lock which will be put on current file and lockstatus is status of locks of the current file 
  int fd;
  
  if(argc != 2){
    printf("Enter file name as arguement\n");
  }
  else{
    fileName = argv[1];
    
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    
    lockStatus = lock;
    
    fd = open(fileName,O_RDONLY);
    
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
      int val2 = fcntl(fd,F_SETLK,&lock);
      if(val2 == -1) {
          perror("Error setting lock");
          close(fd);
          return 1;
        }
      printf("File is locked now for reading\n");
    close(fd);
  }
  return 0;
  
}

/*
============================================================================

Process 1:-

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/16/16b$ ./16b.out temp.txt
File is locked now for reading

--------------------------------------------
Process 2:- 

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/16/16b$ ./16b.out temp.txt
File is locked now for reading

============================================================================
*/
