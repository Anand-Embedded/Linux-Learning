#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char rdbuff[4096] = {0};
	int readlen = 0; 	
	int fd = open(argv[1],O_RDONLY,0777);
	if (fd<0)
	{
	  perror("Invalid open: ");
	  exit(0);
	}
	

	readlen = read(fd,&rdbuff[0],sizeof(rdbuff));
	while(readlen != 0)
	{
		write(1,&rdbuff,readlen); 
		readlen = read(fd,&rdbuff[0],sizeof(rdbuff));
  	}

	return 0;
}

