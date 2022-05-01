#include <stdio.h>


int main()
{
    int a = 93, b = 53;

    int result = 0;

    result =  b ^ ((a ^ b) & -(a < b));
    printf("Result is :%d\n\r",result);


    return 0;
}