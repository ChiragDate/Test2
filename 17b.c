/*
============================================================================
Name : 17b.c
Author : Chirag Date 
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 29th Aug, 2024.
============================================================================
*/

#include <unistd.h>   
#include <fcntl.h>    
#include <sys/types.h> 
#include <sys/stat.h>  
#include <stdio.h>    

int main() {
    struct flock lock;
    int fd;
    struct {
        int ticket_no;
    } db;

    fd = open("17b_db", O_RDWR);
    if (fd == -1) {
        perror("Error 17b_db file\n");
        return 1;
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;
    lock.l_len = 0; 
    lock.l_pid = getpid();

    printf("Before entering into critical section\n");

    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section\n");

    read(fd, &db, sizeof(db));
    printf("Current ticket number: %d\n", db.ticket_no);
    db.ticket_no++;
    lseek(fd, 0, SEEK_SET);
    write(fd, &db, sizeof(db));

    printf("New ticket number: %d\n", db.ticket_no);

    printf("Press enter to unlock\n");
    getchar(); 

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Exited critical section\n");
    close(fd); 
    return 0;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/17/17b$ gcc 17b.c -o 17b.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/17/17b$ ./17b.out
Before entering into critical section
Inside the critical section
Current ticket number: 667697
New ticket number: 667698
Press enter to unlock

Exited critical section

============================================================================
*/





