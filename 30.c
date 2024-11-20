/*
============================================================================
Name : 30.c
Author : Chirag Date 
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 30th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void Daemon(){
    int pId;
    pId = fork();
    if (pId < 0) {
        exit(1);
    }
    if (pId > 0) {
        exit(0);
    }
    
    umask(0);
 
    if (setsid() < 0) {
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        exit(1);
    }

    // Parse target time
    int target_hour = atoi(argv[1]);
    int target_minute = atoi(argv[2]);
    int target_second = (argc > 3) ? atoi(argv[3]) : 0;
    char *sc = argv[4];

    time_t curr_epoch, deadline_epoch;
    struct tm *deadline_tm;

    time(&curr_epoch);
    deadline_tm = localtime(&curr_epoch);

    deadline_tm->tm_sec = target_second;
    deadline_tm->tm_hour = target_hour;
    deadline_tm->tm_min = target_minute;

    deadline_epoch = mktime(deadline_tm);

    if (deadline_epoch == -1) {
        perror("Error converting deadline to epoch\n");
        exit(1);
    }
    Daemon();
    while (1) {
        time(&curr_epoch);
        if (difftime(deadline_epoch, curr_epoch) <= 0) {
            printf("Running the given script %s\n",sc);
            execl(sc, sc, (char *)NULL); // Run the script
            exit(0);  // Exit after running the script
        }
        sleep(1); // Check every 1 seconds
    }

    exit(0);
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/30$ gcc 30.c -o 30.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/30$ ./30.out 18 19 00 /bin/ls
Running the given script /bin/ls
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/30$ 30.c  30.out


============================================================================
*/
