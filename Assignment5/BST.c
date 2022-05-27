#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

void initBST(BST* bst) {
	bst->root = NULL;
}

TreeNode* createNode(int value) {
	TreeNode *treeNode = (TreeNode*)malloc(sizeof(TreeNode));
	
	// check if malloc succeeded
	if (treeNode) {
		treeNode->left = treeNode->right = NULL;
		treeNode->element = value;
	}
	else
		perror("Failed to allocate memory");

	return treeNode;
}

addNode(TreeNode* root, TreeNode* node) {
	if (node->element <= root->element)
		if (root->left == NULL) // stop condition
			root->left = node;
		else
			addNode(root->left, node);
	else if (node->element > root->element)
		if (root->right == NULL) // stop condition
			root->right = node;
		else
			addNode(root->right, node);
}

a_addNode(TreeNode** root, TreeNode* node) {
	if (*root == NULL)
	{

	}
}



void a_insertBST(BST* bst, int value) {
	TreeNode* newNode = createNode(value);

	// check if the node is created
	if (newNode)
		a_addNode(&bst->root, newNode);
	else
		puts("Failed to create a new node");
}

void insertBST(BST* bst, int value) {
	TreeNode* newNode = createNode(value);
	
	// check if the node is created
	if (newNode)
		// check if the tree is empty
		if (bst->root == NULL)
			bst->root = newNode;
		else
			addNode(bst->root, newNode);
	else
		puts("Failed to create a new node");
}