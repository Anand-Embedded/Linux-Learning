#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <stdlib.h>

int main(void)
{
	
	int ret;
	int cnt;

	printf("Welcome to the fork system call !!!\n");
	
	ret=fork();

	if(ret < 0)
	{
		perror("Fork failed");
		exit(0);
	}

	if(ret == 0)//child process
	{
		cnt = 100;
		printf("child process : %d\t%d\n",getpid(),cnt);
		printf("child process -> parent process : %d\n",getppid());

	}
	else //parent process
	{
		cnt = 200;
		printf("parent process : %d\t%d\n",getpid(),cnt);
		printf("parent process -> parent process : %d\n",getppid());

	}
	return 0;

}


