#ifndef _LIB_QUEUE_H_
#define _LIB_QUEUE_H_

#include <item.h>
#include <stack.h>

typedef struct queue *Queue;

Queue newQueue();
int isEmptyQueue(Queue);
int enqueue(Queue, Item);
Item dequeue(Queue);
void printQueue(Queue);

void free_queue(Queue);

#endif /* _LIB_QUEUE_H_ */
