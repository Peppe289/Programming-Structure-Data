#ifndef _PSD_STACK_H_
#define _PSD_STACK_H_

#include <item.h>

typedef struct stack *Stack;

#if defined(__STDC_VERSION__)
#if (__STDC_VERSION__ >= 199901)
#define INLINE_STATIC static inline
#else
#define INLINE_STATIC static
#endif
#else
#define INLINE_STATIC static
#endif

Stack newStack();
int isEmptyStack(Stack);
int push(Stack, Item);
int pop(Stack);
Item top(Stack);
void printStack(Stack);

#endif /* _PSD_STACK_H_ */