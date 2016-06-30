/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 8 February 2016
Last Revision: 26 February 2016
Description: This program performs operations on an abstract binary heap data type.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "Heap.h"

#define HEAP_SIZE       32
#define INVALID_INDEX   -1
#define PARENT_INDEX i / 2
#define LEFT_CHILD   2 * i
#define RIGHT_CHILD (2 * i) + 1

//dynamic array concrete representation of heap
typedef struct binaryHeap {
   item *items;
   unsigned long size, maxSize;
} binaryHeap;

static bool printNewline(Heap h, unsigned long value);

//creates and returns a new empty heap
Heap createHeap(void) {

   Heap new = malloc(sizeof(binaryHeap));
   assert(new != NULL);
   new->items = malloc((HEAP_SIZE + 1) * sizeof(item));
   assert(new->items != NULL);
   new->size = 0;
   new->maxSize = HEAP_SIZE;
   return new;
}

//frees all memory associated with a given heap
void disposeHeap(Heap h) {

   assert(h != NULL);
   for (unsigned long i = 1; i <= h->size; i++) del(h->items[i]);
   free(h->items);
   free(h);
}

//inserts a given item in the correct location of a given heap
void insertHeapItem(Heap h, item data) {

   assert(h != NULL);

   //reallocates heap array if expansion is required
   if (h->size == h->maxSize) {
      h->maxSize += HEAP_SIZE;
      h->items = realloc(h->items, (h->maxSize + 1) * sizeof(item));
      assert(h->items != NULL);
   }

   //inserts data into heap and shifts upwards if necessary
   h->items[++h->size] = copy(data);
   unsigned long i = h->size;
   while (i > 1 && lt(h->items[PARENT_INDEX], h->items[i])) {
      item swap = copy(h->items[i]);
      del(h->items[i]);
      h->items[i] = copy(h->items[PARENT_INDEX]);
      del(h->items[PARENT_INDEX]);
      h->items[PARENT_INDEX] = copy(swap);
      del(swap);
      i = PARENT_INDEX;
   }

}

//removes and returns a copy of the root item of the given heap
item removeHeapRoot(Heap h) {

   assert(h != NULL);
   assert(isHeapEmpty(h) == FALSE);
   item root = getHeapRoot(h);
   h->items[1] = copy(h->items[h->size]);
   h->size--;

   //shifts root item downwards if necessary
   unsigned long j, i = 1;
   while (LEFT_CHILD <= h->size) {
      //prepares to swap with the larger of the two children
      j = LEFT_CHILD;
      if (gt(h->items[RIGHT_CHILD], h->items[LEFT_CHILD])) j = RIGHT_CHILD;

      if (ge(h->items[i], h->items[j])) break; //heap invariant satisfied
      item swap = copy(h->items[j]);
      del(h->items[j]);
      h->items[j] = copy(h->items[i]);
      del(h->items[i]);
      h->items[i] = copy(swap);
      del(swap);
      i = j;
   }

   del(h->items[h->size + 1]);

   //reallocates heap array if excess memory is present
   if (h->size == h->maxSize - HEAP_SIZE) {
      h->maxSize -= HEAP_SIZE;
      h->items = realloc(h->items, (h->maxSize + 1) * sizeof(item));
      assert(h->items != NULL);
   }

   return root;
}

//displays the items in a given heap as a binary tree
void showHeap(Heap h) {

   assert(h != NULL);
   if (isHeapEmpty(h) == TRUE) {
      printf("(empty)");
   } else {
      for (unsigned long i = 1; i <= h->size; i++) {
         show(h->items[i]);
         printf(" ");
         if (i != h->size && printNewline(h, i) == TRUE) printf("\n");
      }
   }
   printf("\n");
}

//returns the number of items in a given heap
unsigned long getHeapSize(Heap h) {

   assert(h != NULL);
   return h->size;
}

//returns whether a given item belongs to a given heap
bool isInHeap(Heap h, item data) {

   assert(h != NULL);

   //performs a linear scan of the heap array
   for (unsigned long i = 1; i < h->size + 1; i++) {
      if (eq(h->items[i], data)) return TRUE;
   }

   return FALSE;
}

//indicates whether a given heap is empty
bool isHeapEmpty(Heap h) {

   assert(h != NULL);
   return h->size == 0;
}

//obtains and returns the root of a given heap
item getHeapRoot(Heap h) {

   assert(h != NULL);
   assert(isHeapEmpty(h) == FALSE);
   return h->items[1];
}

//determines whether the given value is a sum of subsequent powers of two
static bool printNewline(Heap h, unsigned long value) {

   assert(h != NULL);
   unsigned long long sum = 0;

   //gets sum of 2^0 + 2^1 + 2^2 + ...
   for (unsigned long i = 0; i < h->size; i++) {
      sum += pow(2, i);
      if (sum == value) return TRUE;
      if (sum > value) return FALSE;
   }

   return FALSE;
}
