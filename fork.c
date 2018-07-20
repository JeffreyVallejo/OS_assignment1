#include <unistd.h>

main()
{
	pid_t pid;

	switch(pid = fork()) 
	{
		printf(" parent pid is", getppid() ,"\n");
		printf(" child pid is", getpid() ,"\n");
		case -1:
			perror("fork failed!")
			break;
		case 0:
			execvp(argc1[1], argv[1]);
			perror("execvp failed!");
			break;
		default:
			wait((int *)0);
			printf("\n\ncommand was executed\n\n");
			exit(0);
	}
}