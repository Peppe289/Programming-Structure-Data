#include <stdio.h>

#include <btree.h>
#include <item.h>

static BTree buildLocalTree() {
	BTree h,a,c,d,l,p,s,o,q;

	q=buildTree(NULL,NULL,"q");
	o=buildTree(NULL,NULL,"o");
	s=buildTree(NULL,NULL,"s");
	p=buildTree(NULL,NULL,"p");
	d=buildTree(NULL,NULL,"d");
	l=buildTree(o,q,"l");
	a=buildTree(d,l,"a");
	c=buildTree(p,s,"c");
	h=buildTree(a,c,"h");

	return h;
}

int main(){

	BTree root = buildLocalTree();

	printf("preorder:\t\t");
	preOrder(root);
	printf("\npreorder stack:\t\t");
	preOrderIt(root);
	printf("\npostorder:\t\t");
	postOrder(root);
	printf("\npostorder stack:\t");
	postOrderIt(root);
	printf("\ninorder:\t\t");
	inOrder(root);
	printf("\ninorder stack:\t\t");
	inOrderIt(root);

	printf("\n\nNumero di nodi: %d\n", NodeTree(root));
	printf("Altezza dell'albero: %d\n", heightTree(root));

	printf("\nLivelli dell'albero:\n");
	levelvisit(root);

	/**
	 * dealloca la memoria dell'albero
	*/
	free_tree(root);
	printf("\n");
	return 0;
}