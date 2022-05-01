#include <stdio.h>

int main()
{
    int data = 0xa55a;
    int result = 0;


    result = ((data & 0x55555555) << 1) | ((data & 0xAAAAAAAA) >> 1 );

    printf("result : %#x\n\r",result);

    return 0;
}