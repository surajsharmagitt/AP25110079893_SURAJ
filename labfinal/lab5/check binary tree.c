#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create new node
struct node* create(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// Check if binary tree
int isBinaryTree(struct node *root)
{
    if(root == NULL)
        return 1;

    // In this structure, node already has max 2 children
    // So just recursively check subtrees

    return isBinaryTree(root->left) && isBinaryTree(root->right);
}

// Main
int main()
{
    struct node *root;

    // Example tree
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);

    if(isBinaryTree(root))
        printf("Given tree is a Binary Tree\n");
    else
        printf("Given tree is NOT a Binary Tree\n");

    return 0;
}
