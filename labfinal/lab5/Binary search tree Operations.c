#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create node
struct node* create(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// Insert
struct node* insert(struct node *root, int x)
{
    if(root == NULL)
        return create(x);

    if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// Find minimum (used in deletion)
struct node* findMin(struct node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

// Delete
struct node* deleteNode(struct node *root, int key)
{
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // Case 1: No child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else
        {
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Search
void search(struct node *root, int key)
{
    if(root == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if(key == root->data)
    {
        printf("Element found\n");
        return;
    }
    else if(key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Inorder traversal
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main
int main()
{
    struct node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: ");
    inorder(root);

    printf("\n");

    search(root, 40);

    root = deleteNode(root, 30);

    printf("After deletion: ");
    inorder(root);

    return 0;
}
