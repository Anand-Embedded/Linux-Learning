#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define FILE_DESCRIPTOR_STDOUT  1

int main(int argc, char *argv[])
{
	int fd;
	const struct timespec time[2];
	if(argc < 2)
	{
		printf("touch: missing file operand\n");
		exit(0);
	}
	
	fd = open(argv[1],O_CREAT | O_RDWR,0664);
	if( fd < 0)
	{
		perror("Open fail");
		exit(0);
	}
	//dup2(fd,0);
	printf("AT_FDCWD :%d\n",AT_FDCWD);
	utimensat(AT_FDCWD, argv[1],NULL , 0);	
	if(close(fd) < 0)
	{
		perror("Close fail");
		exit(0);
	}
	return 0;
}

