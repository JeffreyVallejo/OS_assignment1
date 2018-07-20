#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

//set buffer size for arrays in pre.c
#define BUFSIZE 100


main()
{
 char inbuf[BUFSIZE];
 int p[2], j;
 pid_t pid;
 
 if (pipe(p) == -1)
 {
  printf("pipe\n");
  perror("\npipe call failed");
  exit(1);
 }
 
 switch(pid = fork()) {
 case -1: 
       printf("fork\n");
       perror("\nfork call ");
       exit(2);
 case 0:
       dup(p[1]);
       close(p[0]);
       printf("pre\n");
       execl("./pre", "pre",(char *)0);
       perror("\nexecl() pre failed\n");
       break;
 default:
       dup(p[0]);
       close(p[1]);
       //printf("sort\n");
       execl("./sort", "sort", (char *)0);
       perror("\nexecl() sort failed\n");
  }
  
  exit(0);
}