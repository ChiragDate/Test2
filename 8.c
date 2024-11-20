/*
============================================================================
Name : 8.c
Author : Chirag Date 
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
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

    char *filename;
    int fileDescriptor;
    char buffer[1];

    if (argc != 2)
        printf("Pass the file to be read as the argument \n");
    else
    {
        filename = argv[1];
        fileDescriptor = open(filename, O_RDONLY);

        if (fileDescriptor == -1)
            perror("Error while opening the file!\n");
        else
        {
            while (read(fileDescriptor, buffer, 1) == 1)
            {
                if (buffer[0] == '\n')
                    write(STDOUT_FILENO, "\n\n", 2);
                else
                    write(STDOUT_FILENO, buffer, 1);
            }
            write(STDOUT_FILENO, "\n", 1);
            close(fileDescriptor);
        }
    }
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/8$ gcc 8.c -o 8.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/8$ ./8.out read.txt
Lorem ipsum 

Hello world



============================================================================
*/
