#include <stdio.h>


#define MAX_STACK_SIZE 4


int stackarr[MAX_STACK_SIZE] = {0};
int stackpointer = -1;


void stack_push(int val)
{
    if(stackpointer == (MAX_STACK_SIZE -1 ))
    {
        printf("Stack is Full\n\r");
    }
    else
    {
        stackpointer++;
        stackarr[stackpointer] = val;
    }
}


void stack_pop(void)
{
    if(stackpointer == -1)
    {
        printf("Stack is empty\n\r");
    }
    else
    {
        printf("popped data is :%d\n\r",stackarr[stackpointer]);
        stackpointer--;
    }
}

void stack_display(void)
{
    int i = 0;
    printf("Stack : ");
    for(i = 0;i <= stackpointer;i++)
    {
        printf("%d \t",stackarr[i]);
    }
    printf("\n");
}

int main()
{
    stack_push(10);   
    stack_push(20);
    stack_push(30);   
    stack_push(40);
    stack_push(50);   
    stack_display();
    stack_pop();
    stack_pop();
    stack_display();
    stack_pop();

    return  0;
}