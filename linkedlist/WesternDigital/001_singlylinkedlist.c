#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}node_t;



int insertnode_atbegin(node_t **head,int val)
{
    node_t *newnode = (node_t *) malloc(sizeof(node_t));

    if(newnode == NULL)
        return -1;

    newnode->data = val;
    newnode->next = *head;
    *head = newnode;

    return 0;
}


int insertnode_atend(node_t **head,int val)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));

    if(newnode == NULL)
    {
        printf("Memory not allocated!!\n\r");
        return -1;
    }

    newnode->data = val;
    newnode->next = NULL;

    node_t *temp = *head;

    if(*head == NULL) 
    {
        *head = newnode;
        return 0 ;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    } 
}


void deletenode_atbegin(node_t **head)
{
    node_t *temp = *head;

    if(*head ==  NULL)
        return;

    *head = temp->next;
    free(temp);
    temp = NULL;
}



void deletenode_atend(node_t **head)
{
    if(*head == NULL)
    {
        return;
    }

    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        node_t *temp = *head;
        node_t *prev = *head;

        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        free(temp);
        prev->next  = NULL;
    }
}


int findlengthofnode(node_t *temp)
{
    int length = 0;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
    
}


void printnodes(node_t *head)
{
    node_t *temp = head;

    printf("Linked List : ");

    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n\r");
}

void findmidnode(node_t *head)
{
    node_t *slow, *fast;
    slow = fast = head;

    while((fast != NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next; 
    }

    printf("Mid node data : %d\n\r",slow->data);
}

node_t * reversenode(node_t **head)
{
    node_t *current  = *head;
    node_t *prev  = NULL;
    node_t *next;

    next = current;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    node_t *head = NULL;

    deletenode_atbegin(&head);
    deletenode_atend(&head);
    insertnode_atbegin(&head,10);    
    insertnode_atbegin(&head,20);
    insertnode_atend(&head,100);  
    insertnode_atend(&head,1200);
    insertnode_atbegin(&head,30);
    printnodes(head);
    findmidnode(head);
    head = reversenode(&head);
    printnodes(head);
    printf("Length is :%d\n\r",findlengthofnode(head));
    deletenode_atbegin(&head);
    printnodes(head);
    deletenode_atend(&head);
    head = reversenode(&head);
    printnodes(head);
    findmidnode(head);
    printf("Length is :%d\n\r",findlengthofnode(head));
    return 0;
}