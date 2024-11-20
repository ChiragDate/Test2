/*
============================================================================
Name : 17a.c
Author : Chirag Date 
Description : Write a program to find the type of a file. 
    1. Input should be taken from command line. 
    2. Program should be able to identify any type of a file.
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd;
    char ticket_number[100];
    ssize_t bytes_read;
    struct flock lock;

    fd = open("ticket_db", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Failed to open file");
        exit(0);
    }

    lock.l_type = F_WRLCK;    
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;        
    lock.l_len = 0;          
    lock.l_pid = getpid();   

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to get write lock");
        close(fd);
        exit(0);
    }

    printf("Enter ticket number: ");
    fflush(stdout);  // 
    bytes_read = read(STDIN_FILENO, ticket_number, sizeof(ticket_number) - 1);
    if (bytes_read == -1) {
        perror("Failed to read ticket number\n");
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        exit(0);
    }

    ticket_number[bytes_read] = '\0';

    if (write(fd, ticket_number, bytes_read) == -1) {
        perror("Failed to write ticket number\n");
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        exit(0);
    }

    printf("Ticket number written to file.\n");

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release write lock");
    }

    close(fd);
    return 0;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/17$ gcc 17a.c -o 17a.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/17$ ./17a.out
10
Enter ticket number: Ticket number written to file.
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/17$ cat ticket_db
10

============================================================================
*/




