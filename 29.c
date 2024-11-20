/*
============================================================================
Name : 29.c
Author : Chirag Date 
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 30th Aug, 2024.
============================================================================
*/

#include <sched.h>
#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    int currentPolicy;
    pid_t pid;
    pid = getpid();
    currentPolicy = sched_getscheduler(pid);
    struct sched_param priority;
    
    priority.sched_priority = 15;

    switch (currentPolicy)
    {
    case SCHED_FIFO:
        printf("Current policy is FIFO\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currentPolicy = sched_getscheduler(pid);
        printf("Current policy variable is %d\n", currentPolicy);
        break;
    case SCHED_RR:
        printf("Current policy is Round Robin\n");
        sched_setscheduler(pid, SCHED_FIFO, &priority);
        currentPolicy = sched_getscheduler(pid);
        printf("Current policy variable is %d\n", currentPolicy);
        break;
    case SCHED_OTHER:
        printf("Current policy is OTHER\n");
        printf("Switching to RR policy\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currentPolicy = sched_getscheduler(pid);
        printf("Current policy variable is %d\n", currentPolicy);
        break;
    default:
        perror("Error while getting current policy\n");
    }
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/29$ gcc 29.c -o 29.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/29$ ./29.out
Current policy is OTHER
Switching to RR policy
Current policy variable is 0

============================================================================
*/
