/*
============================================================================
Name : 24.c
Author : Chirag Date 
Description :Write a program to create an orphan process.
Date: 29th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
  pid_t childPId;
  
  childPId = fork();
  
  if(childPId > 0){
    printf("Parent PID : %d\n",getpid());
    printf("Putting parent to sleep for 10 seconds.\n");
    sleep(10);
    printf("Exiting Parent\n");
    _exit(0);
  }
  else if(childPId == 0){
    printf("Child PId : %d\n",getpid());
    printf("Putting child to sleep for 30 seconds.\n");
    sleep(30);
    printf("Child is now awake.\n");
    
  }
  else{
    printf("Error while creating child process.\n");
  }
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/24$ gcc 24.c -o 24.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/24$ ./24.out
Parent PID : 9198
Putting parent to sleep for 10 seconds.
Child PId : 9199
Putting child to sleep for 30 seconds.
Exiting Parent

============================================================================
*/
