#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
// Case 1: Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}
// Case 2: Check if tree is BST
int isBSTHelper(struct Node* root, long long minVal, long long maxVal) {
    if (root == NULL) return 1;
    if (root->data <= minVal || root->data >= maxVal) return 0;
    return isBSTHelper(root->left, minVal, root->data) &&
           isBSTHelper(root->right, root->data, maxVal);
}
int isBST(struct Node* root) {
    return isBSTHelper(root, LLONG_MIN, LLONG_MAX);
}
// In-order print to display tree contents
void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
int main() {
    struct Node* root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;
    // Case 1: Construct BST
    printf("=== Case 1: Constructing Binary Search Tree ===\n");
    printf("Inserting elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insert(root, values[i]);
    }
    printf("\n");

    printf("In-order of constructed BST: ");
    inOrder(root);
    printf("\n");
    // Case 2: Check if BST
    printf("\n=== Case 2: Checking if Tree is a BST ===\n");
    if (isBST(root))
        printf("Result: The tree IS a valid Binary Search Tree.\n");
    else
        printf("Result: The tree is NOT a Binary Search Tree.\n");
    // Test with invalid BST
    printf("\nTesting with an invalid tree...\n");
    struct Node* invalidRoot = newNode(10);
    invalidRoot->left = newNode(5);
    invalidRoot->right = newNode(15);
    invalidRoot->right->left = newNode(6); // violates BST property

    if (isBST(invalidRoot))
        printf("Result: The tree IS a valid Binary Search Tree.\n");
    else
        printf("Result: The tree is NOT a Binary Search Tree.\n");

    return 0;
}
