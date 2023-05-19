#include <bst.h>
#include <item.h>
#include <stdio.h>

int main(){
	int a [] = {20, 10, 30, 5, 15, 25, 40, 3, 6, 35};
	int b [] = {20, 10, 30, 5, 15, 25, 40, 3, 35};
	BST bst = newBST();
	BST bst2 = newBST();
	int i;
	Item el;
	int ret;

	for(i=0; i<(int)(sizeof(a)/sizeof(int)); i++){
		insertBST(&bst, &a[i]);
	}

	for(i=0; i<(int)(sizeof(b)/sizeof(int)); i++){
		insertBST(&bst2, &b[i]);
	}

	printf("\nInserisci un elemento da eliminare: ");
	el = inputItem();

	el = deleteBST(&bst, el);

	if (el != NULL)
		printf("Elemento trovato ed eliminato\n");
	else
		printf("Eleneto non trovato\n");

	
	printf("Inserisci l'elemento da cercare: ");
	el = inputItem();
	ret = searchInLevel(bst, el);

	if (ret == -1) {
		printf("Elemento non trovato.\n");
	} else {
		printf("Elementro trovato in profondità %d\n", ret);
	}

	ret = cmpbst(bst, bst2);

	if (ret) {
		printf("Gli alberi sono uguali\n");
	} else {
		printf("Gli alberi non sono uguali\n");
	}

	printf("Il minimo e': ");
	outputItem(min(bst));

	printf("\nIl massimo e': ");
	outputItem(max(bst));

	return 0;
}
