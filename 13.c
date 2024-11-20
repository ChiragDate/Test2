/*
============================================================================
Name : 13.c
Author : Chirag Date 
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

void main(){
  
  fd_set readFDSet;
  
  struct timeval timeout;
  
  int ans;
  
  FD_ZERO(&readFDSet); //clearing the set
  FD_SET(STDIN_FILENO, &readFDSet);
  
  timeout.tv_sec = 10;
  timeout.tv_usec = 0;
  
  ans = select(STDOUT_FILENO, &readFDSet, NULL, NULL, &timeout);
  
  if(ans == -1){
    perror("Error \n");
  }
  else if(ans){ 
    printf("The data is available \n");
  }
  else{
    printf("No data was given for 10 seconds \n");  
  }
  
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/13$ gcc 13.c -o 13.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/13$ ./13.out
Hi
The data is available 

============================================================================
*/
