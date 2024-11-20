/*
============================================================================
Name : 27.c
Author : Chirag Date 
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    char *executableToRun = "/bin/ls";
    char *arg0OfCommand= "ls";
    char *arg1OfCommand = "-Rl";
    
    execl(executableToRun , arg0OfCommand , arg1OfCommand , (char *)NULL);

    perror("execl");
    return 1;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27a$ gcc 27a.c -o 27a.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27a$ ./27a.out
.:
total 20
-rw-rw-r-- 1 chirag-date chirag-date   780 Aug 30 18:06 27a.c
-rwxrwxr-x 1 chirag-date chirag-date 16000 Aug 30 18:07 27a.out
  

============================================================================
*/
