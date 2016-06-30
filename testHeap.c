/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 8 February 2016
Last Revision: 26 February 2016
Description: This program makes assertions to test Heap.c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "Heap.h"

int main(int argc, char *argv[]) {

   //tests heap initialisation
   printf("Testing heap initialisation:\n");
   Heap h = createHeap();
   assert(h != NULL);
   assert(getHeapSize(h) == 0);
   assert(isHeapEmpty(h) == TRUE);
   printf("Empty heap: ");
   showHeap(h);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests insertHeapItem() and getHeapSize()
   printf("Tesing insertHeapItem() and getHeapSize():\n");
   insertHeapItem(h, 5);
   assert(getHeapSize(h) == 1);
   assert(isHeapEmpty(h) == FALSE);
   insertHeapItem(h, 10);
   assert(getHeapSize(h) == 2);
   insertHeapItem(h, 15);
   assert(getHeapSize(h) == 3);
   insertHeapItem(h, 2);
   assert(getHeapSize(h) == 4);
   insertHeapItem(h, 5); //re-inserts existing item
   assert(getHeapSize(h) == 5);
   printf("Heap containing 5, 10, 15, 2 and 5:\n");
   showHeap(h);
   insertHeapItem(h, 7);
   assert(getHeapSize(h) == 6);
   insertHeapItem(h, 3);
   assert(getHeapSize(h) == 7);
   insertHeapItem(h, 1);
   assert(getHeapSize(h) == 8);
   insertHeapItem(h, 29);
   assert(getHeapSize(h) == 9);
   insertHeapItem(h, 3); //re-inserts existing item
   assert(getHeapSize(h) == 10);
   printf("Heap containing 5, 10, 15, 2, 5, 7, 3, 1, 29 and 3:\n");
   showHeap(h);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isInHeap()
   printf("Tesing isInHeap():\n");
   assert(isHeapEmpty(h)  == FALSE);
   assert(isInHeap(h, 0)  == FALSE);
   assert(isInHeap(h, 4)  == FALSE);
   assert(isInHeap(h, 6)  == FALSE);
   assert(isInHeap(h, 8)  == FALSE);
   assert(isInHeap(h, 9)  == FALSE);
   assert(isInHeap(h, 12) == FALSE);
   assert(isInHeap(h, 22) == FALSE);
   assert(isInHeap(h, 46) == FALSE);
   assert(isInHeap(h, 1)  ==  TRUE);
   assert(isInHeap(h, 2)  ==  TRUE);
   assert(isInHeap(h, 3)  ==  TRUE);
   assert(isInHeap(h, 5)  ==  TRUE);
   assert(isInHeap(h, 7)  ==  TRUE);
   assert(isInHeap(h, 10) ==  TRUE);
   assert(isInHeap(h, 15) ==  TRUE);
   assert(isInHeap(h, 29) ==  TRUE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getHeapRoot() and removeHeapRoot()
   printf("Tesing getHeapRoot() and removeHeapRoot():\n");
   assert(isHeapEmpty(h) == FALSE);
   assert(getHeapRoot(h) == 29);
   assert(removeHeapRoot(h) == 29);
   assert(getHeapSize(h) == 9);
   assert(getHeapRoot(h) == 15);
   assert(removeHeapRoot(h) == 15);
   assert(getHeapSize(h) == 8);
   printf("Heap containing 5, 10, 2, 5, 7, 3, 1 and 3:\n");
   showHeap(h);
   assert(getHeapRoot(h) == 10);
   assert(removeHeapRoot(h) == 10);
   assert(getHeapSize(h) == 7);
   assert(getHeapRoot(h) == 7);
   assert(removeHeapRoot(h) == 7);
   assert(getHeapSize(h) == 6);
   insertHeapItem(h, 78);
   assert(getHeapSize(h) == 7);
   insertHeapItem(h, 42);
   assert(getHeapSize(h) == 8);
   insertHeapItem(h, 4);
   assert(getHeapSize(h) == 9);
   printf("Heap containing 5, 2, 5, 3, 1, 3, 78, 42 and 4:\n");
   showHeap(h);
   assert(getHeapRoot(h) == 78);
   assert(removeHeapRoot(h) == 78);
   assert(getHeapSize(h) == 8);
   assert(getHeapRoot(h) == 42);
   assert(removeHeapRoot(h) == 42);
   assert(getHeapSize(h) == 7);
   assert(getHeapRoot(h) == 5);
   assert(removeHeapRoot(h) == 5);
   assert(getHeapSize(h) == 6);
   assert(getHeapRoot(h) == 5);
   assert(removeHeapRoot(h) == 5);
   assert(getHeapSize(h) == 5);
   assert(getHeapRoot(h) == 4);
   assert(removeHeapRoot(h) == 4);
   assert(getHeapSize(h) == 4);
   printf("Heap containing 2, 3, 1 and 3:\n");
   showHeap(h);
   assert(getHeapRoot(h) == 3);
   assert(removeHeapRoot(h) == 3);
   assert(getHeapSize(h) == 3);
   assert(getHeapRoot(h) == 3);
   assert(removeHeapRoot(h) == 3);
   assert(getHeapSize(h) == 2);
   assert(getHeapRoot(h) == 2);
   assert(removeHeapRoot(h) == 2);
   assert(getHeapSize(h) == 1);
   assert(getHeapRoot(h) == 1);
   assert(removeHeapRoot(h) == 1);
   assert(getHeapSize(h) == 0);
   assert(isHeapEmpty(h) == TRUE);
   printf("Empty heap: ");
   showHeap(h);
   insertHeapItem(h, 22);
   assert(getHeapSize(h) == 1);
   assert(isHeapEmpty(h) == FALSE);
   insertHeapItem(h, -66);
   assert(getHeapSize(h) == 2);
   printf("Heap containing 22 and -66:\n");
   showHeap(h);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests heap expansion and contraction
   printf("Testing heap expansion and contraction:\n");
   int i;
   for (i = 100; i < 300; i++) {
      insertHeapItem(h, i);
      assert(getHeapRoot(h) == i);
      assert(getHeapSize(h) == i - 99 + 2);
   }
   assert(getHeapRoot(h) == 299);
   assert(getHeapSize(h) == 202);
   assert(isHeapEmpty(h) == FALSE);
   for (i = 100; i < 300; i++) assert(isInHeap(h, i) == TRUE);
   for (i =   0; i < 100; i++) {
      assert(getHeapRoot(h) == 299 - i);
      assert(removeHeapRoot(h) == 299 - i);
   }
   assert(getHeapRoot(h) == 199);
   assert(getHeapSize(h) == 102);
   assert(isHeapEmpty(h) == FALSE);

   for (i = 500; i < 600; i++) {
      insertHeapItem(h, i);
      assert(getHeapRoot(h) == i);
      assert(getHeapSize(h) == i - 499 + 102);
   }
   assert(getHeapRoot(h) == 599);
   assert(getHeapSize(h) == 202);
   assert(isHeapEmpty(h) == FALSE);
   for (i = 500; i < 600; i++) assert(isInHeap(h, i) == TRUE);
   for (i =   0; i < 200; i++) {
      if (i < 100) {
         assert(getHeapRoot(h) == 599 - i);
         assert(removeHeapRoot(h) == 599 - i);
      } else {
         assert(getHeapRoot(h) == 299 - i);
         assert(removeHeapRoot(h) == 299 - i);
      }
   }
   assert(getHeapRoot(h) == 22);
   assert(getHeapSize(h) == 2);
   assert(isHeapEmpty(h) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   disposeHeap(h);
   printf("Testing completed: PROGRAM COMPLIES\n");
   return EXIT_SUCCESS;
}
