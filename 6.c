/*
============================================================================
Name : 6.c
Author : Chirag Date 
Description :Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 25th Aug, 2024.
============================================================================
*/

#include <unistd.h> 
#include <stdio.h>  

void main()
{
    char *buffer[100];
    int readByteCount, writeByteCount;
    while (1)
    {
        readByteCount = read(STDIN_FILENO, buffer, 1);
        if (readByteCount == -1)
        {
            perror("Error while reading from STDIN \n");
            break;
        }        
        writeByteCount = write(STDOUT_FILENO, buffer, 1);

        if (writeByteCount == -1)
        {
            perror("Error while writing to STDOUT\n");
            break;
        }
    }
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/6$ gcc 6.c -o 6.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/6$ ./6.out
Hello
Hello

============================================================================
*/
