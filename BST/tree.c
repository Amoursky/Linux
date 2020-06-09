#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;

struct Tree
{
    Node* root;
}

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

int main()
{
    return 0;
}