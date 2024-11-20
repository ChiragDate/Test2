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
    
    // Instead of seperate arguements takes one char array and path needs to be given.
    
    char *argv[] = { "ls", "-Rl", NULL };

    execv("/bin/ls", argv);

    perror("execv");
    return 1;
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27d$ gcc 27d.c -o 27d.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27d$ ./27d.out
.:
total 36
-rw-rw-r-- 1 chirag-date chirag-date  1241 Aug 30 18:17 27d.c
-rwxrwxr-x 1 chirag-date chirag-date 16056 Aug 30 18:21 27d.out
-rwxrwxr-x 1 chirag-date chirag-date 16056 Aug 30 18:17 27.out



============================================================================
*/
