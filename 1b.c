/*
============================================================================
Name : 1b.c
Author : Chirag Date 
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 25th Aug, 2024.
============================================================================
*/

#include <unistd.h> 
#include <stdio.h> 

void main(int argc, char *argv[])
{

    char *filePath;     // File name of the source file
    char *hardLinkPath; // File name of the symbolic link file

    int status; // 0 -> Success, -1 -> Error

    if (argc != 3)
        printf("Enter File path and Link File path as the arguments to the program\n");
    else
    {
        filePath = argv[1];
        hardLinkPath = argv[2];

        status = link(filePath, hardLinkPath);

        if (status == -1)
            perror("Error while creating hard link!");
        else
            printf("Successfully created a hard link.\n");
    }
}

/*
============================================================================
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/1/1b$ gcc 1b.c -o 1b.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/1/1b$ ./1b.out temp2.txt link1b
Successfully created a hard link.

-----------------------------------------
Shell command 

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/1/1b$ ln temp2.txt cmdlink1b

============================================================================ 
*/
