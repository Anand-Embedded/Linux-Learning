#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
}node_t;


node_t * getnewnode(int val)
{
    node_t * newnode =  (node_t *)malloc(sizeof(node_t));

    newnode->key = val;
    newnode->left =  NULL;
    newnode->right = NULL;

    return newnode;
}



node_t *  BST_insertnode(node_t *root,int val)
{
    if(root == NULL)
    {
        return getnewnode(val);
    }

    if(val > root->key)
    {
        root->right = BST_insertnode(root->right,val);
    }
    else if(val < root->key)
    {
        root->left = BST_insertnode(root->left,val);
    }

    return root;
}

void inorder(node_t *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d\t",root->key);
    inorder(root->right);
}

int getRightMin(node_t *root)
{
    node_t *temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->key;
}


node_t * BST_deletenode(node_t *root,int val)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(val > root->key)
    {
        root->right = BST_deletenode(root->right,val);
    }
    else if(val < root->key)
    {
        root->left = BST_deletenode(root->left,val);
    }
    else
    {
        if((root->left == NULL) && (root->right == NULL))
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
            int rightmin  = getRightMin(root->right);
            root->key = rightmin;
            root->right = BST_deletenode(root->right,rightmin);
        }
    }

    return root;

}

void inorder_decreasing(node_t *root)
{
    if(root ==  NULL)
        return;
    inorder_decreasing(root->right);
    printf("%d\t",root->key);
    inorder_decreasing(root->left);
}



int main()
{
    node_t *root = NULL;

    root = BST_insertnode(root,100);
    root = BST_insertnode(root,50);
    root = BST_insertnode(root,200);
    root = BST_insertnode(root,10);
    root = BST_insertnode(root,60);
    root = BST_insertnode(root,150);
    root = BST_insertnode(root,300);
    root = BST_insertnode(root,250);
    inorder(root);
    printf("\n");
    // root = BST_deletenode(root ,150);
    // inorder(root);
    // printf("\n");
    // root = BST_deletenode(root ,300);
    // inorder(root);
    // printf("\n");
    root = BST_deletenode(root ,200);
    inorder(root);
    printf("\n");
    inorder_decreasing(root);
    printf("\n");
    return 0;
}