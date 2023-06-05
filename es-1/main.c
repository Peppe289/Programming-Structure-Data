#include <stdio.h>
#include "btree.h"
#include <stdlib.h>

void inorder(BTree bt, int left) {

	if (isEmptyTree(bt)) {
		return;
	}

	if ((!getLeft(bt) && !getRight(bt) && left) || left == -1) {
		outputItem("(");
	}

	inorder(getLeft(bt), 1);
	outputItem(getBTreeRoot(bt));
	inorder(getRight(bt), 0);

	if (!getLeft(bt) && !getRight(bt) && !left) {
		outputItem(")");
	}
}

int main()
{
	BTree root;
	BTree left[4], right[4];

	right[3] = buildTree(NULL, NULL, "14");
	left[3] = buildTree(NULL, NULL, "11");
	right[2] = buildTree( NULL, NULL, "2");
	left[2] = buildTree( NULL, NULL, "6");
	right[1] = buildTree( NULL, NULL, "1");
	left[1] = buildTree( left[3], right[3], "+");
	right[0] = buildTree(left[2], right[2], "*");
	left[0] = buildTree(left[1], right[1], "-");
	root = buildTree(left[0], right[0], "/");

	inorder(root, -1);

	return 0;
}
