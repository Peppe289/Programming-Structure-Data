#include <stdio.h>
#include <stdlib.h>
#include <item.h>
#include <stack.h>

#define START_DIM 10
#define ADD_DIM 5

struct stack
{
    Item *elements;
    int top;
    int dim;
};

Stack newStack()
{
    Stack s = malloc(sizeof(struct stack));

    if (s == NULL)
        return NULL;

    s->top = 0;
    s->elements = malloc(sizeof(Item) * START_DIM);

    if (s->elements == NULL)
        return NULL;

    s->dim = START_DIM;

    return s;
}

int isEmptyStack(Stack s)
{
    /**
     * Controlla anche s->top poiché lo stack può
     * avere una dimensione ma anche non essere utilizzato.
     */
    if (s->top == 0 || s->dim == 0)
        return 1;

    return 0;
}

int push(Stack s, Item el)
{
    Item *temp;

    if (s->top == s->dim)
    {
        temp = realloc(s->elements, sizeof(Item) * (unsigned long int)(s->dim + ADD_DIM));

        if (temp == NULL)
            return 0;
        else
        {
            s->elements = temp;
            s->dim += ADD_DIM;
            DBG("\n%s(): expand stack size from %d to %d\n", __func__, s->dim - ADD_DIM, s->dim);
        }
    }
    s->elements[s->top] = el;
    s->top++;

    return 1;
}

int pop(Stack s)
{
    if (isEmptyStack(s))
        return 0;

    (s->top)--;
    /**
     * PSD-es6:
     * L'indirizzo che andiamo a prendere si trova nello stack.
     * Non possiamo fare il free().
     */
#if 0
    free(s->elements[s->top]);
#endif

    return 1;
}

Item top(Stack s)
{
    if (isEmptyStack(s))
        return NULL;

    return s->elements[(s->top) - 1];
}

void printStack(Stack s)
{
    int i;

    for (i = s->top - 1; i >= 0; i--)
    {
        outputItem(s->elements[i]);
    }
}
