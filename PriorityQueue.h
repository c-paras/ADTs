/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 8 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for PriorityQueue.c.
*/

#include "bool.h"
#include "item.h"

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct priorityQueue *PQueue;

//priority queue initialisation
PQueue createPQueue(void);
void disposePQueue(PQueue pq);

//priority queue progression
void priorityEnqueue(PQueue pq, item data);
item priorityDequeue(PQueue pq);

//priority queue query
unsigned long getPQueueSize(PQueue pq);
bool isPQueueEmpty(PQueue pq);
item peak(PQueue pq);

#endif
