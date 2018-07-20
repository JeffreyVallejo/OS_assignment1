#include<stdio.h>
#include<unistd.h>

int main () 
{
	int fd[2];
	pipe(fd);
	pid_t pid;
	
	pid = fork();
	
	if(pid < 0)
	{
		fprint(stderr, "Fork Failed!");
		exit(-1);
	}
	else if(pid == 0) //child needs to execute pre.c
	{
		close(0);
		dup(fd[0]);
		close(fd[1]);
	}
	else //parent needs to execute sort.c
	{
		close(1);
		dup(fd[1]);
		close(fd[1]);
		close(fd[0]);
	}
	return 0;
}

