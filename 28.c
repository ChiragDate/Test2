/*
============================================================================
Name : 28.c
Author : Chirag Date 
Description : Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2024.
============================================================================
*/

#include <sched.h> 
#include <stdio.h> 

void main()
{
    int maximum_RR_Priority, minimum_RR_Priority;
    int maximum_FIFO_Priority, minimum_FIFO_Priority;

    maximum_RR_Priority = sched_get_priority_max(SCHED_RR);
    if (maximum_RR_Priority == -1)
        perror("Error while finding Maximum Round Robin priority\n");
    else
        printf("The max priority with Round Robin Scheduling Policy is : %d\n", maximum_RR_Priority);

    minimum_RR_Priority = sched_get_priority_min(SCHED_RR);
    if (minimum_RR_Priority == -1)
        perror("Error while finding minimum Round Robin priority\n");
    else
        printf("The minimum priority with Round Robin Scheduling Policy is : %d\n", minimum_RR_Priority);
        
    maximum_FIFO_Priority = sched_get_priority_max(SCHED_FIFO);
    if (maximum_FIFO_Priority == -1)
        perror("Error while finding Maximum FIFO priority\n");
    else
        printf("The max priority with FIFO Scheduling Policy is : %d\n", maximum_FIFO_Priority);

    minimum_FIFO_Priority = sched_get_priority_min(SCHED_FIFO);
    if (minimum_FIFO_Priority == -1)
        perror("Error while finding minimum FIFO priority\n");
    else
        printf("The minimum priority with FIFO Scheduling Policy is : %d\n", minimum_FIFO_Priority);
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/28$ gcc 28.c -o 28.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/28$ ./28.out
The max priority with Round Robin Scheduling Policy is : 99
The minimum priority with Round Robin Scheduling Policy is : 1
The max priority with FIFO Scheduling Policy is : 99
The minimum priority with FIFO Scheduling Policy is : 1


============================================================================
*/
