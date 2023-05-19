#ifndef _LIBS_BST_
#define _LIBS_BST_

#include <item.h>

typedef struct node *BST;

BST newBST();
int isEmptyBST(BST);
BST getLeft(BST);
BST getRight(BST);
Item getItem(BST);
Item search(BST, Item);
Item min(BST);
Item max(BST);
void insertBST(BST *, Item);
Item deleteBST(BST *, Item);

#if 0
void printPerLevel(BST);
#endif

int searchInLevel(BST bst, Item el);
int cmpbst(BST data_1, BST data_2);

#endif /* _LIBS_BST_ */