#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ret;
	char buff[50];
	//fd is 0 is stdin 
	ret = read(0,buff,6);
	if(ret < 0)
	{
		perror("Read fail ");
		printf("errno : %d\n\r",errno);
		exit(0);
	}	
	printf("Ret : %d\t buff:%s\n\r",ret,buff);
	return 0;
}
