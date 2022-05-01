#include <stdio.h>

int main()
{
    int data = 0x12345678;

    int result =0 ;
    int mask = 0;
    int pos = 0;

    printf("Enter the position : ");
    scanf("%d",&pos);
    printf("%d\n\r",pos);


    mask =  (1 << (pos + 1));
    mask = mask - 1;

    result = data & mask;
    printf("Result is :%#x\n\r",result);


    return 0 ;
}
