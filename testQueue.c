/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This program makes assertions to test Queue.c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "Queue.h"

int main(int argc, char *argv[]) {

   //tests queue initialisation
   printf("Testing queue initialisation:\n");
   Queue q = createQueue();
   assert(q != NULL);
   assert(getQueueLength(q) == 0);
   assert(isQueueEmpty(q) == TRUE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests enqueue() and getQueueLength()
   printf("Testing enqueue() and getQueueLength():\n");
   enqueue(q, 0);
   assert(getQueueLength(q) == 1);
   assert(isQueueEmpty(q) == FALSE);
   enqueue(q, 4);
   assert(getQueueLength(q) == 2);
   enqueue(q, 10);
   assert(getQueueLength(q) == 3);
   enqueue(q, 800);
   assert(getQueueLength(q) == 4);
   enqueue(q, -7);
   assert(getQueueLength(q) == 5);
   enqueue(q, -42);
   assert(getQueueLength(q) == 6);
   enqueue(q, 195);
   assert(getQueueLength(q) == 7);
   enqueue(q, 50000);
   assert(getQueueLength(q) == 8);
   enqueue(q, 9999);
   assert(getQueueLength(q) == 9);
   enqueue(q, -3333);
   assert(getQueueLength(q) == 10);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getHead() and dequeue()
   printf("Testing getHead() and dequeue():\n");
   assert(isQueueEmpty(q) == FALSE);
   assert(getHead(q) == 0);
   assert(dequeue(q) == 0);
   assert(getQueueLength(q) == 9);
   assert(getHead(q) == 4);
   assert(dequeue(q) == 4);
   assert(getQueueLength(q) == 8);
   assert(getHead(q) == 10);
   assert(dequeue(q) == 10);
   assert(getQueueLength(q) == 7);
   assert(getHead(q) == 800);
   assert(dequeue(q) == 800);
   assert(getQueueLength(q) == 6);
   assert(getHead(q) == -7);
   assert(dequeue(q) == -7);
   assert(getQueueLength(q) == 5);
   assert(getHead(q) == -42);
   enqueue(q, -1111);
   assert(getQueueLength(q) == 6);
   assert(getHead(q) == -42);
   assert(dequeue(q) == -42);
   assert(getQueueLength(q) == 5);
   assert(getHead(q) == 195);
   assert(dequeue(q) == 195);
   assert(getQueueLength(q) == 4);
   assert(getHead(q) == 50000);
   assert(dequeue(q) == 50000);
   assert(getQueueLength(q) == 3);
   assert(getHead(q) == 9999);
   assert(dequeue(q) == 9999);
   assert(getQueueLength(q) == 2);
   assert(getHead(q) == -3333);
   assert(dequeue(q) == -3333);
   assert(getQueueLength(q) == 1);
   assert(getHead(q) == -1111);
   assert(dequeue(q) == -1111);
   assert(getQueueLength(q) == 0);
   assert(isQueueEmpty(q) == TRUE);
   enqueue(q, 4173);
   assert(getQueueLength(q) == 1);
   assert(isQueueEmpty(q) == FALSE);
   assert(getHead(q) == 4173);
   enqueue(q, 99);
   assert(getQueueLength(q) == 2);
   assert(getHead(q) == 4173);
   printf("Testing completed: UNIT COMPLIES\n\n");

   disposeQueue(q);
   printf("Testing completed: PROGRAM COMPLIES\n");
   return EXIT_SUCCESS;
}
