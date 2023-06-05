#include "item.h"
#include "auto.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

Item inputItem()
{
	char *p = malloc(MAX * sizeof(char));
	scanf("%s", p);

	return p;
}

/**
 * Item automobile
 */
void outputItem(Item addr)
{
	Auto data = addr;

	printf("\n------Dati dell'auto------\n");
	printf("Targa: %s\t\t\tModello: %s\t\n", getTarga(data), getModello(data));
	printf("Anno di Produzione: %d\tImmatricolazione: %d",
		   getProd(data), getImm(data));
	printf("\n");
}

int cmpItem(Item a, Item b)
{
	char *p1 = a;
	char *p2 = b;

	return strcmp(p1, p2);
}