#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;

typedef struct Tree
{
    Node* root;
} Tree;

void insert(Tree* tree, int value)
{
    Node* node = malloc(sizeof(Node));
    node -> data  = value;
    node -> left  = NULL;
    node -> right = NULL;

    if (tree -> root == NULL)
    {
        tree -> root = node;
    }
    else
    {
        Node* temp = tree -> root;
        while (temp != NULL)
        {
            if (value < temp -> data)
            {
                if (temp -> left == NULL)
                {
                    temp -> left = node;
                    return;
                }
                else
                {
                    temp = temp -> left;
                }
            }
            else
            {
                if (temp -> right == NULL)
                {
                    temp -> right = node;
                    return;
                }
                else
                {
                    temp = temp -> right;
                }
            }
        }
    }
}

void preorder(Node* node)
{
    if (node != NULL)
    {
        printf("%d\n", node -> data);
        preorder(node -> left);
        preorder(node -> right);
    }
}

void inorder(Node* node)
{
    if (node != NULL)
    {
        inorder(node -> left);
        printf("%d\n", node -> data);        
        inorder(node -> right);
    }
}

int main()
{
    Tree tree;
    tree.root = NULL;
    int arr[7] = {6, 3, 8, 2, 5, 1, 7};
    int i = 0;
    for (i = 0; i < 7; i++)
    {
        insert(&tree, arr[i]);
    }
    preorder(tree.root);
    return 0;
}