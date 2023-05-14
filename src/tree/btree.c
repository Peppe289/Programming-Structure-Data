#include <stdio.h>
#include <stdlib.h>

#include <item.h>
#include <btree.h>
#include <stack.h>

struct node
{
	Item value;
	struct node *left;
	struct node *right;
};

void free_tree(BTree btree) {
	if (isEmptyTree(btree))
		return;
	
	free_tree(btree->left);
	free_tree(btree->right);
	free(btree);
}

BTree newTree()
{
	return NULL;
}

int isEmptyTree(BTree btree)
{
	if (btree == NULL)
		return 1;
	return 0;
}

BTree buildTree(BTree left, BTree right, Item root)
{
	BTree btree = malloc(sizeof(struct node));
	btree->value = root;
	btree->left = left;
	btree->right = right;
	return btree;
}

Item getBTreeRoot(BTree btree)
{
	if (isEmptyTree(btree))
		return NULL;
	return (btree->value);
}

BTree getLeft(BTree btree)
{
	if (isEmptyTree(btree))
		return NULL;
	return (btree->left);
}
BTree getRight(BTree btree)
{
	if (isEmptyTree(btree))
		return NULL;
	return (btree->right);
}

void preOrder(BTree btree)
{
	if (!isEmptyTree(btree))
	{
		outputItem(btree->value);
		preOrder(btree->left);
		preOrder(btree->right);
	}
}

void postOrder(BTree btree)
{
	if (!isEmptyTree(btree))
	{
		postOrder(btree->left);
		postOrder(btree->right);
		outputItem(btree->value);
	}
}

void inOrder(BTree btree)
{
	if (!isEmptyTree(btree))
	{
		inOrder(btree->left);
		outputItem(btree->value);
		inOrder(btree->right);
	}
}

/**
 * Calcola quanti nodi sono presenti.
 * Ogni volta che la funzione riesce a fare una visita somma + 1;
 */
int NodeTree(BTree btree)
{
	if (isEmptyTree(btree))
		return 0;

	return 1 + NodeTree(btree->right) + NodeTree(btree->left);
}

/**
 * Calcola il percorso più lungo nell'albero.
 * 
 * Salva in una variabile statica la profondità
 * massima che riesce a raggiungere.
 */
static int heightTreeRec(BTree btree, int value)
{
	static int ret = 0;
	int temp;

	if (isEmptyTree(btree))
		return 0;

	value++;
	heightTreeRec(btree->right, value);
	heightTreeRec(btree->left, value);

	if (ret < value)
		ret = value;

	/**
	 * Si toglie dal calcolo la radice.
	 */
	return ret - 1;
}

int heightTree(BTree btree) {
	return heightTreeRec(btree, 0);
}

static void printLevel(BTree btree, int level) {

	if (isEmptyTree(btree) || level < 0)
		return;

	/**
	 * il livello 0 rappresenta la foglia del sottoalbero.
	 * E' ciò che vogliamo stampare.
	 */
	if (level == 0) {
		outputItem(btree->value);
		return;
	}

	/**
	 * Chiama ricorsivamente la funzione e arriva a stampare
	 * solo il valore del livello di quella profondità.
	 */
	printLevel(btree->left, level - 1);
	printLevel(btree->right, level - 1);
}

void levelvisit(BTree btree) {
	/**
	 * ATTENZIONE: la radice ha il livello di valore 0
	 */
	int level;
	int height = heightTree(btree);

	/**
	 * Questa forma iterativa fa il modo che stampa tutti i valori
	 * di un singolo livello, che rappresenta un sottoalbero
	 * di cui stampiamo ogni foglia.
	 * 
	 * E' quindi necessario selezionare il livello (noi li vogliamo tutti).
	 */
	for (level = 0; level <= height; ++level) {
		printLevel(btree, level);
		printf("\n");
	}
}

void preOrderIt(BTree btree) {
	
	Stack stack_data;
	BTree tempTree;

	if (isEmptyTree(btree))
		return;

	stack_data = newStack();

	/* push della radice */
	push(stack_data, btree);

	/**
	 * Partendo dalla radice il ciclo si ferma quando lo stack
	 * è vuoto.
	 * Quindi dopo il pop() con dimensione dello stack=1 sia il ramo
	 * sinistro, sia quello destro è NULL
	 * (quindi siamo arrivati all'ultima foglia). 
	 */
	while (!isEmptyStack(stack_data))
	{
		/**
		 * Prendi l'elemento in cima allo stack con top()
		 * e rimuovilo con pop().
		 */
		tempTree = top(stack_data);
		pop(stack_data);

		outputItem(tempTree->value);

		if (tempTree->right != NULL)
			push(stack_data, tempTree->right);

		if (tempTree->left != NULL)
			push(stack_data, tempTree->left);
	}

	free(stack_data);
}

void postOrderIt(BTree btree) {
	
	Stack stack_data;
	BTree tempTree;
	BTree last = NULL;
	BTree swipe = btree;

	if (isEmptyTree(btree)) {
		return;
	}

	stack_data = newStack();

	while(!isEmptyStack(stack_data) || swipe != NULL) {
		if (swipe != NULL) { 
			push(stack_data, swipe);
			swipe = swipe->left;
		} else {
			tempTree = top(stack_data);

			if ((tempTree->right != NULL) && (tempTree->right != last)) {
				swipe = tempTree->right;
			} else {
				outputItem(tempTree->value);
				last = top(stack_data);
				pop(stack_data);
			}
		}
	}

	free(stack_data);
}

void inOrderIt(BTree btree) {

	BTree current = btree;
	Stack stack_data;	

	if (isEmptyTree(btree)) {
		return;
	}

	stack_data = newStack();

	while (current != NULL || !isEmptyStack(stack_data)) {

		while (current != NULL) {
			push(stack_data, current);
			current = current->left;
		}

		current = top(stack_data);
		pop(stack_data);
		outputItem(current->value);

		current = current->right;
	}

	free(stack_data);
}