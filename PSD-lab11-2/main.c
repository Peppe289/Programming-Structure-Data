#include <stdio.h>
#include <stdlib.h>

#include <item.h>
#include <stack.h>
#include <queue.h>

#define INPUT	5

int main()
{
	Queue data = newQueue();

	for (int i = 0; i != INPUT; ++i) {
		printf("Inserisci gli elementi [%d/%d]: ", i + 1, INPUT);
		enqueue(data, inputItem());
	}

	printf("\nStampa coda: ");
	printQueue(data);

	printf("\ndequeue...");
	free(dequeue(data));

	printf("\nStampa coda: ");
	printQueue(data);

	printf("\nInserisci un altro numero: ");
	enqueue(data, inputItem());

	printf("\nStampa coda: ");
	printQueue(data);

	free_queue(data);

	printf("\n");
	return 0;
}
