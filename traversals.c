#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}
// Pre-order: Root -> Left -> Right
void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
// In-order: Left -> Root -> Right
void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
// Post-order: Left -> Right -> Root
void postOrder(struct Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    printf("Inserting elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insert(root, values[i]);
    }
    printf("\n");

    printf("\n=== Binary Tree Traversals ===\n");

    printf("\nPre-order  (Root -> Left -> Right): ");
    preOrder(root);
    printf("\n");

    printf("In-order   (Left -> Root -> Right): ");
    inOrder(root);
    printf("\n");

    printf("Post-order (Left -> Right -> Root): ");
    postOrder(root);
    printf("\n");

    return 0;
}
