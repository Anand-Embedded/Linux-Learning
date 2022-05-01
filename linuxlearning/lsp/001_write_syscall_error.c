#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	int ret;
	char *usr_msg = "Hello world\n";
	
	ret = write(3,usr_msg,strlen(usr_msg));	
	printf("ret : %d\n\r",ret);
	if(ret < 0)
	{
		perror("Write error: ");
		printf("Error number is : %d\n\r",errno);
		exit(0);
	}
	return 0;
}
