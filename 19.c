/*
============================================================================
Name : 19.c
Author : Chirag Date 
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 29th Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

int main(){
  int start,end,pid;
  struct timeval timestamp;
  
  start = __rdtsc();
  pid = getpid();
  end = __rdtsc();
  
  printf("pid : %d\n",pid);
  printf("Time taken by system call is: %d\n",(end-start));
  return 0;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/19$ gcc 19.c -o ./19.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/19$ ./19.out
pid : 7719
Time taken by system call is: 9756

============================================================================
*/
