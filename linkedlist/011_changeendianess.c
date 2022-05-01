#include <stdio.h>


int changeendianess(int data)
{
    int result = 0;

    result = (((data & 0xFF000000) >> 24) | ((data & 0xFF0000) >> 8) | ((data & 0xFF00) << 8) | ((data & 0xFF) << 24));

    return result;
}

int main()
{
    int data = 0;
    int result = 0;
    printf("Enter the number : ");
    scanf("%d",&data);

    printf("Entered number in hex :%#x\n\r",data);

    printf("Result is  : %#x\n\r",changeendianess(data));

    return 0;
}