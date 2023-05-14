#include <stdio.h>
#include <stdlib.h>

#include <item.h>
#include <stack.h>

#define MAXSTACK 50

struct stack{
    int top;
    Item arr[MAXSTACK];
};

Stack newStack(){
    Stack s = malloc(sizeof(struct stack));
    s->top=0;
    return s;
} 

int isEmptyStack(Stack s){
    if(s->top == 0)
        return 1;
    else    
        return 0;
}

int push(Stack s, Item el){
    if(s->top == MAXSTACK)
        return 0;
    else{
        s->arr[s->top] = el;
        (s->top)++;
        return 1;
    }
}

int pop(Stack s){
    if(isEmptyStack(s))
        return 0;
    else{
        (s->top)--;
        return 1;
    }
}

Item top(Stack s){
    if(isEmptyStack(s))
        return NULL;
    else
        return s->arr[(s->top)-1];
}

void printStack(Stack s){
    int i;
    for(i=s->top-1; i>=0; i--)
        outputItem(s->arr[i]);
}
