#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <item.h>

#define MAX 20

Item inputItem()
{
	char *p = malloc(MAX * sizeof(char));
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
