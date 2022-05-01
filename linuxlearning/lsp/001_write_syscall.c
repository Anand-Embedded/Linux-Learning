#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int ret;
	char *usr_msg = "Hello world\n";
	
	ret = write(1,usr_msg,strlen(usr_msg));	
	printf("ret : %d\n\r",ret);
	if(ret < 0)
	{
		perror("Write error: ");
		exit(0);
	}
	return 0;
}
