#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include <string.h>
#include <stdio.h>

#define FILE_DESCRIPTOR_STDOUT  1

int main(int argc, char *argv[])
{
	int ret_write;
	char arr[4096];
	
	strncpy(arr,argv[1],strlen(argv[1]));

#ifdef DEBUG_LOG_ENABLE	
	printf("Before string len :%ld\n\r", strlen(arr));
#endif

	arr[strlen(arr)] = '\n';
	arr[strlen(arr)+1] = '\0';

#ifdef DEBUG_LOG_ENABLE	
	printf("AFter string len :%ld\n\r", strlen(arr));
#endif

	ret_write = write(1,arr,strlen(&arr[0]));
	if(ret_write < 0)
	{
		perror("write failed");
		printf("ret_write : %d\n\r",ret_write);
		exit(0);
	}

	return 0;
}

