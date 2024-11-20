/*
============================================================================
Name : 18b.c
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
    int ticket_count;
};

int main() {
    int fd, input;
    struct database db;

    fd = open("18b.txt", O_RDWR);

    printf("Select train number: 1, 2, 3\n");
    scanf("%d", &input);

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;

    lock.l_start = (input - 1) * sizeof(struct database);
    lock.l_len = sizeof(struct database);
    lock.l_pid = getpid();

    // Read lock
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error setting read lock");
        close(fd);
        return 1;
    }

    lseek(fd, (input - 1) * sizeof(struct database), SEEK_SET);
    if (read(fd, &db, sizeof(struct database)) != sizeof(struct database)) {
        perror("Error reading record");
        close(fd);
        exit(0);
    }

    printf("Current ticket count for train %d: %d\n", db.trainnum, db.ticket_count);

    printf("To release the read lock, press enter\n");
    getchar();
    getchar();

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error unlocking");
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/18/18b$ gcc 18b.c -o 18b.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/18/18b$ ./18b.out
Select train number: 1, 2, 3
1
Current ticket count for train 0: 2
To release the read lock, press enter
        

============================================================================
*/
