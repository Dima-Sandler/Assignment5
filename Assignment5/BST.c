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

void insertBST(BST* bst, int value) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	CHECK_ALLOCATION(newNode);
	
	// initialize the new node
	newNode->left = newNode->right = NULL;
	newNode->element = value;
	
	insert(&bst->root, newNode);
}

void insert(TreeNode** root, TreeNode* leaf) {
	if (*root == NULL) // base case
		*root = leaf;
	else if (leaf->element <= (*root)->element)
		insert(&(*root)->left, leaf); // go left
	else
		insert(&(*root)->right, leaf); // go right
}

void printTreeInorder(BST* bst) {
	if (bst->root)
		inorder(bst->root);
	else
		puts("The tree is empty");
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d ", root->element);
		inorder(root->right);
	}
}

void destroyBST(BST* bst) {
	destroy(bst->root);
}

void destroy(TreeNode* root) {
	if (root) {
		destroy(root->left);
		destroy(root->right);
		free(root);
	}
}


