#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MY_SIZEOF(x)  ((char *)(&x+1) - (char *)(&x))
#define INTBIT(x)  ((MY_SIZEOF(x)) * (8))

#define ROTATE_LEFT(xdata,pos)   ((xdata << pos)  | (data >> (INTBIT(xdata) - pos))) 
#define ROTATE_RIGHT(xdata,pos)   ((xdata >> pos)  | (data << (INTBIT(xdata) - pos))) 

int main(int argc, char * argv[])
{
    int data = 0 ;
    int pos = 0;

    data = atoi(argv[1]);
    pos = atoi(argv[2]);

    printf("Data : %#x\t pos :%d\t%ld\n\r",data,pos,INTBIT(data));
    printf("Rotate Left : %#x\n\r",ROTATE_LEFT(data,pos));
    printf("Rotate Right : %#x\n\r",ROTATE_R___(data,pos));


    return 0 ;
}