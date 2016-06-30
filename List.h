/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 16 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for List.c.
*/

#include "bool.h"
#include "item.h"

#ifndef LIST_H
#define LIST_H

typedef struct linkedList *List;

//list initialisation
List createList(void);
List copyList(List l);
List convertToList(item *data, unsigned long num);
item *convertToArray(List l);
void disposeList(List l);

//list progression
void insertAtHead(List l, item data);
void insertAtTail(List l, item data);
void sortedInsert(List l, item data);
void insertAt(List l, item data, unsigned long position);
void removeHead(List l);
void removeTail(List l);
void removeAll(List l, item data);
void removeAt(List l, unsigned long position);

//list query
void showList(List l);
bool isInList(List l, item data);
bool isSorted(List l);
bool isSublist(List l1, List l2);
bool isStrictSublist(List l1, List l2);
bool isListEmpty(List l);

//getter functions
item getDataAt(List l, unsigned long position);
item getMinimalItem(List l);
item getMaximalItem(List l);
unsigned long getFrequency(List l, item data);
unsigned long getNumNodes(List l);

//higher-order functions
void map(List l, item (*f)(item));
item fold(List l, item (*f)(item, item), item identity);
void filter(List l, bool (*f)(item));

//list modification operations
void shiftHead(List l);
void shiftTail(List l);
void swapHeadTail(List l);
void reverseList(List l);
void pairwiseSwap(List l);
void removeDuplicates(List l);
void sortList(List l);

//list splitting operations
void splitList(List sourceList, List frontList, List backList);
void splitAt(List sourceList, List firstList, List secondList, unsigned long position);
void alternatingSplit(List sourceList, List firstList, List secondList);

//list combination operations
List concatenate(List l1, List l2);
List sortedMerge(List l1, List l2);
List zipLists(List l1, List l2);

#endif
