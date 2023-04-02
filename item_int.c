#include <stdlib.h>
#include <stdio.h>

#include <item.h>
#include <list.h>

Item inputItem()
{
	int *p = malloc(sizeof(int));
	scanf("%d", p);

	return p;
}

void outputItem(Item a)
{
	int *p = a;
	printf("%d ", *p);
}

int cmpItem(Item a, Item b)
{
	int *p1 = a;
	int *p2 = b;

	return (*p1 - *p2);
}

void *addrDataInput()
{
	int *ret;
	ret = malloc(sizeof(int));
	scanf("%d", ret);
	return ret;
}

/**
 * Ritorna l'indirizzo dell'Item value
 */
static void *addrStruct(Node data) {
	return valueNode(data);
}

/**
 * Per item_int la struttura è:
 * 
 * struct node {
 * 		Item value;
 * 		struct node *next;
 * }
 * 
 * @value: contiene un int su memoria heap.
 * Basta fare il free del valore.
 */
void free_struct(Node data) {
	free(addrStruct(data));
	free(data);
}