/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This program performs operations on an abstract stack data type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "Stack.h"

typedef struct node *link;

typedef struct node {
   item data;
   link next;
} node;

//list-like concrete representation of stack
typedef struct stack {
   link top;
   unsigned long length;
} stack;

//creates and returns a new empty stack
Stack createStack(void) {

   Stack new = malloc(sizeof(stack));
   assert(new != NULL);
   new->length = 0;
   new->top = NULL;
   return new;
}

//frees all memory associated with a given stack
void disposeStack(Stack s) {

   assert(s != NULL);
   item temp;
   while (isStackEmpty(s) == FALSE) {
      temp = pop(s);
      del(temp);
   }
   free(s);
}

//adds a new item to the top of a given stack
void push(Stack s, item data) {

   assert(s != NULL);
   link new = malloc(sizeof(node));
   assert(new != NULL);
   new->data = copy(data);
   new->next = s->top;
   s->top = new;
   s->length++;
}

//removes and returns a copy of the top item from a given stack
item pop(Stack s) {

   assert(s != NULL);
   assert(isStackEmpty(s) == FALSE);
   link top = s->top;
   item data = copy(top->data);
   s->top = top->next;
   del(top->data);
   free(top);
   s->length--;
   return data;
}

//returns the data at the top of a given stack
item getTop(Stack s) {

   assert(s != NULL);
   assert(isStackEmpty(s) == FALSE);
   return s->top->data;
}

//returns the size of a given stack
unsigned long getStackSize(Stack s) {

   assert(s != NULL);
   return s->length;
}

//indicates whether a given stack is empty
bool isStackEmpty(Stack s) {

   assert(s != NULL);
   return s->length == 0;
}
