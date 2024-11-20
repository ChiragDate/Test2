/*
============================================================================
Name : 27b.c
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
    char *executableToRun = "ls"; //Can execute without giving full path
    char *arg0OfCommand= "ls";
    char *arg1OfCommand = "-Rl";
    
    execlp(executableToRun , arg0OfCommand , arg1OfCommand , (char *)NULL);

    perror("execlp");
    return 1;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27b$ gcc 27b.c -o 27b.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27b$ ./27b.out
.:
total 20
-rw-rw-r-- 1 chirag-date chirag-date  1293 Aug 30 18:09 27b.c
-rwxrwxr-x 1 chirag-date chirag-date 16000 Aug 30 18:09 27b.out



============================================================================
*/
