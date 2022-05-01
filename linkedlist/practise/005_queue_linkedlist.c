#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node_t;


node_t *front = NULL;
node_t *rear = NULL;

void queue_enqueue(int val)
{
    node_t *newnode = (node_t *)malloc(sizeof(newnode));

    newnode->data = val;
    newnode->next = NULL;

    if((front == NULL) && (rear == NULL))
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}


void queue_dequeue()
{
    if(front == NULL)
    {
        printf("Queue is empty\n\r");
    }
    else
    {

        node_t *temp = front;
        front = front->next;
        printf("popped data is :%d\n\r",temp->data);

        if(front == NULL)
            rear = NULL;
        
        free(temp);
    }
}

void Queue_display()
{
    int i = 0;
    node_t *temp = front;
    printf("Queue : ");

    while(temp != NULL)
    {
       printf("%d \t",temp->data);
       temp = temp->next;
    }
    printf("\n");
}

int main()
{
    queue_enqueue(10);
    queue_enqueue(20);
    queue_dequeue();
    queue_enqueue(30);
    queue_enqueue(40);
    Queue_display();

    return  0;
}