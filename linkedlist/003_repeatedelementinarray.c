#include <stdio.h>


int main()
{

    int arr[10] = {1,2,3,4,6,3,2,7,2,1};
    int freqcnt[10] = {0};
    int count = 0;
    int i = 0,j = 0;

    for(i = 0;i < 10; i++)
    {
        count = 1;
        for(j = i+1; j < 10; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                freqcnt[j] = 1;
            }
        }

        if(freqcnt[i] == 0)
        {
            freqcnt[i] = count;
            printf("Element :%d\t Occuerence :%d\r\n",arr[i],freqcnt[i]);
        }
    }

    return 0;

}
