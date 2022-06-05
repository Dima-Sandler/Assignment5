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

int findIndexNFromLast(BST* bst, int N) {
	if (bst->root == NULL)
		return 0;
	
	return reversed(findLast(bst->root), N);
}

TreeNode* findLast(TreeNode* root) {
	if (root->right == NULL) // base case
		return root;
	else
		return findLast(root->right);
}

int reverse(TreeNode* root, int N) {
	if (N == 1) // base case
		return root->element;

	return reverse(root, N - 1);
}

int sameHeightLeaves(BST* bst) {
	if (bst->root == NULL)
		return 0;
}

int checkUtil(TreeNode* root, int level, int* leafLevel){
	// Base case
	if (root == NULL)
		return 1;

	// If a leaf node is encountered
	if (root->left == NULL && root->right == NULL)
	{
		// When a leaf node is found first time
		if (*leafLevel == 0)
		{
			*leafLevel = level; // Set first found leaf's level
			return 1;
		}

		// If this is not first leaf node, compare its level with
		// first leaf's level
		return (level == *leafLevel);
	}

	// If this node is not leaf, recursively check left and right subtrees
	return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}

/* The main function to check if all leafs are at same level.
   It mainly uses checkUtil() */
int check(TreeNode* root){
	int level = 0, leafLevel = 0;
	return checkUtil(root, level, &leafLevel);
}