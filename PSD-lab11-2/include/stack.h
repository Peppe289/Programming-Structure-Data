#ifndef _LIB_STACK_H_
#define _LIB_STACK_H_

#include <item.h>

typedef struct stack *Stack;

Stack newStack();
int isEmptyStack(Stack); 
int push(Stack, Item);
int pop(Stack);
Item top(Stack);
void printStack(Stack);

#endif /* _LIB_STACK_H_ */
