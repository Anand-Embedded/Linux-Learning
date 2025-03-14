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
	
	for (int i = 1; i <argc ;i++)
	{
		readlen = strlen(argv[i]);	
		if (i >= 2)
			writelen = write(1, " ",1);
		writelen = write(1, argv[i],readlen);
	
		if (writelen != readlen)
		{
	  		perror("Invalid write: ");
	  		exit(0);
		}
	}
	writelen = write(1,"\n",1);
	if (writelen != 1)
	{
	  perror("Invalid write: ");
	  exit(0);
	}
	
	return 0;
}

