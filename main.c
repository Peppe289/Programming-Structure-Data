#include <stdio.h>
#include <stdlib.h>

#include <btree.h>
#include <item.h>

int main(){
	BTree h,a,c,d,l,p,s,o,q;

	int array[] = {2, 4, 7, 35, 86, 5, 76, 32, 120};
	int ret;
	Item el;

	q=buildTree(NULL,NULL,&array[0]);
	o=buildTree(NULL,NULL,&array[1]);
	s=buildTree(NULL,NULL,&array[2]);
	p=buildTree(NULL,NULL,&array[3]);
	d=buildTree(NULL,NULL,&array[4]);
	l=buildTree(o,q,&array[5]);
	a=buildTree(d,l,&array[6]);
	c=buildTree(p,s,&array[7]);
	h=buildTree(a,c,&array[8]);

	printf("preorder:\t");
	preOrder(h);

	printf("\npostorder:\t");
	postOrder(h);

	printf("\ninorder:\t");
	inOrder(h);


	printf("\nIl valore massimo nell'albero è: ");
	outputItem(max(h));


	printf("\nInserisci il valore da cercare: ");
	el = inputItem();
	ret = searchInLevel(h, el);

	if (ret == 0) {
		printf("Valore non trovato\n");
	} else {
		printf("Valore trovato\n");
	}

	free(el);

	ret = cmpBTree(h, h);

	if (ret) {
		printf("\nGli alberi sono ugauli");
	} else {
		printf("\nGli alberi non sono uguali");
	}

	free_tree(h);

	printf("\n");
	return 0;
}