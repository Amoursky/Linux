#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int date;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;

struct Tree
{
    Node* root;
}


int main()
{
    return 0;
}