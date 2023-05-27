/**
 * Il funzionamento di questa queue si occupa
 * di tenere a se due stack @head e @tail.
 * Il primo segue il normale funzionamento in enqueue della coda,
 * Il secondo segue il normale funzionamento di dequeue della coda.
 * 
 * Ad ogni operazione di input e rimozione viene fatto il sync con
 * il reverse dei rispettivi stack.
 */
#include <stdlib.h>
#include <stdio.h>

#include <queue.h>
#include <stack.h>

struct queue {
    /**
     * Stack:
     * 
     * int top;
     * Item value[];
     * 
     * Top is the last empty position.
     * Top - 1 is the last input data in head; 
     */
    Stack head;

    /**
     * Reverse stack.
     * 
     * int top;
     * Item value[];
     * 
     * Top is the last empty position.
     * Top - 1 is the last input data in queue;
     */
    Stack tail;
};

Queue newQueue() {
    Queue ret = malloc(sizeof(struct queue));

    ret->head = newStack();
    ret->tail = newStack();

    return ret;
}

int isEmptyQueue(Queue data) {
    return isEmptyStack(data->head);
}

/**
 * data = valori da prendere
 * 
 * sync = valori invertiti
 * 
 * Inverti ricorsivamente.
 */
static void recursion_sync(Stack data, Stack sync)
{
    Item tmp;

    if (isEmptyStack(data))
        return;

    tmp = top(data);
    pop(data);
    push(sync, tmp);
    recursion_sync(data, sync);
    push(data, tmp);
}

static Stack sync_data(Stack data, Stack sync)
{
    /**
     * Svuota il valore da syncare.
     */
    while (!isEmptyStack(sync))
        pop(sync);

    /**
     * Avvia la ricorsione dopo esserti assicurato
     * che lo stack in cui mettere le cose sia vuoto e allocabile.
     */
    recursion_sync(data, sync);

    return sync;
}

int enqueue(Queue data, Item value) {

    int tmp = push(data->tail, value);

    if (!tmp)
        return 0;

    /**
     * Reverse di head
     */
    sync_data(data->tail, data->head);

    return 1;
}

Item dequeue(Queue data) {

    Item tmp = top(data->head);

    if (pop(data->head) == 0)
        return NULL;

    /**
     * Reverse di tail
     */
    sync_data(data->head, data->tail);

    return tmp;
}

void printQueue(Queue data) {
    printStack(data->head);
}

void free_queue(Queue data) {

    /**
     * Gli indirizzi allocati in head
     * sono gli stessi allocati in tail.
     * 
     * E' necessario fare il free() di un solo
     * stack per liberare entrambi.
     */
    while (!isEmptyQueue(data)) {
        free(dequeue(data));
    }

    /**
     * Dealloca gli stack dinamici.
     */
    free(data->head);
    free(data->tail);

    /**
     * Dealloca la coda.
     */
    free(data);
}