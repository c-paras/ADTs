/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 8 February 2016
Last Revision: 26 February 2016
Description: This program performs operations on an abstract priority queue data type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "PriorityQueue.h"

#define HEAP_SIZE       32
#define INVALID_INDEX   -1
#define PARENT_INDEX i / 2
#define LEFT_CHILD   2 * i
#define RIGHT_CHILD (2 * i) + 1

//dynamic array concrete representation of priority queue
typedef struct priorityQueue {
   item *items;
   unsigned long size, maxSize;
} priorityQueue;

//creates and returns a new empty priority queue
PQueue createPQueue(void) {

   PQueue new = malloc(sizeof(priorityQueue));
   assert(new != NULL);
   new->items = malloc((HEAP_SIZE + 1) * sizeof(item));
   assert(new->items != NULL);
   new->size = 0;
   new->maxSize = HEAP_SIZE;
   return new;
}

//frees all memory associated with a given priority queue
void disposePQueue(PQueue pq) {

   assert(pq != NULL);
   for (unsigned long i = 1; i <= pq->size; i++) del(pq->items[i]);
   free(pq->items);
   free(pq);
}

//inserts a given item in the correct location of a given priority queue
void priorityEnqueue(PQueue pq, item data) {

   assert(pq != NULL);

   //reallocates heap array if expansion is required
   if (pq->size == pq->maxSize) {
      pq->maxSize += HEAP_SIZE;
      pq->items = realloc(pq->items, (pq->maxSize + 1) * sizeof(item));
      assert(pq->items != NULL);
   }

   //inserts data into priority queue and shifts upwards if necessary
   pq->items[++pq->size] = copy(data);
   unsigned long i = pq->size;
   while (i > 1 && lt(pq->items[PARENT_INDEX], pq->items[i])) {
      item swap = copy(pq->items[i]);
      del(pq->items[i]);
      pq->items[i] = copy(pq->items[PARENT_INDEX]);
      del(pq->items[PARENT_INDEX]);
      pq->items[PARENT_INDEX] = copy(swap);
      del(swap);
      i = PARENT_INDEX;
   }

}

//removes and returns a copy of the highest priority (root) item of the given priority queue
item priorityDequeue(PQueue pq) {

   assert(pq != NULL);
   assert(isPQueueEmpty(pq) == FALSE);
   item root = peak(pq);
   pq->items[1] = copy(pq->items[pq->size]);
   pq->size--;

   //shifts root item downwards if necessary
   unsigned long j, i = 1;
   while (LEFT_CHILD <= pq->size) {
      //prepares to swap with the larger of the two children
      j = LEFT_CHILD;
      if (gt(pq->items[RIGHT_CHILD], pq->items[LEFT_CHILD])) j = RIGHT_CHILD;

      if (ge(pq->items[i], pq->items[j])) break; //heap invariant satisfied
      item swap = copy(pq->items[j]);
      del(pq->items[j]);
      pq->items[j] = copy(pq->items[i]);
      del(pq->items[i]);
      pq->items[i] = copy(swap);
      del(swap);
      i = j;
   }

   del(pq->items[pq->size + 1]);

   //reallocates heap array if excess memory is present
   if (pq->size == pq->maxSize - HEAP_SIZE) {
      pq->maxSize -= HEAP_SIZE;
      pq->items = realloc(pq->items, (pq->maxSize + 1) * sizeof(item));
      assert(pq->items != NULL);
   }

   return root;
}

//returns the number of items in a given priority queue
unsigned long getPQueueSize(PQueue pq) {

   assert(pq != NULL);
   return pq->size;
}

//indicates whether a given priority queue is empty
bool isPQueueEmpty(PQueue pq) {

   assert(pq != NULL);
   return pq->size == 0;
}

//obtains and returns the highest priority item in a given priority queue
item peak(PQueue pq) {

   assert(pq != NULL);
   assert(isPQueueEmpty(pq) == FALSE);
   return pq->items[1];
}
