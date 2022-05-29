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

void addLeaf(TreeNode** root, TreeNode* leaf) {
	if (*root == NULL) // base case
		*root = leaf;
	else if (leaf->element <= (*root)->element)
		addLeaf(&(*root)->left, leaf); // go left
	else
		addLeaf(&(*root)->right, leaf); // go right
}

void insertBST(BST* bst, int value) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	CHECK_ALLOCATION(newNode);
	
	// initialize the new node
	newNode->left = newNode->right = NULL;
	newNode->element = value;
	
	addLeaf(&bst->root, newNode);
}

void printTreeInorder(BST* bst) {
	inorder(bst->root);
}

void inorder(TreeNode* node) {
	if (node != NULL) {
		inorder(node->left);
		printf("%d", node->element);
		inorder(node->right);
	}
}