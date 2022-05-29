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

void initBST(BST*);
void insert(TreeNode**, TreeNode*);
void insertBST(BST*, int);
void inorder(TreeNode*);
void printTreeInorder(BST*);

#endif // !_BST_ADT_H


