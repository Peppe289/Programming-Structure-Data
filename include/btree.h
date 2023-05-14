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

int NodeTree(BTree);
int heightTree(BTree);
void levelvisit(BTree);

/**
 * Visite iterative con stack
 */
void preOrderIt(BTree);
void postOrderIt(BTree);
void inOrderIt(BTree);

/* FREE */
void free_tree(BTree);
