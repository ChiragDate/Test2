
/*
============================================================================
Name : 23.c
Author : Chirag Date 
Description : Write a program to create a Zombie state of the running program.
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
    printf("Putting parent to sleep for 30 seconds.\n");
    sleep(30);
    printf("Parent is now awake\n");
  }
  else if(childPId == 0){
    printf("Child PId : %d\n",getpid());
    printf("Exiting child\n");
    _exit(0);
  }
  else{
    printf("Error while creating child process.\n");
  }
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/23$ gcc 23.c -o 23.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/23$ ./23.out
Parent PID : 8878
Putting parent to sleep for 30 seconds.
Child PId : 8879
Exiting child
Parent is now awake

============================================================================
*/
