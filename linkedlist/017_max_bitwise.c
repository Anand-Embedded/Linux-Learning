#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int a ,b ;
    int result = 0;

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    result = b ^ ((a ^ b) & -(a > b)); //-1 in 0xFFFFFFFF
    printf("Result : %d\n\r",result);
}