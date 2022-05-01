#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#define FILE_DESCRIPTOR_STDOUT  1
#define NEW_LINE	'\n'
#define SPACE_BAR	' '



int main(int argc, char *argv[])
{
	int fd;
	int ret_read;
	int ret_write;
	int cnt_line = 0,cnt_word = 0 ,cnt_char = 0;
	int loop;
	char buff[4096]={0};

	if(argc < 2)
	{
		printf("Command Usage : %s  <file>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		perror("Source file Open failed");
		printf("fd : %d\n\r",fd);
		exit(0);
	}

#ifdef DEBUG_LOG_ENABLE
	printf(" opened fd is :%d\n\r",fd);
#endif

	while((ret_read = read(fd,buff,4096)) > 0)
	{
#ifdef DEBUG_LOG_ENABLE
		printf("String : %s\n",buff);
#endif
		for(loop = 0; loop < ret_read; loop++)
		{
			if(buff[loop] == NEW_LINE)
			{
				cnt_line++;
				if((buff[loop+1] != SPACE_BAR))
					cnt_word++;
				cnt_char++;
			}
			else if(buff[loop] == SPACE_BAR && ( (buff[loop+1] != SPACE_BAR) &&  (buff[loop+1] != NEW_LINE)))
			{
				cnt_word++;
				cnt_char++;
			}
			else
			{
				cnt_char++;
			}
		}
	}	

	if(ret_read < 0)
	{
		perror("Read failed");
		printf("ret_read : %d\n\r",ret_read);
		exit(0);
	}
	
#ifdef DEBUG_LOG_ENABLE
	sprintf(buff,"Lines : %d\t Words : %d\t Character : %d\n",cnt_line,cnt_word,cnt_char);
#endif
	sprintf(buff,"%d\t %d\t %d\t %s\n",cnt_line,cnt_word,cnt_char,argv[1]);
	ret_write = write(1,buff,strlen(buff)); 

	if(ret_write < 0)
	{
		perror("write failed");
		printf("ret_write : %d\n\r",ret_write);
		exit(0);
	}

	if(close(fd) < 0)
	{
		perror("Close failed");
		exit(0);
	}

	return 0;
}

