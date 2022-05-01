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



int main(int argc, char *argv[])
{
	int fd;
	int ret_read;
	int ret_write;
	int cnt_line = 10;
	int option = 10;
	int loop;
	char buff[4096]={0};
	char copy_buff[4096]={0};
	int track_buff = 0;
	
	if(argc < 2)
	{
		printf("Command usage : %s <file>\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	else if(argc == 3)
	{
		//if user provide option 
		cnt_line = atoi(argv[2]);
#ifdef DEBUG_LOG_ENABLE
		printf("cnt_line : %d\n",cnt_line);
#endif
	}
	else
	{
		;
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

	while(cnt_line)
	{
#ifdef DEBUG_LOG_ENABLE
		printf("String : %s\n",buff);
#endif
		ret_read = read(fd,buff,4096);

		if(ret_read < 0)
		{
			perror("Read failed");
			printf("ret_read : %d\n\r",ret_read);
			exit(0);
		}
		
		for(loop = 0; loop < ret_read; loop++)
		{
			if((buff[loop] == NEW_LINE) && (cnt_line))
			{
				buff[loop] = '\0';
				strncpy(copy_buff,&buff[track_buff],strlen(&buff[track_buff]));
				copy_buff[strlen(copy_buff)] = '\n';
				copy_buff[strlen(copy_buff)+1] = '\0';
				cnt_line = cnt_line < 0 ? 0 : (cnt_line-1);
#ifdef DEBUG_LOG_ENABLE				
				printf("loop :%d\t trackbuff:%d\t strlen of copybuff:%ld\n",loop,track_buff,strlen(copy_buff));
				printf("cnt_line : %d\n",cnt_line);	
#endif		
				ret_write = write(1, copy_buff,strlen(copy_buff));
				if(ret_write < 0)
				{
					perror("Write failed");
					printf("ret_write : %d\n\r",ret_write);
					exit(0);
				}
				track_buff = loop+1;
				memset(copy_buff,0,strlen(copy_buff));
			}
			
			if(cnt_line == 0)
			{
				ret_read = 0;
				break;
			}
		}

		if(ret_read == 0)
		{
			break;
		}
	}
	
#ifdef DEBUG_LOG_ENABLE
	sprintf(buff,"Lines : %d\t Words : %d\t Character : %d\n",cnt_line,cnt_word,cnt_char);
#endif
	/*
	sprintf(buff,"%d\t %s\n",cnt_line,argv[1]);
	ret_write = write(1,buff,strlen(buff)); 

	if(ret_write < 0)
	{
		perror("write failed");
		printf("ret_write : %d\n\r",ret_write);
		exit(0);
	}
	*/
	if(close(fd) < 0)
	{
		perror("Close failed");
		exit(0);
	}

	return 0;
}

