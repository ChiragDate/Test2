/*
============================================================================
Name : 22.c
Author : Chirag Date 
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 29th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc,char *argv[]){

  char *fileName;
  int childPId,fd;
  
  if(argc !=2){
    printf("Enter file name as argument \n");
  }
  else{
    fileName = argv[1];
    fd = open(fileName,O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    childPId = fork();
    if(childPId != 0){
      write(fd,"Parent\n",7);
    }
    else{
      write(fd,"Child\n",6);
    }
  }
    printf("Both parent and child have written file\n");
    close(fd);
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/22$ cat temp.txt
Some written text.

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/22$ gcc 22.c -o 22.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/22$ ./22.out temp.txt
Both parent and child have written file
Both parent and child have written file
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/22$ cat temp.txt
Some written text.

Parent
Child

============================================================================
*/
