#include <stdio.h>


#define MY_SIZEOF(x)  ((char *)(&x+1) - (char *)(&x))

int main(int arg, int *argc)
{
    int input_data = 0xA55A;
    int result = 0;

    result = (((input_data & 0x55555555) << 1) | ((input_data & 0xAAAAAAAA) >> 1)); 

    printf("Result  : %x\n\r",result); 
    printf("Result  : %d\n\r",result); 

    return 0;
}