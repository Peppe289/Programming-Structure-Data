#include <stdlib.h>
#include <stdio.h>
#include <list.h>
#include <item.h>

struct list
{
	int size;
	struct node *head;
};

struct node
{
	Item value;
	struct node *next;
};

/**
 * Prende in input e alloca dinamicamente la stringa.
 * Il valore di ritorno è la stringa.
 *
 * Il vantaggio di questa funzione è il poter prendere gli spazi.
 */
char *inputString()
{
	char *ret;
	char tmp;
	int size = 1;
	ret = malloc(size * sizeof(char));

	do
	{
		tmp = getchar();
		ret = realloc(ret, (++size) * sizeof(char));
		ret[size - 2] = tmp;
	} while (tmp != '\n');

	ret[size - 2] = '\0';

	return ret;
}

struct node *headList(List data)
{
	return data->head;
}

struct node *nextList(struct node *data)
{
	return data->next;
}

Item valueNode(struct node *data)
{
	return data->value;
}

void sortList(List data)
{
	struct node *p;
	struct node *next;
	for (p = data->head; p != NULL; p = p->next)
	{
		// printf("%d -> ", *((int*)p->value));
		for (next = p->next; next != NULL; next = next->next)
		{
			if (cmpItem(p->value, next->value) > 0)
			{
				void *tmp;
				tmp = next->value;
				next->value = p->value;
				p->value = tmp;
			}
		}
	}
}

List newList()
{
	List list = malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	return list;
}

int isEmpty(List list)
{
	if (list->size == 0)
		return 1;

	return 0;
}

void addHead(List list, Item el)
{

	struct node *newHead = malloc(sizeof(struct node));

	newHead->value = el;
	newHead->next = list->head;

	list->head = newHead;

	(list->size)++;
}

Item removeHead(List list)
{

	if (isEmpty(list))
		return NULL;

	struct node *temp = list->head;
	list->head = temp->next;

	Item el = temp->value;
	free(temp);

	(list->size)--;

	return el;
}

Item getHead(List list)
{

	if (isEmpty(list))
		return NULL;

	return list->head->value;
}

int sizeList(List list)
{
	return list->size;
}

void printList(List list)
{
	struct node *p;
	for (p = list->head; p != NULL; p = p->next)
	{
		outputItem(p->value);
	}
}

Item searchListItem(List l, Item q, int *pos)
{
	struct node *p;
	*pos = 0;
	for (p = l->head; p != NULL; p = p->next, (*pos)++)
	{
		if (cmpItem(q, p->value) == 0)
		{
			return p->value;
		}
	}
	*pos = -1;
	return NULL;
}

Item removeListItem(List l, Item q)
{
	struct node *prev, *p;
	Item val;
	if (isEmpty(l))
		return NULL;

	/**
	 * Il valore da eliminare potrebbe
	 * essere un valore nullo.
	 */
	if (q == NULL)
	{
		return NULL;
	}

	for (p = l->head; p != NULL; prev = p, p = p->next)
	{
		if (cmpItem(q, p->value) == 0)
		{
			if (p == l->head)
				return removeHead(l);
			else // si può anche evitare
			{
				prev->next = p->next;
				val = p->value; // assegno il valore precedente dell'item
				(l->size)--;	// decremento taglia lista
				free_struct(p);		// libero memoria p
				return val;		// ritorno l'item
			}
		}
	}
	return NULL; // caso in cui non è stato trovato
}

Item removeListPos(List l, int pos)
{
	struct node *prev, *p;
	Item val;
	int i;
	if (isEmpty(l) || pos < 0 || pos >= l->size) // controllo precondizione
		return NULL;
	for (i = 0, p = l->head; p != NULL; prev = p, p = p->next, i++)
	{
		if (i == pos)
		{
			if (p == l->head)
				return removeHead(l);
			else // si può anche evitare
			{
				prev->next = p->next;
				val = p->value; // assegno il valore precedente dell'item
				(l->size)--;	// decremento taglia lista
				free_struct(p);		// libero memoria p
				return val;		// ritorno l'item
			}
		}
	}
	return NULL;
}