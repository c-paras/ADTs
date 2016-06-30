/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This program makes assertions to test Stack.c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "Stack.h"

int main(int argc, char *argv[]) {

   //tests stack initialisation
   printf("Testing stack initialisation:\n");
   Stack s = createStack();
   assert(s != NULL);
   assert(getStackSize(s) == 0);
   assert(isStackEmpty(s) == TRUE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests push() and getStackSize()
   printf("Testing push() and getStackSize():\n");
   push(s, 0);
   assert(getStackSize(s) == 1);
   assert(isStackEmpty(s) == FALSE);
   push(s, 4);
   assert(getStackSize(s) == 2);
   push(s, 10);
   assert(getStackSize(s) == 3);
   push(s, 800);
   assert(getStackSize(s) == 4);
   push(s, -7);
   assert(getStackSize(s) == 5);
   push(s, -42);
   assert(getStackSize(s) == 6);
   push(s, 195);
   assert(getStackSize(s) == 7);
   push(s, 50000);
   assert(getStackSize(s) == 8);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getTop()
   printf("Testing getTop():\n");
   assert(isStackEmpty(s) == FALSE);
   assert(getTop(s) == 50000);
   push(s, 11);
   assert(getStackSize(s) == 9);
   assert(getTop(s) == 11);
   push(s, 22);
   assert(getStackSize(s) == 10);
   assert(getTop(s) == 22);
   push(s, 33);
   assert(getStackSize(s) == 11);
   assert(getTop(s) == 33);
   push(s, 44);
   assert(getStackSize(s) == 12);
   assert(getTop(s) == 44);
   push(s, 55);
   assert(getStackSize(s) == 13);
   assert(getTop(s) == 55);
   push(s, 66);
   assert(getStackSize(s) == 14);
   assert(getTop(s) == 66);
   push(s, 77);
   assert(getStackSize(s) == 15);
   assert(getTop(s) == 77);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests pop()
   printf("Testing pop():\n");
   assert(isStackEmpty(s) == FALSE);
   assert(pop(s) == 77);
   assert(getStackSize(s) == 14);
   assert(getTop(s) == 66);
   assert(pop(s) == 66);
   assert(getStackSize(s) == 13);
   assert(getTop(s) == 55);
   assert(pop(s) == 55);
   assert(getStackSize(s) == 12);
   assert(getTop(s) == 44);
   assert(pop(s) == 44);
   assert(getStackSize(s) == 11);
   assert(getTop(s) == 33);
   assert(pop(s) == 33);
   assert(getStackSize(s) == 10);
   assert(getTop(s) == 22);
   push(s, 999);
   assert(getStackSize(s) == 11);
   assert(getTop(s) == 999);
   assert(pop(s) == 999);
   assert(getStackSize(s) == 10);
   assert(getTop(s) == 22);
   printf("Testing completed: UNIT COMPLIES\n\n");

   disposeStack(s);
   printf("Testing completed: PROGRAM COMPLIES\n");
   return EXIT_SUCCESS;
}
