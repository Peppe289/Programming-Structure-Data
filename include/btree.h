#ifndef _BTREE_H_
#define _BTREE_H_

#include <item.h>

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);


void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree);

int cmpBTree(BTree data_1, BTree data_2);
Item max(BTree data);
int searchInLevel(BTree data, Item value);
void free_tree(BTree btree);

#endif /* _BTREE_H_ */