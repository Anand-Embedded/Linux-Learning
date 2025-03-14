#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char rdbuff[4096] = {0};
	int readlen = 0;
	int writelen = 0;
	
	if (argc < 3)
	{
		write(1, "no args\n",8);
		exit(0);
	}

	int rdfd = open (argv[1],O_RDONLY);
	if (rdfd < 1)
	{
		perror("Open read fails :");
		exit(0);
	}
	int wdfd = open (argv[2], O_WRONLY | O_CREAT, 0644);
	if (wdfd < 1)
	{
		perror("Open write fails :");
		exit(0);
	}

	while ((readlen = read(rdfd,rdbuff, 4096)) != 0)
	{
		writelen = write(wdfd, rdbuff, readlen);
		if(writelen != readlen)
		{
			perror("Write fails: ");
			exit(0);
		}
	}

	close(rdfd);
	close(wdfd);
	return 0;
}

