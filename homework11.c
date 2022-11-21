#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
	if (argc != 3)
		exit(1);
	int fd[2];
	pid_t pid1, pid2;

	pipe(fd);
	pid1 = fork(); 
	if (pid1 == -1)
	{
		perror("fork");
		return 1;
	}
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		char* tmp1[2];
		tmp1[0] = argv[1];
		tmp1[1] = NULL;
		execvp(tmp1[0] ,tmp1);
		exit(1);
	}
	pid2 = fork(); 
	if (pid2 == -1)
	{
		perror("fork");
		return 1;
	}
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		char* tmp2[2];
		tmp2[0] = argv[2];
		tmp2[1] = NULL;
		execvp(tmp2[0], tmp2);
		exit(1);
																						        
	}
		close(fd[0]);
		close(fd[1]);	
		wait(NULL);
		wait(NULL);
		return 0;
}
