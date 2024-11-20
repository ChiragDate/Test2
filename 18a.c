/*
============================================================================
Name : 18a.c
Author : Chirag Date 
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 29th Aug, 2024.
============================================================================
*/



#include <unistd.h>    
#include <fcntl.h>     
#include <sys/types.h> 
#include <sys/stat.h>  
#include <stdlib.h>
#include <stdio.h>    

struct database {
    int trainnum;
    int ticketcount;
};

int main() {
    int fd, input;
    struct database db;

    fd = open("18.txt", O_RDWR);
   
    printf("Select train number: 1, 2, 3\n");
    scanf("%d", &input);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;

    lock.l_start = (input - 1) * sizeof(struct database);
    lock.l_len = sizeof(struct database);
    lock.l_pid = getpid();

    lseek(fd, (input - 1) * sizeof(struct database), SEEK_SET);
    read(fd, &db, sizeof(struct database));

    printf("Before entering critical section\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error setting lock");
        exit(0);
    }

    printf("Current ticket count: %d\n", db.ticketcount);
    db.ticketcount++;

    // Moving the file pointer to the start of the current record
    lseek(fd, -1 * sizeof(struct database), SEEK_CUR);
    write(fd, &db, sizeof(struct database));

    printf("To book ticket, press enter\n");
    getchar();
    getchar();

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error unlocking");
        close(fd);
        exit(0);
    }

    printf("Ticket booked with number %d\n", db.ticketcount);
    close(fd);
    return 0;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/18/18a$ touch 18.txt
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/18/18a$ gcc 18a.c -o 18a.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/18/18a$ ./18a.out
Select train number: 1, 2, 3
1
Before entering critical section
Current ticket count: 0
To book ticket, press enter

Ticket booked with number 1
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/18/18a$ ./18a.out
Select train number: 1, 2, 3
2
Before entering critical section
Current ticket count: 0
To book ticket, press enter
 
Ticket booked with number 1
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/18/18a$ ./18a.out
Select train number: 1, 2, 3
1
Before entering critical section
Current ticket count: 1
To book ticket, press enter

Ticket booked with number 2


============================================================================
*/


