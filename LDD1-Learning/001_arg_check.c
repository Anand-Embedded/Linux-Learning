#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{

	printf("Hello world :%d\n", argc);
	for (int i =1 ; i < argc ;i++)
		printf("sting:%s\n",argv[i]);  
	return 0;
}

