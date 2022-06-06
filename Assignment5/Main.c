#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"

void main() {
	BST bst;
	
	initBST(&bst);	
	insertBST(&bst, 5);
	insertBST(&bst, 2);
	insertBST(&bst, 8);
	insertBST(&bst, 1);
	insertBST(&bst, 4);
	print_ascii_tree(bst.root);
	printf("\n");

	insertBST(&bst, 9);
	print_ascii_tree(bst.root);
	printf("\n");

	/*insertBST(&bst, 5);
	print_ascii_tree(bst.root);
	printf("\n");*/

	printTreeInorder(&bst);
	printf("\n\n");

	insertBST(&bst, 10);
	insertBST(&bst, 11);

	printf("%d\n", findIndexNFromLast(&bst, 3));
	printf("%d\n", findIndexNFromLast(&bst, 6));
	
	destroyBST(&bst);
}

