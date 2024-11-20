/*
============================================================================
Name : 26.c
Author : Chirag Date 
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

void main(int argc,char *argv[]){
  if(argc !=2){
    printf("Enter priority as argument");
  }
  else{
  char *arg0 = "20.out";
  char *executeToRun = "./20.out";
  
  execl(executeToRun,arg0,argv[1],NULL);
  } 
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/26$ gcc 26.c -o 26.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/26$ ./26.out 12Current priority is :0
New priority is :12
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/26$ ./26.out 2
Current priority is :0
New priority is :2



============================================================================
*/
