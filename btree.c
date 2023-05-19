#include <stdio.h>
#include <stdlib.h>

#include <item.h>
#include <btree.h>

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

int cmpBTree(BTree data_1, BTree data_2)
{
    int right = 0, left = 0;

    if (isEmptyTree(data_1) && isEmptyTree(data_2))
    {
        /**
         * Controlla se entrambi gli alberi sono vuoti
         * (o finiti in caso di sottoalberi).
         *
         * I valori devono essere uguali ed entrambi true.
         */
        return 1;
    }
    else if (isEmptyTree(data_1) || isEmptyTree(data_2))
    {
        /**
         * I valori non sono coerenti. Un albero ha finito e l'altro no.
         * Gli alberi non sono uguali.
         */
        return 0;
    }

    /**
     * Controlla se i valori contenuti sono uguali.
     */
    if (cmpItem(data_1->value, data_2->value) == 0)
    {
        /**
         * Se i valori sono uguali controlla il nodo sinisto
         * e il nodo destro e il loro esito.
         *
         * Se gli alberi non sono ugali verrà restituito 0.
         */
        left = cmpBTree(data_1->left, data_2->left);
        right = cmpBTree(data_1->right, data_2->right);
    }

    /**
     * Se gli alberi sono uguali entrambi i valori sono true,
     * quindi restituirà 1 altrimenti 0.
     */
    return right && left;
}

Item max(BTree data) {

	Item max_left;
	Item max_right;
	Item tmp = NULL;

	if (isEmptyTree(data))
		return NULL;

	/**
	 * Se un ramo è NULL allora confronta con il valore attuale.
	 * Sarà un confronto inutile, ma evita errori di memoria
	 * e il risultato è comunque corretto.
	 */
	if (data->right != NULL)
		max_right = max(data->right);
	else
		max_right = data->value;

	if (data->left != NULL)
		max_left = max(data->left);
	else
		max_left = data->value;

	/**
	 * Se il valore è maggiore di 0 allora nel ramo
	 * destro c'è un valore maggiore, altrimenti
	 * nel ramo sinistro.
	 */
	if (cmpItem(max_right, max_left) > 0) {
		tmp = max_right;
	} else {
		tmp = max_left;
	}

	/**
	 * Confronta il valore dei rami con il valore attuale.
	 * 
	 * Con questa forma se è minore di 0 allora il valore attuale è meggiore.
	 */
	if (cmpItem(tmp, data->value) < 0) {
		tmp = data->value;
	}

	/**
	 * Torna l'eventuale valore aggiornato.
	 */
	return tmp;
}


int searchInLevel(BTree data, Item value) {

	int find_left;
	int find_right;

	/**
	 * L'albero è finito ma non abbiamo trovato valori.
	 */
	if (isEmptyTree(data))
		return 0;

	/**
	 * Chiudi le ricorsioni e porta il valore indietro.
	 * Il return finale si occupa di capire se il valore è stato trovato.
	 */
	if (cmpItem(data->value, value) == 0)
		return 1;
	
	find_left = searchInLevel(data->left, value);
	find_right = searchInLevel(data->right, value);

	/**
	 * Controlla i rami di destra e i rami di sinistra
	 * e fai un or. se esiste da qualche parte torna true.
	 */
	return find_left || find_right;
}