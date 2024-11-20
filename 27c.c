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

    char *envi[] = { "MY_VAR=HelloWorld" , NULL};

    //unlike others,allows us to use specific custom environment for new process  
    execle("/bin/ls", "ls", "-Rl", (char *)NULL, envi);

    // If execle returns, there was an error
    perror("execle");
    return 1;
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27c$ gcc 27c.c -o 27c.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/27/27c$ ./27c.out
.:
total 20
-rw-rw-r-- 1 chirag-date chirag-date  1313 Aug 30 18:13 27c.c
-rwxrwxr-x 1 chirag-date chirag-date 16056 Aug 30 18:13 27c.out


============================================================================
*/
