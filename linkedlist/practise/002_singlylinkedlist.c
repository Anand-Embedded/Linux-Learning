#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}node_t;


int Getnodelength(node_t *head)
{
    node_t *temp = head;
    int len = 0 ;

    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void insertnode_atbegin(node_t **head,int val)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));

    newnode->data = val;
    newnode->next = *head;
    *head = newnode;
}

void insertnode_atend(node_t **head,int val)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));

    newnode->data =  val;
    newnode->next =  NULL;

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

void insertnode_atpos(node_t **head,int pos,int val)
{
    int len  = Getnodelength(*head);

    if((pos < 1) || (pos > (len + 1)))
    {
        printf("INvalid pos !!!\n\r");
    }
    else
    {
        node_t *newnode = (node_t *)malloc(sizeof(node_t));
        newnode->data = val;
        node_t *temp = *head;
        node_t *prev = NULL;
        while(pos--)
        {
            if(pos == 0 )
            {
                prev->next = newnode;
                newnode->next = temp;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }    
}

void printnode(node_t *temp)
{
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
    node_t *slow,*fast;

    slow = fast = head;

    while((fast != NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Mid node is %d\n\r",slow->data);
}


node_t * Reveresenode(node_t *head)
{
    node_t *current = head;
    node_t *prev = NULL;
    node_t *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;   
    }

    return prev;

}

void deletenode_atbegin(node_t **head)
{
    node_t *temp = *head;

    if(*head ==  NULL)
    {
        printf("LInked List is EMpty\n\r");
        return;
    }
    *head = (*head)->next;
    free(temp);
}


void deletenode_atend(node_t **head)
{
    node_t *temp = *head;
    node_t *prev = NULL;

    if(*head == NULL)
    {
        return;
    }

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deletenode_atpos(node_t **head,int pos)
{
    node_t * temp = *head;
    int len = Getnodelength(*head);

    if((pos < 1) || (pos > (len+1)))
    {
        printf("Invalid Pos \n\r");
        return;
    }
    else
    {
        node_t *prev = *head;
        pos -=1;
        while(pos--)
        {
            prev = temp;
            temp = temp->next; 
        }
        prev->next = prev->next->next;
        free(temp);
    }
}

int main()
{
    node_t *head = NULL;

    insertnode_atend(&head,10);
    insertnode_atbegin(&head,20);
    insertnode_atend(&head,30);
    printnode(head);
    insertnode_atpos(&head,2,40);
    insertnode_atpos(&head,4,50);
    printnode(head);
    findmidnode(head);
    head = Reveresenode(head);
    printnode(head);
    deletenode_atpos(&head,3);
    printnode(head);

    deletenode_atbegin(&head);
    deletenode_atend(&head);
    printnode(head);
    deletenode_atpos(&head,2);
    printnode(head);
    return 0;
}