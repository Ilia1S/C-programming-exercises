// Необходимо реализовать функцию, которая печатает вид дерева сверху
// Print nodes in top view of binary tree

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct tree
{
    datatype key;
    struct tree *left, *right;
}tree;

tree* newNode(int );
void btUpView(tree *);
void deleteTree(tree **);

int main(void)
{
    tree *root = newNode(10);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->left->left = newNode(1);
    root->left->right = newNode(7);
    root->left->right->left = newNode(6);
    root->right = newNode(15);
    root->right->left = newNode(13);
    root->right->right = newNode(18);
    btUpView(root);
    deleteTree(&root);
    printf("\n");
    return 0;
}
tree* newNode(int key)
{
    tree* node = calloc(1, sizeof(tree));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void btUpView(tree *root)
{
    tree *head = root;
    int stack[30];
    int i = 0;
    if (root == NULL)
        return;
    while (root)
    {
        stack[i] = root->key;
        i++;
        root = root->left;
    }
    i--;
    while (i>=0)
    {
        printf("%d ", stack[i]);
        i--;
    }
    root = head;
    root = root->right;
    while (root)
    {
        printf("%d ", root->key);
        root = root->right;
    }
}
void deleteTree(tree **root)
{
    tree *temp;
    temp = *root;
    free(temp);
}
