#include <stdio.h>
#include "btree.h"
#include <stdlib.h>

// scrivere *in questo file*:
// - heightAndNumNodes
// - preorder

int NodeHeight(BTree bt, int *array)
{
	int right, left;

	if (isEmptyTree(bt))
		return 0;

	array[1] += 1;

	left = NodeHeight(getLeft(bt), array);
	right = NodeHeight(getRight(bt), array);

	array[0] = left > right ? left : right;

	return array[0] + 1;
}

int *heightAndNumNodes(BTree bt)
{

	int *array;
	array = malloc(2 * sizeof(int));

#define var_name(x) #x

	if (array == NULL)
	{
		fprintf(stderr, "\n%s(): Errore nell'allocazione di memoria per %s\n",
				__func__, var_name(array));
	}

#undef var_name

	if (isEmptyTree(bt))
	{
		/**
		 * Secondo l'oracolo quando l'albero è vuoto
		 * ritorna i valori 0 - 0 e non NULL.
		 */
		array[0] = 0;
		array[1] = 0;
		return array;
	}

	/**
	 * indice 0: altezza dell'albero.
	 */
	array[0] = -1;
	/**
	 * indice 1: numero di nodi
	 */
	array[1] = NodeHeight(bt, array);

	return array;
}

/**
 * @stack: stack fittizio per salvare i nodi dei sottoalberi.
 *
 * @top: helper per lo stack.
 *
 * @array: mi serve creare la memoria dello stack con dimensione
 * il numero di nodi, valore presente in indice 1.
 */
void preorder(BTree bt)
{
	BTree *stack;
	int *array;
	int top = 0;

	if (isEmptyTree(bt))
	{
		return;
	}

	array = malloc(2 * sizeof(int));
	/**
	 * indice 0: altezza dell'albero.
	 * la radice vale 0;
	 */
	array[0] = -1;
	/**
	 * indice 1: numero di nodi
	 */
	array[1] = 0;
	NodeHeight(bt, array);

	stack = malloc(array[1] * sizeof(BTree));

	/**
	 * Push nello stack
	 */
	stack[top] = bt;

	while (top >= 0)
	{

		BTree tmp = stack[top];
		top--;

		outputItem(getBTreeRoot(tmp));

		if (getRight(tmp) != NULL)
		{
			stack[top + 1] = getRight(tmp);
			top++;
		}

		if (getLeft(tmp) != NULL)
		{
			stack[top + 1] = getLeft(tmp);
			top++;
		}
	}

	free(stack);
	free(array);
}

void printHeightNumNodesAndPreorder(BTree bt)
{
	printf("Albero:\n");
	printTree(bt);
	int *hn = heightAndNumNodes(bt);
	if (hn)
		printf("Altezza albero: %d\nNumero nodi albero: %d\n", hn[0], hn[1]);
	printf("Visita preorder iterativa: ");
	preorder(bt);
	printf("\n\n");
}

int main()
{
	// printHeightNumNodesAndPreorder(aTree);
	// da scrivere

	int value = 2;
	int bruh[] = {7, 3, 9, 1, 5};

	BTree aTree_1 = newTree();

	BTree aTree_2 = buildTree(NULL, NULL, &value);

	BTree aTree_3_right_2 = buildTree(NULL, NULL, &bruh[4]);
	BTree aTree_3_left_2 = buildTree(NULL, NULL, &bruh[3]);
	BTree aTree_3_right_1 = buildTree(aTree_3_left_2, aTree_3_right_2, &bruh[2]);
	BTree aTree_3_left_1 = buildTree(NULL, NULL, &bruh[1]);
	BTree aTree_3_root = buildTree(aTree_3_left_1, aTree_3_right_1, &bruh[0]);

	BTree aTree_4 = newRandomTree(8);

	printHeightNumNodesAndPreorder(aTree_1);
	printHeightNumNodesAndPreorder(aTree_2);
	printHeightNumNodesAndPreorder(aTree_3_root);
	printHeightNumNodesAndPreorder(aTree_4);

	return 0;
}
