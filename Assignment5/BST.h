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
void destroy(TreeNode*);
void destroyBST(BST*);
int findIndexNFromLast(BST*, int);
int sameHeightLeaves(BST*);
int checkUtil(TreeNode*, int, int*);
TreeNode* find(TreeNode*, int*);

#endif // !_BST_ADT_H


