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

node_t * reversenode(node_t *head)
{
    node_t *current,*prev,*next;

    prev = NULL;
    current = head;

    while(current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev  = current;
        current  = next;
    }

    PrintAllNodes(prev);
    return prev;

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


void insertnode_atposition(node_t *head,int pos,int val)
{
    node_t *prev,*current;
    current = head;
    int size = Getnodelenght(head);

    if((pos < 1) || (pos > (size + 1)))
    {
        printf("Invalid position is entered\n\r");
    }
    else
    {
        while(pos--)
        {
            if(pos == 0)
            {
                node_t *newnode = (node_t *)malloc(sizeof(node_t));

                newnode->data = val;
                newnode->next = current;
                prev->next = newnode;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
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
    insertnode_atposition(head,2,500);
    PrintAllNodes(head);
    head = reversenode(head);
    findmidnode(head);
    deletenodeat_end(&head);
    PrintAllNodes(head);
    findmidnode(head);
    deletenodeat_end(&head);
     insertnode_atposition(head,3,600);
     insertnode_atposition(head,5,900);
  
    PrintAllNodes(head);
         findmidnode(head);   
    printf("\nTotal length of node :%d\n\r",Getnodelenght(head));
    return 0;
}
