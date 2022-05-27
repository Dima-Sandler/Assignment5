#include <stdio.h>
#include "BST.h"

void initBST(BST* bst) {
	bst->root = NULL;
}

TreeNode* createNode(int value) {
	TreeNode *treeNode = (TreeNode*)malloc(sizeof(TreeNode));
	
	if (treeNode) {
		treeNode->left = treeNode->right = NULL;
		treeNode->element = value;
	}
	else
		perror("Failed to allocate memory");

	return treeNode;
}

void insertBST(BST* bst, int value) {
	TreeNode* root = bst->root, * newNode = createNode(value);
	
	if (newNode == NULL) {
		puts("Failed to create a new node");
		return;
	}

	if (bst->root == NULL) {
		bst->root = newNode;
		return;
	}

	if (value <= root->element) 
		if(root->left == NULL) // stop condition
			root->left->element = value;
		else
			insertBST(root->left, value);

	if (value > root->element) 
		if (root->right == NULL) // stop condition
			root->right->element = value;
		else
			insertBST(root->right, value);
}

void a_insertBST(BST* bst, int value) {
	TreeNode* root = bst->root, * newNode = createNode(value);

	if (newNode == NULL) {
		puts("Failed to create a new node");
		return;
	}

	if (bst->root == NULL) {
		bst->root = newNode;
		return;
	}

	if (value <= root->element)
		insertBST(root->left, value);

	if (value > root->element)
		if (root->right == NULL) // stop condition
			root->right->element = value;
		else
			insertBST(root->right, value);
}