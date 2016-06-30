/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for Stack.c.
*/

#include "bool.h"
#include "item.h"

#ifndef STACK_H
#define STACK_H

typedef struct stack *Stack;

//stack initialisation
Stack createStack(void);
void  disposeStack(Stack s);

//stack progression
void push(Stack s, item data);
item pop(Stack s);

//stack query
item getTop(Stack s);
unsigned long getStackSize(Stack s);
bool isStackEmpty(Stack s);

#endif
