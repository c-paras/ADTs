/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 8 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for Heap.c.
*/

#include "bool.h"
#include "item.h"

#ifndef HEAP_H
#define HEAP_H

typedef struct binaryHeap *Heap;

//heap initialisation
Heap createHeap(void);
void disposeHeap(Heap h);

//heap progression
void insertHeapItem(Heap h, item data);
item removeHeapRoot(Heap h);

//heap query
void showHeap(Heap h);
unsigned long getHeapSize(Heap h);
bool isInHeap(Heap h, item data);
bool isHeapEmpty(Heap h);
item getHeapRoot(Heap h);

#endif
