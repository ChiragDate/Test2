/*
============================================================================
Name : 21.c
Author : Chirag Date 
Description : Write a program, call fork and print the parent and child process id.
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
  
  int childId,parentId;
  
  parentId = getpid();
  
  printf("Parent ID : %d\n",parentId);
  
  childId = fork();
  
  if(childId == -1){
    perror("Fork has failed \n");
  }
  else if(childId > 0) //Parent Process 
  {
    printf("Child ID : %d\n",childId);
  }
  
    
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/21$ gcc 21.c -o 21.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/21$ ./21.out
Parent ID : 15196
Child ID : 15197

============================================================================
*/
