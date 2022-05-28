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

//void addNode(TreeNode* root, TreeNode* node) {
//	if (node->element <= root->element)
//		if (root->left == NULL) // stop condition
//			root->left = node;
//		else
//			addNode(root->left, node);
//	else
//		if (root->right == NULL) // stop condition
//			root->right = node;
//		else
//			addNode(root->right, node);
//}

void alt_addNode(TreeNode** root, TreeNode* node) {
	if (*root == NULL) { // stop conditon
		*root = node;
		return;
	}
	if (node->element <= (*root)->element)
		alt_addNode(&(*root)->left, node);
	else
		alt_addNode(&(*root)->right, node);
}

//void insertBST(BST* bst, int value) {
//	TreeNode* newNode = createNode(value);
//	
//	// check if the node is created
//	if (newNode)
//		// check if the tree is empty
//		if (bst->root == NULL)
//			bst->root = newNode;
//		else
//			addNode(bst->root, newNode);
//	else
//		puts("Failed to create a new node");
//}

void alt_insertBST(BST* bst, int value) {
	TreeNode* newNode = createNode(value);

	// check if the node is created
	if (newNode)
		alt_addNode(&bst->root, newNode);
	else
		puts("Failed to create a new node");
}

