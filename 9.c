/*
============================================================================
Name : 9.c
Author : Chirag Date 
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

void main(int argc , char *argv[]){

  char *fileName;
  int status;

  struct stat data;

  if(argc != 2){
  printf("Please enter file name as argument \n");
  }
  else{

    fileName = argv[1];
    
    status = stat(fileName, &data);
    //returns info of file in data

    if(status == -1){
      perror("Error while executing the file \n");
    }
    else{
          printf("Inode -> %ld\n", data.st_ino);
          printf("Number of hardlinks -> %ld\n", data.st_nlink);
          printf("UID -> %d\n", data.st_uid);
          printf("GID -> %d\n", data.st_gid);
          printf("Size -> %ld\n", data.st_size);
          printf("Block Size -> %ld\n", data.st_blksize);
          printf("Number of Blocks -> %ld\n", data.st_blocks);
          // `ctime` function in `time.h` header -> converts the timestamp in epoch to a readable format
          printf("Time of last access -> %s", ctime(&data.st_atim.tv_sec));
          printf("Time of last modification -> %s", ctime(&data.st_mtim.tv_sec));
          printf("Time of last change -> %s", ctime(&data.st_ctim.tv_sec));
    }

  }

}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/9$ touch temp.txt
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/9$ gcc 9.c -o 9.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/9$ ./9.out temp.txt
Inode -> 11781
Number of hardlinks -> 1
UID -> 1000
GID -> 1000
Size -> 0
Block Size -> 4096
Number of Blocks -> 0
Time of last access -> Sat Aug 24 23:44:54 2024
Time of last modification -> Sat Aug 24 23:44:54 2024
Time of last change -> Sat Aug 24 23:44:54 2024


============================================================================
*/
