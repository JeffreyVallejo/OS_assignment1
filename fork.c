#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
int main(int argc, char* argv[])
{
	pid_t pid;

	switch(pid = fork()) 
	{
		
		case -1:
			perror("fork failed!");
			break;
		case 0:
			printf("parent pid is %d\n", (int) getppid());
			printf("child pid is %d\n" , (int) getpid());
			execvp(argv[1], &argv[1]);
			perror("execvp failed!");
			break;
		default:
			wait(NULL);
			printf("\n\ncommand was executed\n\n");
			exit(0);
	}
}