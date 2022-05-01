#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
}node_t;


node_t * Generatenewnode(node_t *root,int val)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));

    newnode->key = val;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}


node_t * insertnewnode(node_t *root,int val)
{
    if(root == NULL)
    {
        return Generatenewnode(root,val);
    }

    if(val > root->key)
    {
        root->right = insertnewnode(root->right,val);
    }
    else if(val < root->key)
    {
        root->left = insertnewnode(root->left,val);
    }

    return root;
}

void inordertraverse(node_t *root)
{
    if(root == NULL)
    {
        return ;
    }

    inordertraverse(root->left);
    printf("%d\t",root->key);
    inordertraverse(root->right);
}


int findrightmin(node_t *temp)
{
    while(temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->key;
}



node_t * deletenode(node_t *root,int val)
{

    if(root == NULL)
    {
        return NULL;
    }

    if(val > root->key)
    {
        root->right = deletenode(root->right,val);
    }
    else if (val < root->key)
    {
        root->left = deletenode(root->left,val);
    }
    else
    {
        if((root->left ==  NULL) && (root->right == NULL))
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            node_t *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            node_t *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            int rightmin = findrightmin(root->right);
            root->key = rightmin;
            root->right = deletenode(root->right,rightmin);
        }
    }

    return root;

}




int main()
{
    node_t *root = NULL;

    root = insertnewnode(root,100);
    root = insertnewnode(root,10);
    root = insertnewnode(root,150);
    root = insertnewnode(root,50);
    root = insertnewnode(root,60);
    root = insertnewnode(root,200);
    root = insertnewnode(root,300);
    root = insertnewnode(root,250);
    inordertraverse(root);
    printf("\n");
    root = deletenode(root,200);
    inordertraverse(root);
    printf("\n");
    return 0;
}