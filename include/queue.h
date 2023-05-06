#include <item.h>

typedef struct queue *Queue;

Queue newQueue();
int isEmptyQueue(Queue);
int enqueue(Queue, Item);
Item dequeue(Queue);
void printQueue(Queue);
Item *getArray(Queue data);
int getTail(Queue data);
int getHead(Queue data);