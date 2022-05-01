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
	int fd;
	int ret_read;
	int ret_write;

	char buff[4096]={0};


	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		perror("Open failed");
		printf("fd : %d\n\r",fd);
		exit(0);
	}
#ifdef DEBUG_LOG_ENABLE
	printf(" opened fd is :%d\n\r",fd);
#endif

	while((ret_read = read(fd,buff,4096)) > 0)
	{
		ret_write = write(FILE_DESCRIPTOR_STDOUT,buff,4096); 

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
	close(fd);
	return 0;
}

