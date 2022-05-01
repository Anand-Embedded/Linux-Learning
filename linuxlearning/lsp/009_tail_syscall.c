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
	int cnt =0;
	int loop;
	char buff[4096]={0};
	int tail_index[4096];
	int option = 11;
	int roll_over = 0 ;
	int seek_pos;
	

	if(argc < 2)
	{
		printf("Command Usage : %s  <file> [number of line]\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	else if(argc == 3)
	{
		option = atoi(argv[2]) + 1;
#ifdef DEBUG_LOG_ENABLE
		printf("option : %d\n\r",option);
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
	while((ret_read = read(fd,buff,4096)) > 0)
	{
		for(loop = 0; loop < ret_read; loop++)
		{
			if(buff[loop] == NEW_LINE)
			{
				//increment the line no
				cnt_line++;

				//Once we hit the new line character then check for next character should not be SPACE_BAR to consider for word cnt 
				//"hELLO WORLD "
				//"        "
				if(buff[loop+1] != SPACE_BAR)
				//increment the word no
					cnt_word++;
				
				//increment the character no
				cnt_char++;
				
				//update the character number, when we hit the new line
				tail_index[cnt++] = cnt_char;
#ifdef DEBUG_LOG_ENABLE
				printf("tail : %d\tcnt: %d\n", tail_index[cnt-1],cnt-1);
#endif
				//check the cnt not equal to zero and roll over the buffer 
				if(((cnt % option) == 0) && (cnt != 0))
				{
#ifdef DEBUG_LOG_ENABLE
					printf("\n roll_over happened : %d\tcnt: %d\n", tail_index[cnt-1],cnt-1);
#endif
					//Mention the roll over event and at this incident the cnt index value will be stored for  last 10 line 
					roll_over=1;

					//reset the cnt 
					cnt = 0;
				}
				

			}
			//check for SPACE_BAR and next character should not be SPACE_BAR and NEW_LINE
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
	for(int i= 0;i	< option;i++)
		printf("arr[%d]:%d\n",i,tail_index[i]);
#endif
	if(roll_over == 1)
	{
		//Bring the file pointer to the starting of the file
		seek_pos = lseek(fd,0,SEEK_SET); 
		
		//move the file pointer to the last 10 line
		seek_pos = lseek(fd,tail_index[cnt],SEEK_SET);
	}	
	else
		//Bring the file pointer to the starting of the file
		seek_pos = lseek(fd,0,SEEK_SET); 
#ifdef DEBUG_LOG_ENABLE
	printf("Seek pos : %d\n",seek_pos);
#endif	

	while((ret_read = read(fd,buff,4096)) > 0)
	{
#ifdef DEBUG_LOG_ENABLE
		printf("ret_read : %d\n",ret_read);
#endif
		ret_write = write(1,buff,ret_read); 

		if(ret_write < 0)
		{
			perror("write failed");
			printf("ret_write : %d\n\r",ret_write);
			exit(0);
		}
	}
#ifdef DEBUG_LOG_ENABLE
	printf("ret_read : %d\n",ret_read);
#endif
	if(ret_read < 0)
	{
		perror("Read failed");
		printf("ret_read : %d\n\r",ret_read);
		exit(0);
	}
	
	if(close(fd) < 0)
	{
		perror("Close failed");
		exit(0);
	}

	return 0;
}

