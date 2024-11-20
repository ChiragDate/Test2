/*
============================================================================
Name : 20.c
Author : Chirag Date 
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 29th Aug, 2024.
============================================================================
*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc,char *argv[]){
  int currentPriority, newPriority;
  
  if(argc != 2){
    printf("Enter a value to be added to the current priority as arguement \n");
  }
  else{
    newPriority = atoi(argv[1]); 
    currentPriority = nice(0);
    printf("Current priority is :%d\n",currentPriority);
    currentPriority = nice(newPriority);
    printf("New priority is :%d\n",currentPriority);
  }
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/20$ gcc 20.c -o 20.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/20$ ./20.out 5
Current priority is :0
New priority is :5

============================================================================
*/
