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

	short buff[4096/2]={0};


	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		perror("Open failed");
		printf("fd : %d\n\r",fd);
		exit(0);
	}
	printf(" opened fd is :%d\n\r",fd);

	ret_read = read(fd, (short *)&buff,1);
       		
	if(ret_read < 0)
	{
		perror("Read failed");
		printf("ret_read : %d\n\r",ret_read);
		exit(0);
	}

	while(ret_read > 0)
	{
		ret_read = read(fd, (short *)&buff,1);

		if(ret_read < 0)
		{
			perror("Read failed");
			printf("ret_read : %d\n\r",ret_read);
			exit(0);
		}

		ret_write = write(FILE_DESCRIPTOR_STDOUT,(short *)&buff,1); 

		if(ret_write < 0)
		{
			perror("write failed");
			printf("ret_write : %d\n\r",ret_write);
			exit(0);
		}
	}	

	close(fd);
	return 0;
}

