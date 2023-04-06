#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <list.h>
#include <item.h>

#define MAX 20

Item inputItem()
{
	char *p = malloc(MAX * sizeof(char));
	printf("Inserisci la stringa: ");
	scanf("%s", p);

	return p;
}

void outputItem(Item a)
{
	char *p = a;
	printf("%s ", p);
}
int cmpItem(Item a, Item b)
{
	char *p1 = a;
	char *p2 = b;

	return strcmp(p1, p2);
}

void *addrDataInput()
{
	char *ret;
	ret = malloc(20 * sizeof(char));
	scanf("%s", ret);
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
 * @value: contiene una stringa su memoria heap.
 * Basta fare il free del valore.
 */
void free_struct(Node data) {
	free(addrStruct(data));
	free(data);
}