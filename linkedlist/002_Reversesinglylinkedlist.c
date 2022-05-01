#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}node_t;


int Getnodelenght(node_t *temp)
{
    int len = 0;

    if(temp == NULL)
    {
        return 0;
    }
    else
    {
        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
}


void insertnodeat_begin(node_t **head,int val)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));

    if(newnode == NULL)
    {
        printf("Memory is not allocated\n\r");
        return;
    }
    newnode->data = val;
    newnode->next = *head;
    *head = newnode;
}

void insertnodeat_end(node_t **head,int val)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));

    if(newnode == NULL)
    {
        printf("Memory is not allocated\n\r");
        return;
    }

    newnode->data = val;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        node_t *temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void PrintAllNodes(node_t *temp)
{
    printf("Linked List : ");
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n\r");
}

void deletenodeat_Begin(node_t **head)
{
    node_t *temp = *head;

    if(*head == NULL)
    {
        printf("Cant be delete since, there is no node in the linked list\n\r");
    }
    else
    {
        *head = (*head)->next;
        free(temp);
    }
}

void deletenodeat_end(node_t **head)
{
    node_t *temp  = *head;

    if(*head == NULL)
    {
        printf("Cant be delete since, there is no node in the linked list\n\r");
    }
    else
    {
        node_t *prev = *head;
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next; 
        }

        if(temp == prev)
        {
            printf("List has one node\n\r");
            free(*head);
            *head = NULL;
        }
        else
        {
            prev->next = NULL;
            free(temp);
        }
    }
}

void reversenode(node_t *head)
{
    node_t *current , *next, *prev = NULL;

    current  =  head;
    
    while(current != NULL)
    {
	    next = current->next;
        current->next =  prev;
        prev = current;
        current  = next;
    }

    PrintAllNodes(prev);
}

void findmidnode(node_t *temp)
{
    node_t *slow,*fast;

    slow = fast = temp;
    
    while((fast != NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("mode node : %d\n\r",slow->data);
}


int main()
{

    node_t *head = NULL;

    insertnodeat_begin(&head,10);
    insertnodeat_end(&head,20);
    PrintAllNodes(head);
    insertnodeat_begin(&head,70);
    PrintAllNodes(head);
    insertnodeat_end(&head,30);
    insertnodeat_end(&head,40);
    insertnodeat_end(&head,50);
    PrintAllNodes(head);
    findmidnode(head);
    deletenodeat_end(&head);
    PrintAllNodes(head);
    reversenode(head);
    findmidnode(head);
    deletenodeat_end(&head);
    PrintAllNodes(head);
    printf("\nTotal length of node :%d\n\r",Getnodelenght(head));
    return 0;
}
