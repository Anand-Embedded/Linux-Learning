#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_DESCRIPTOR_STDOUT  1

int main(int argc, char *argv[])
{
	int fd1,fd2;
	int ret_read;
	int ret_write;

	char buff[4096]={0};

	if(argc < 3)
	{
		printf("Command usage : %s <Source file> <Destination file>\n",argv[0]);
		exit(EXIT_FAILURE);
	}


	fd1 = open(argv[1],O_RDONLY);
	if(fd1 < 0)
	{
		perror("Source file Open failed");
		printf("fd1 : %d\n\r",fd1);
		exit(0);
	}

	fd2 = open(argv[2],O_RDWR | O_CREAT | O_TRUNC, 0664);
	if(fd2 < 0)
	{
		perror("Destination file open failed");
		printf("fd2 : %d\n\r",fd2);
		exit(0);
	}
#ifdef DEBUG_LOG_ENABLE
	printf(" opened fd1 is :%d\n\r",fd1);
	printf(" opened fd2 is :%d\n\r",fd2);
#endif

	while((ret_read = read(fd1,buff,4096)) > 0)
	{
		ret_write = write(fd2,buff,ret_read); 

		if(ret_write < 0)
		{
			perror("write failed");
			printf("ret_write : %d\n\r",ret_write);
			exit(0);
		}
	}	

	if(ret_read < 0)
	{
		perror("Read failed");
		printf("ret_read : %d\n\r",ret_read);
		exit(0);
	}

	if(close(fd1) < 0)
	{
		perror("Close failed");
		exit(0);
	}

	if(close(fd2) < 0)
	{
		perror("Close failed");
		exit(0);
	}
	return 0;
}

