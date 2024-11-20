/*
============================================================================
Name : 7.c
Author : Chirag Date 
Description :Write a program to copy file1 into file2 ($cp file1 file2).
Date: 25th Aug, 2024.
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>    
#include <unistd.h>    
#include <stdio.h>   


void main(int argc, char *argv[])
{

    char *sourcePath;
    char *destinationPath;

    int sourceFD, destinationFD; 
    int sourceReadCount;        
    int destinationWriteCount;   

    char *buffer[100]; 

    if (argc != 3)
        printf("Pass the source & destination file name as the argument\n");
    else
    {
        sourcePath = argv[1];
        destinationPath = argv[2];

       
        sourceFD = open(sourcePath, O_RDONLY);
  
        destinationFD = open(destinationPath, O_CREAT | O_RDWR, S_IRWXU);

        if (sourceFD == -1 || destinationFD == -1)
        {
            perror("Error while opening source / destination file");
            _exit(1);
        }

        while ((sourceReadCount = read(sourceFD, buffer, 100)) > 0)
        {
            destinationWriteCount = write(destinationFD, buffer, sourceReadCount);
            if (destinationWriteCount == -1)
                perror("Error while writing content");
        }

        if (sourceReadCount == -1)
            perror("Error while reading content");
        else
            printf("Successfully copied the contents!\n");

        close(sourceFD);
        close(destinationFD);
    }
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/7$ gcc 7.c -o 7.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/7$ ./7.out readFile.txt writeFile.txt
Successfully copied the contents!

============================================================================
*/
