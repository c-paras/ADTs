/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 8 February 2016
Last Revision: 26 February 2016
Description: This program makes assertions to test PriorityQueue.c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "PriorityQueue.h"

int main(int argc, char *argv[]) {

   //tests priority queue initialisation
   printf("Testing priority queue initialisation:\n");
   PQueue pq = createPQueue();
   assert(pq != NULL);
   assert(getPQueueSize(pq) == 0);
   assert(isPQueueEmpty(pq) == TRUE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests priorityEnqueue() and getPQueueSize()
   printf("Tesing priorityEnqueue() and getPQueueSize():\n");
   priorityEnqueue(pq, 5);
   assert(getPQueueSize(pq) == 1);
   assert(isPQueueEmpty(pq) == FALSE);
   priorityEnqueue(pq, 10);
   assert(getPQueueSize(pq) == 2);
   priorityEnqueue(pq, 15);
   assert(getPQueueSize(pq) == 3);
   priorityEnqueue(pq, 2);
   assert(getPQueueSize(pq) == 4);
   priorityEnqueue(pq, 5); //re-inserts existing item
   assert(getPQueueSize(pq) == 5);
   priorityEnqueue(pq, 7);
   assert(getPQueueSize(pq) == 6);
   priorityEnqueue(pq, 3);
   assert(getPQueueSize(pq) == 7);
   priorityEnqueue(pq, 1);
   assert(getPQueueSize(pq) == 8);
   priorityEnqueue(pq, 29);
   assert(getPQueueSize(pq) == 9);
   priorityEnqueue(pq, 3); //re-inserts existing item
   assert(getPQueueSize(pq) == 10);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests peak() and priorityDequeue()
   printf("Tesing peak() and priorityDequeue():\n");
   assert(isPQueueEmpty(pq) == FALSE);
   assert(peak(pq) == 29);
   assert(priorityDequeue(pq) == 29);
   assert(getPQueueSize(pq) == 9);
   assert(peak(pq) == 15);
   assert(priorityDequeue(pq) == 15);
   assert(getPQueueSize(pq) == 8);
   assert(peak(pq) == 10);
   assert(priorityDequeue(pq) == 10);
   assert(getPQueueSize(pq) == 7);
   assert(peak(pq) == 7);
   assert(priorityDequeue(pq) == 7);
   assert(getPQueueSize(pq) == 6);
   priorityEnqueue(pq, 78);
   assert(getPQueueSize(pq) == 7);
   priorityEnqueue(pq, 42);
   assert(getPQueueSize(pq) == 8);
   priorityEnqueue(pq, 4);
   assert(getPQueueSize(pq) == 9);
   assert(peak(pq) == 78);
   assert(priorityDequeue(pq) == 78);
   assert(getPQueueSize(pq) == 8);
   assert(peak(pq) == 42);
   assert(priorityDequeue(pq) == 42);
   assert(getPQueueSize(pq) == 7);
   assert(peak(pq) == 5);
   assert(priorityDequeue(pq) == 5);
   assert(getPQueueSize(pq) == 6);
   assert(peak(pq) == 5);
   assert(priorityDequeue(pq) == 5);
   assert(getPQueueSize(pq) == 5);
   assert(peak(pq) == 4);
   assert(priorityDequeue(pq) == 4);
   assert(getPQueueSize(pq) == 4);
   assert(peak(pq) == 3);
   assert(priorityDequeue(pq) == 3);
   assert(getPQueueSize(pq) == 3);
   assert(peak(pq) == 3);
   assert(priorityDequeue(pq) == 3);
   assert(getPQueueSize(pq) == 2);
   assert(peak(pq) == 2);
   assert(priorityDequeue(pq) == 2);
   assert(getPQueueSize(pq) == 1);
   assert(peak(pq) == 1);
   assert(priorityDequeue(pq) == 1);
   assert(getPQueueSize(pq) == 0);
   assert(isPQueueEmpty(pq) == TRUE);
   priorityEnqueue(pq, 22);
   assert(getPQueueSize(pq) == 1);
   assert(isPQueueEmpty(pq) == FALSE);
   priorityEnqueue(pq, -66);
   assert(getPQueueSize(pq) == 2);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests heap expansion and contraction
   printf("Testing heap expansion and contraction:\n");
   int i;
   for (i = 100; i < 300; i++) {
      priorityEnqueue(pq, i);
      assert(peak(pq) == i);
      assert(getPQueueSize(pq) == i - 99 + 2);
   }
   assert(peak(pq) == 299);
   assert(getPQueueSize(pq) == 202);
   assert(isPQueueEmpty(pq) == FALSE);
   for (i =   0; i < 100; i++) {
      assert(peak(pq) == 299 - i);
      assert(priorityDequeue(pq) == 299 - i);
   }
   assert(peak(pq) == 199);
   assert(getPQueueSize(pq) == 102);
   assert(isPQueueEmpty(pq) == FALSE);

   for (i = 500; i < 600; i++) {
      priorityEnqueue(pq, i);
      assert(peak(pq) == i);
      assert(getPQueueSize(pq) == i - 499 + 102);
   }
   assert(peak(pq) == 599);
   assert(getPQueueSize(pq) == 202);
   assert(isPQueueEmpty(pq) == FALSE);
   for (i =   0; i < 200; i++) {
      if (i < 100) {
         assert(peak(pq) == 599 - i);
         assert(priorityDequeue(pq) == 599 - i);
      } else {
         assert(peak(pq) == 299 - i);
         assert(priorityDequeue(pq) == 299 - i);
      }
   }
   assert(peak(pq) == 22);
   assert(getPQueueSize(pq) == 2);
   assert(isPQueueEmpty(pq) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   disposePQueue(pq);
   printf("Testing completed: PROGRAM COMPLIES\n");
   return EXIT_SUCCESS;
}
