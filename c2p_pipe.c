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
  perror("\npipe call");
  exit(1);
 }
 
 switch(pid = fork()) {
 case -1: 
       perror("\nfork call");
       exit(2);
 case 0:
       close(1);
       dup(p[1]);
       close(p[0]);
       close(p[1]);
       execl("./pre", "pre",(char *)0);
       perror("\nexecl() failed\n");
       break;
 default:
       close(0);
       dup(p[0]);
       close(p[0]);
       close(p[1]);
       execl("./sort", "sort", (char *)0);
       perror("\nexecl() failed\n");
  }
  
  exit(0);
}