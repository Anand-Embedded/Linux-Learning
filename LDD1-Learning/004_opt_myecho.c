#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdint.h>

#define SPACE_FOR_NULL_BYTE    (1) 


int main(int argc, char *argv[])
{
	char rdbuff[4096] = {0};
	int readlen = 0; 	
	int writelen = 0;
	int totallen = 0; 
	
	if (argc < 2)
	{
		printf("no arg\n");
		exit(0);
	}
	readlen = strlen(argv[1]);
	totallen += readlen+ SPACE_FOR_NULL_BYTE;	
	char *ptr = malloc((uint8_t)totallen);
	strcpy(ptr, argv[1]);	
	for (int i = 2; i <argc ;i++)
	{
		readlen = strlen(argv[i]);	
		totallen += readlen + SPACE_FOR_NULL_BYTE;
		if (i >= 2)
		{	
			totallen++;
			ptr = realloc(ptr,totallen);
			strcat(ptr," ");
		}	
		else
		{
			ptr = realloc(ptr,totallen);
		}
		strcat(ptr,argv[i]);
	}
	readlen = strlen(ptr) + 1 /*New Line*/+ SPACE_FOR_NULL_BYTE;		
	ptr = realloc(ptr,readlen);//for appending the new line "\n"
	strcat(ptr,"\n");
	writelen = write(1, ptr,readlen);
	if (writelen != readlen)
	{
		perror("Invalid write: ");
	}
	
	free(ptr);
	return 0;
}

