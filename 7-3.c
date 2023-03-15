// Дано двоичное дерево. Требуется реализовать функцию, которая по ключу возвращает
// адрес соседнего элемента - брата. Если такого ключа нет или у узла нет брата,
// то необходимо вернуть 0.

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct tree
{
    datatype key;
    struct tree *left, *right;
    struct tree *parent;
}tree;

tree* newNode(int );
tree * findBrother(tree *root, int key);
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
    findBrother(root, 1);
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
tree * findBrother(tree *root, int key)
{
    if (root == NULL || root->key == key)
        return 0;
    if (root->left && root->left->key == key)
    {
        if (root->right)
        {
            printf("имеет брата %d", root->right->key);
            return 0;
        }
        else if (!root->right)
        {
            printf("0");
            return 0;
        }
    }
    if (root->right && root->right->key == key)
    {
        if (root->left)
        {
            printf("имеет брата %d", root->left->key);
            return 0;
        }
        else if (!root->left)
        {
            printf("0");
            return 0;
        }
    }
    tree *temp = findBrother(root->left, key);
    if (temp)
        return temp;
    temp = findBrother(root->right, key);
    return temp;
}
void deleteTree(tree **root)
{
    tree *temp;
    temp = *root;
    free(temp);
}
