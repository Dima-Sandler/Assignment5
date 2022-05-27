#include <stdio.h>
#include "BST.h"

void initBST(BST* bst) {
	bst->root = NULL;
}

TreeNode* createNode() {
	int temp = (TreeNode*)calloc(sizeof(TreeNode));
	if (!temp)
		exit(1);
	return temp;
}

void insertBST(BST* bst, int value) {
	if (bst->root == NULL)
		return;

	if (value <= bst->root->element) 
		if (bst->root->left->left == NULL)
			bst->root->left->element = value;
		else
			insertBST(bst->root->left, value);

	if (value > bst->root->element)
		if (bst->root->right == NULL)
			bst->root->right->element = value;
		else
			insertBST(bst->root->right, value);
}

