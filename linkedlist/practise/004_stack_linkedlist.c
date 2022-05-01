#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node_t;


void stack_push(node_t **head,int val)
{
    node_t *newnode = (node_t *)malloc(sizeof(newnode));

    newnode->data = val;
    newnode->next = *head;
    *head = newnode;
}


void stack_pop(node_t **head)
{
    if(*head == NULL)
    {
        printf("Stack is empty\n\r");
    }
    else
    {

        node_t *temp = *head;
        printf("popped data is :%d\n\r",temp->data);

        (*head) = (*head)->next;
        free(temp);
    }
}

void stack_display(node_t *head)
{
    int i = 0;
    node_t *temp = head;
    printf("Stack : ");

    while(temp != NULL)
    {
       printf("%d \t",temp->data);
       temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node_t *head = NULL;
    stack_push(&head,10);   
    stack_push(&head,20);
    stack_push(&head,30);   
    stack_push(&head,40);
    stack_push(&head,50);   
    stack_display(head);
    stack_pop(&head);
    stack_pop(&head);
    stack_pop(&head);
    stack_display(head);
    stack_pop(&head);
    stack_pop(&head);
    stack_pop(&head);

    return  0;
}