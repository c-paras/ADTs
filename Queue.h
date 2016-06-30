/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for Queue.c.
*/

#include "bool.h"
#include "item.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue *Queue;

//queue initialisation
Queue createQueue(void);
void  disposeQueue(Queue q);

//queue progression
void enqueue(Queue q, item data);
item dequeue(Queue q);

//queue query
item getHead(Queue q);
unsigned long getQueueLength(Queue q);
bool isQueueEmpty(Queue q);

#endif
