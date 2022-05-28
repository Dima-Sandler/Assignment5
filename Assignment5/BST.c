#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

#define CHECK_ALLOCATION(ptr)\
	do\
		if (!ptr) {\
			perror("Failed to allocate memory");\
			exit(1);\
		}\
	while (0)

void initBST(BST* bst) {
	bst->root = NULL;
}
void addLeaf(TreeNode** root, TreeNode* node) {
	if (*root == NULL) // base case
		*root = node;
	else if (node->element <= (*root)->element)
		addLeaf(&(*root)->left, node); // go left
	else
		addLeaf(&(*root)->right, node); // go right
}
void insertBST(BST* bst, int value) {
	TreeNode* newLeaf = (TreeNode*)malloc(sizeof(TreeNode));
	CHECK_ALLOCATION(newLeaf);
	
	// initialize the new node
	newLeaf->left = newLeaf->right = NULL;
	newLeaf->element = value;
	
	addLeaf(&bst->root, newLeaf);
}