/*
============================================================================
Name : 15.c
Author : Chirag Date 
Description : Write a program to display the environmental variable of the user (use environ).
Date: 29th Aug, 2024.
============================================================================
*/


#include <stdio.h>

extern char **environ;

int isUser(char *v){
  return v[0] == 'U' && v[1] == 'S' && v[2] == 'E' && v[3] == 'R' && v[4] == '=';
} 

void main(){
  
  int iter = -1;
  while(environ[++iter] != NULL){
    if(isUser(environ[iter])){
      printf("%s\n",environ[iter]);
    }
  }

}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/15$ gcc 15.c -o 15.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/15$ ./15.out
USER=chirag-date

============================================================================
*/



