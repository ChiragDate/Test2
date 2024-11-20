/*
============================================================================
Name : 12.c
Author : Chirag Date 
Description :Write a program to find out the opening mode of a file. Use fcntl. 
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void main(int argc,char *argv[]){
  
  char *fileName;
  int fd;
  
  if(argc != 2){
    printf("Enter file Name as argument\n");
  }
  else{
    
    fileName = argv[1];
    fd = open(fileName,O_RDONLY);
    
    if(fd == -1){
      perror("Error while opening the file\n");
    }
    else{
      int status = fcntl(fd,F_GETFL);
      
      if(status == -1){
        perror("Error while executing fcntl system call\n");
      }
      else{
        
                switch (O_ACCMODE & status)
                {
                case 0:
                    printf("The file has been opened with the flags : O_RDONLY\n");
                    break;
                case 1:
                    printf("The file has been opened with the flags : O_WRONLY\n");
                    break;
                case 2:
                    printf("The file has been opened with the flags : O_RDWR\n");
                    break;
                case 64:
                    printf("The file has been opened with the flags : O_CREAT\n");
                    break;
                case 512:
                    printf("The file has been opened with the flags : O_TRUNC\n");
                    break;
                case 1024:
                    printf("The file has been opened with the flags : O_APPEND\n");
                    break;
                case 577:
                    printf("The file has been opened with the flags : O_WRONLY | O_CREAT | O_TRUNC\n");
                    break;
                case 1089:
                    printf("The file has been opened with the flags : O_WRONLY | O_CREAT | O_APPEND\n");
                    break;
                case 578:
                    printf("The file has been opened with the flags : O_RDWR   | O_CREAT | O_TRUNC\n");
                    break;
                case 1090:
                    printf("The file has been opened with the flags : O_RDWR   | O_CREAT | O_APPEND\n");
                    break;
                default:
                    printf("Error!");
                }
        }
        close(fd);
      }
    }
  
  }
  
/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/12$ gcc 12.c -o 12.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/12$ ./12.out test.txt
The file has been opened with the flags : O_RDONLY

============================================================================
*/




