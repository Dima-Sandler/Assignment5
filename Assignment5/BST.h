#ifndef _BST_ADT_H
#define _BST_ADT_H

typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;

#endif // !_BST_ADT_H

void initBST(BST* bst);
TreeNode* createNode();
void insertBST(BST* bst, int value);
void printTreeInorder(BST* bst);
void inorder(BST* bst);
