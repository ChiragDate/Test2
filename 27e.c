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
    
    // Takes args as execv but doesnt need path just specify command name
    char *argv[] = { "ls" , "-Rl", NULL };

    execvp("ls", argv);

    perror("execvp");
    return 1;
}




/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27e$ gcc 27e.c -o 27e.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27e$ ./27e.out
.:
total 20
-rw-rw-r-- 1 chirag-date chirag-date  1223 Aug 30 18:20 27e.c
-rwxrwxr-x 1 chirag-date chirag-date 16056 Aug 30 18:20 27e.out




============================================================================
*/
