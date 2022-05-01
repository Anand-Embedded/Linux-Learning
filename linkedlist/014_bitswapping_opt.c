#include <stdio.h>


#define MY_SIZEOF(x)  ((char *)(&x+1) - (char *)(&x))

int main(int arg, int *argc)
{
    int input_data = 0xC33C;
    int result = 0;

    result = (((input_data & 0x33333333) << 2) | ((input_data & 0xCCCCCCCC) >> 2)); 

    printf("Result  : %x\n\r",result); 
    printf("Result  : %d\n\r",result); 

    return 0;
}