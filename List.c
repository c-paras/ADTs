/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 16 February 2016
Last Revision: 26 February 2016
Description: This program performs operations on an abstract singly linked list data type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "List.h"

typedef struct node *link;

typedef struct node {
   item data;
   link next;
} node;

//unbounded list concrete representation of linked list
typedef struct linkedList {
   link head, tail;
   unsigned long length;
} linkedList;

static link createNode(item data);
static item doFold(link curr, item (*f)(item, item), item identity);

//creates and returns a new empty list
List createList(void) {

   List new = malloc(sizeof(linkedList));
   assert(new != NULL);
   new->head = new->tail = NULL;
   new->length = 0;
   return new;
}

//returns an exact copy of a given list
List copyList(List l) {

   assert(l != NULL);
   List copy = createList();
   for (link curr = l->head; curr != NULL; curr = curr->next) insertAtTail(copy, curr->data);
   return copy;
}

//returns a list containing the same data as the given array in the same order
List convertToList(item *data, unsigned long num) {

   assert(data != NULL);
   List new = createList();
   for (unsigned long i = 0; i < num; i++) insertAtTail(new, data[i]);
   return new;
}

//returns an array containing the same data as the given list in the same order
item *convertToArray(List l) {

   assert(l != NULL);
   if (l->length == 0) return NULL;
   item *buffer = malloc(l->length * sizeof(item));
   assert(buffer != NULL);
   unsigned long i = 0;
   for (link curr = l->head; curr != NULL; curr = curr->next) buffer[i++] = copy(curr->data);
   return buffer;
}

//frees all memory associated with a given list
void disposeList(List l) {

   assert(l != NULL);
   link temp, curr = l->head;

   //deallocates memory for each node
   while (curr != NULL) {
      temp = curr->next;
      del(curr->data);
      free(curr);
      curr = temp;
   }

   free(l); //deallocates memory for the list object
}

//inserts the given data at the head of the given list
void insertAtHead(List l, item data) {

   assert(l != NULL);
   link new = createNode(data);
   new->next = l->head;
   l->head = new;
   if (l->length == 0) l->tail = new;
   l->length++;
}

//inserts the given data at the tail of the given list
void insertAtTail(List l, item data) {

   assert(l != NULL);
   link new = createNode(data);
   if (l->length == 0) {
      l->head = l->tail = new;
   } else {
      l->tail->next = new;
      l->tail = new;
   }
   l->length++;
}

//insert the given data in the given (sorted) list so as to maintain sortedness
void sortedInsert(List l, item data) {

   assert(l != NULL);

   //inserts at head or tail of the given list
   if (l->length == 0 || le(data, l->head->data)) {
      insertAtHead(l, data);
      return;
   } else if (ge(data, l->tail->data)) {
      insertAtTail(l, data);
      return;
   }

   link new = createNode(data);

   //inserts data at correct location in the given list
   for (link curr = l->head; curr->next != NULL; curr = curr->next) {
      if (le(curr->data, data) && ge(curr->next->data, data)) {
         new->next = curr->next;
         curr->next = new;
         l->length++;
         return;
      }
   }

}

//inserts the given data at the given position in the given list
void insertAt(List l, item data, unsigned long position) {

   assert(l != NULL);
   assert(position == 0 || position < l->length);
   link new = createNode(data);

   //inserts new node into given list
   if (l->length == 0) {
      l->head = l->tail = new;
   } else if (position == 0) {
      new->next = l->head;
      l->head = new;
   } else {
      link curr = l->head;

      //finds required node
      for (unsigned long i = 0; i < position - 1; i++) {
         curr = curr->next;
      }

      new->next = curr->next;
      curr->next = new;
      if (curr->next == NULL) l->tail = curr;
   }

   l->length++;
}

//removes the node at the head of the given list
void removeHead(List l) {

   assert(l != NULL);
   assert(isListEmpty(l) == FALSE);
   link temp = l->head->next;
   del(l->head->data);
   free(l->head);
   l->head = temp;
   l->length--;
}

//removes the node at the tail of the given list
void removeTail(List l) {

   assert(l != NULL);
   assert(isListEmpty(l) == FALSE);

   //removes the tail node and updates l->tail
   if (l->length == 1) {
      del(l->tail->data);
      free(l->tail);
      l->head = l->tail = NULL;
   } else {
      link curr = l->head;
      link prev = curr;

      //finds second-last node
      while (curr != NULL && curr->next != NULL) {
         prev = curr;
         curr = curr->next;
      }

      del(l->tail->data);
      free(l->tail);
      prev->next = NULL;
      l->tail = prev;
   }

   l->length--;
}

//removes all occurrences of the specified item in the given list if any exist
void removeAll(List l, item data) {

   assert(l != NULL);
   assert(isListEmpty(l) == FALSE);
   if (l->length == 1) {
      if (!eq(l->head->data, data)) return;
      removeHead(l);
      return;
   }
   link curr = l->head;

   //iterates over the first n - 1 nodes
   while (curr->next != NULL && curr->next->next != NULL) {
      if (eq(curr->next->data, data)) {
         link temp = curr->next;
         curr->next = curr->next->next;
         del(temp->data);
         free(temp);
         l->length--;
      } else {
         curr = curr->next;
      }
   }

   if (eq(l->head->data, data)) removeHead(l);
   if (eq(l->tail->data, data)) removeTail(l);
}

//removes the node at the given position of the given list
void removeAt(List l, unsigned long position) {

   assert(l != NULL);
   assert(isListEmpty(l) == FALSE);
   assert(position == 0 || position < l->length);

   //removes the specified node from the given list
   if (l->length == 1) {
      del(l->head->data);
      free(l->head);
      l->head = l->tail = NULL;
   } else if (position == 0) {
      link temp = l->head;
      l->head = temp->next;
      del(temp->data);
      free(temp);
   } else {
      link curr = l->head;

      //finds required node
      for (unsigned long i = 0; i < position - 1; i++) {
         curr = curr->next;
      }

      link temp = curr->next;
      curr->next = curr->next->next;
      del(temp->data);
      free(temp);
      if (curr->next == NULL) l->tail = curr;
   }

   l->length--;
}

//displays the data contained in a given list
void showList(List l) {

   assert(l != NULL);
   link curr = l->head;

   //prints the data contained in each node
   while (curr != NULL) {
      printf("[");
      show(curr->data);
      printf("]->");
      curr = curr->next;
   }

   printf("X\n");
}

//returns whether a given item is part of a given list
bool isInList(List l, item data) {

   assert(l != NULL);

   //performs a linear scan of the given list
   for (link curr = l->head; curr != NULL; curr = curr->next) {
      if (eq(curr->data, data)) return TRUE;
   }

   return FALSE;
}

//indicates whether a given list is in sorted (ascending) order
bool isSorted(List l) {

   assert(l != NULL);
   if (l->length < 2) return TRUE;
   for (link curr = l->head; curr->next != NULL; curr = curr->next) {
      if (lt(curr->next->data, curr->data)) return FALSE;
   }
   return TRUE;
}

//determines whether a given list is a sublist of another given list
//the first list must be fully sequentially equal to the second list to be a sublist
bool isSublist(List l1, List l2) {

   assert(l1 != NULL && l2 != NULL);
   if (l1->length == 0) return TRUE;
   if (l1->length > l2->length) return FALSE;

   //traverses the second list in order
   for (link curr2 = l2->head; curr2 != NULL; curr2 = curr2->next) {
      if (eq(curr2->data, l1->head->data)) {
         link curr = curr2;

         //checks whether the first list is sequentially equal to the second
         for (link curr1 = l1->head; curr1 != NULL; curr1 = curr1->next) {
            if (!eq(curr1->data, curr2->data)) {
               curr2 = curr;
               break;
            } else {
               curr2 = curr2->next;
            }
         }

         if (curr2 != curr) return TRUE;
      }
   }

   return FALSE;
}

//determines whether a given list is a strict sublist of another given list
//the first list must be a sublist of the second list but shorter than it to be a strict sublist
bool isStrictSublist(List l1, List l2) {

   assert(l1 != NULL && l2 != NULL);
   if (l1->length >= l2->length) return FALSE;
   return isSublist(l1, l2);
}

//indicates whether a given list is empty
bool isListEmpty(List l) {

   assert(l != NULL);
   return l->length == 0;
}

//returns the data at the given position of a given list
item getDataAt(List l, unsigned long position) {

   assert(l != NULL);
   assert(isListEmpty(l) == FALSE);
   assert(position < l->length);
   if (position == 0) return l->head->data;
   if (position == l->length - 1) return l->tail->data;
   link curr = l->head;

   //finds required position
   for (unsigned long i = 0; i < position; i++) {
      curr = curr->next;
   }

   return curr->data;
}

//returns the minimal element of a given list
item getMinimalItem(List l) {

   assert(l != NULL);
   assert(isListEmpty(l) == FALSE); //undefined for an empty list
   item min = l->head->data;
   for (link curr = l->head; curr != NULL; curr = curr->next) {
      if (lt(curr->data, min)) min = curr->data;
   }
   return min;
}

//returns the maximal element of a given list
item getMaximalItem(List l) {

   assert(l != NULL);
   assert(isListEmpty(l) == FALSE); //undefined for an empty list
   item max = l->head->data;
   for (link curr = l->head; curr != NULL; curr = curr->next) {
      if (gt(curr->data, max)) max = curr->data;
   }
   return max;
}

//returns the frequency of a given item in a given list
unsigned long getFrequency(List l, item data) {

   assert(l != NULL);
   unsigned long frequency = 0;

   //performs a linear scan of the given list
   for (link curr = l->head; curr != NULL; curr = curr->next) {
      if (eq(curr->data, data)) frequency++;
   }

   return frequency;
}

//returns the number of nodes in a given list
unsigned long getNumNodes(List l) {

   assert(l != NULL);
   return l->length;
}

//applies a given function to every element of a given list
//the given list will be affected iff the given function is not an identity function
void map(List l, item (*f)(item)) {

   assert(l != NULL && f != NULL);
   item data;
   for (link curr = l->head; curr != NULL; curr = curr->next) {
      data = f(curr->data);
      del(curr->data);
      curr->data = copy(data);
      del(data);
   }
}

//obtains an aggregate (compressed) value for the given list by applying the given function
//the supplied identity item is used under certain conditions where required
//the given list remains unchanged
item fold(List l, item (*f)(item, item), item identity) {

   assert(l != NULL && f != NULL);
   if (l->length != 0) {
      return doFold(l->head, f, identity);
   } else {
      return copy(identity);
   }
}

//removes all nodes in a given list which do not satisfy the given condition
void filter(List l, bool (*f)(item)) {

   assert(l != NULL && f != NULL);
   assert(isListEmpty(l) == FALSE);
   if (l->length == 1) {
      if (f(l->head->data) == FALSE) return;
      removeHead(l);
      return;
   }
   link curr = l->head;

   //iterates over the first n - 1 nodes
   while (curr->next != NULL && curr->next->next != NULL) {
      if (f(curr->next->data) == TRUE) {
         link temp = curr->next;
         curr->next = curr->next->next;
         del(temp->data);
         free(temp);
         l->length--;
      } else {
         curr = curr->next;
      }
   }

   if (f(l->head->data) == TRUE) removeHead(l);
   if (f(l->tail->data) == TRUE) removeTail(l);
}

//moves the head of a given list to the tail of the list
void shiftHead(List l) {

   assert(l != NULL);
   if (l->length < 2) return;
   link temp = l->head->next;
   l->head->next = NULL;
   l->tail->next = l->head;
   l->tail = l->head;
   l->head = temp;
}

//moves the tail of a given list to the head of the list
void shiftTail(List l) {

   assert(l != NULL);
   if (l->length < 2) return;

   //finds second-last node
   link curr = l->head;
   while (curr->next != NULL && curr->next->next) {
      curr = curr->next;
   }

   l->tail->next = l->head;
   l->head = l->tail;
   curr->next = NULL;
   l->tail = curr;
}

//exchanges the head of a given list with the tail of the list
void swapHeadTail(List l) {

   assert(l != NULL);

   //handles short lists
   if (l->length < 2) {
      return;
   } else if (l->length == 2) {
      shiftHead(l);
      return;
   }

   //finds second-last node
   link curr = l->head;
   while (curr->next != NULL && curr->next->next) {
      curr = curr->next;
   }

   link temp = l->head->next;
   l->head->next = NULL;
   curr->next = l->head;
   l->tail->next = temp;
   l->head = l->tail;
   l->tail = curr->next;
}

//reverses the order of the nodes in a given list
void reverseList(List l) {

   assert(l != NULL);
   if (l->length < 2) return;
   link temp, curr = l->head;

   //resets list parameters
   l->head = l->tail = NULL;
   l->length = 0;

   //inserts all nodes at the head one after the other
   while (curr != NULL) {
      insertAtHead(l, curr->data);
      temp = curr;
      curr = curr->next;
      del(temp->data);
      free(temp); //deallocates the original node
   }

}

//swaps all sequential pairs of nodes in a given list
//the tail of an odd-lengthed list is left unaffected
void pairwiseSwap(List l) {

   assert(l != NULL);
   if (l->length < 2) return;
   link first = NULL, second, curr = l->head;
   l->head = curr->next;
   link prevPair = NULL;

   //swaps node links in pairs
   while (curr != NULL && curr->next != NULL) {
      second = curr->next->next;
      first = curr;
      if (prevPair != NULL) prevPair->next = curr->next;
      curr->next->next = curr;
      first->next = second;
      prevPair = first;
      curr = second;
   }

   if (l->length % 2 == 0) l->tail = first; //changes tail of even-lengthed list
}

//removes all duplicate nodes from a given list
void removeDuplicates(List l) {

   assert(l != NULL);
   if (l->length < 2) return;
   link temp, curr2, curr = l->head;

   //checks for potential duplicates of each node in order
   while (curr != NULL && curr->next != NULL) {
      curr2 = curr;

      //finds and removes any duplicates of current node
      while (curr2 != NULL && curr2->next != NULL) {
         if (eq(curr2->next->data, curr->data)) {
            temp = curr2->next;
            curr2->next = curr2->next->next;
            del(temp->data);
            free(temp);
            l->length--;
         } else {
            curr2 = curr2->next;
         }
      }

      curr = curr->next;
   }

   //finds and updates tail of list
   curr = l->head;
   while (curr != NULL && curr->next != NULL) curr = curr->next;
   l->tail = curr;

}

//repositions the nodes in a given list into sorted (ascending) order
void sortList(List l) {

   assert(l != NULL);
   if (l->length < 2) return;
   link temp, curr = l->head;

   //resets list parameters
   l->head = l->tail = NULL;
   l->length = 0;

   //inserts each node into the list in sorted order
   while (curr != NULL) {
      sortedInsert(l, curr->data);
      temp = curr->next;
      del(curr->data);
      free(curr); //deallocates the original node
      curr = temp;
   }

}

//splits a given list into two halves, while keeping the original list unchanged
//the front list is one node longer than the back list if the source list is of odd length
void splitList(List sourceList, List frontList, List backList) {

   assert(sourceList != NULL && frontList != NULL && backList != NULL);
   assert(isListEmpty(frontList) == TRUE && isListEmpty(backList) == TRUE);

   //handles short source lists
   if (sourceList->length < 2) {
      if (sourceList->length == 1) insertAtHead(frontList, sourceList->head->data);
      return;
   }

   //finds length of front list
   unsigned long frontLength = (sourceList->length / 2) + (sourceList->length % 2);

   //copies nodes from the source list to the front and back lists
   for (link curr = sourceList->head; curr != NULL; curr = curr->next) {
      if (frontList->length < frontLength) {
         insertAtTail(frontList, curr->data);
      } else {
         insertAtTail(backList, curr->data);
      }
   }

}

//splits a given list at the given position, while keeping the original list unchanged
//if the minimum position (0) is specified, the front list remains empty
void splitAt(List sourceList, List firstList, List secondList, unsigned long position) {

   assert(sourceList != NULL && firstList != NULL && secondList != NULL);
   assert(isListEmpty(firstList) == TRUE && isListEmpty(secondList) == TRUE);
   assert(position == 0 || position < sourceList->length);

   //handles short source lists
   if (sourceList->length < 2) {
      if (sourceList->length == 1) insertAtHead(secondList, sourceList->head->data);
      return;
   }

   //copies nodes from the source list to the front and back lists
   for (link curr = sourceList->head; curr != NULL; curr = curr->next) {
      if (firstList->length < position) {
         insertAtTail(firstList, curr->data);
      } else {
         insertAtTail(secondList, curr->data);
      }
   }

}

//splits a given list across two initially empty lists pairwise
//the first list is one node longer than the second list if the source list is of odd length
void alternatingSplit(List sourceList, List firstList, List secondList) {

   assert(sourceList != NULL && firstList != NULL && secondList != NULL);
   assert(isListEmpty(firstList) == TRUE && isListEmpty(secondList) == TRUE);

   //handles short source lists
   if (sourceList->length < 2) {
      if (sourceList->length == 1) insertAtHead(firstList, sourceList->head->data);
      return;
   }

   unsigned long i = 0; //keeps track of how many nodes have been processed

   //copies nodes from the source list to the front and back lists
   for (link curr = sourceList->head; curr != NULL; curr = curr->next) {
      if (i++ % 2 == 0) {
         insertAtTail(firstList, curr->data);
      } else {
         insertAtTail(secondList, curr->data);
      }
   }

}

//joins two lists by linking the nodes from the second list (in order) to the tail of the first
List concatenate(List l1, List l2) {

   assert(l1 != NULL && l2 != NULL);
   List new = copyList(l1);
   for (link curr = l2->head; curr != NULL; curr = curr->next) insertAtTail(new, curr->data);
   return new;
}

//combines two lists in sorted (ascending) order
List sortedMerge(List l1, List l2) {

   assert(l1 != NULL && l2 != NULL);
   List new = createList();
   link curr;
   for (curr = l1->head; curr != NULL; curr = curr->next) sortedInsert(new, curr->data);
   for (curr = l2->head; curr != NULL; curr = curr->next) sortedInsert(new, curr->data);
   return new;
}

//merges two given lists in a pairwise combination
//if the lists are not of equal length, the excess nodes are appended to the resulting list
List zipLists(List l1, List l2) {

   assert(l1 != NULL && l2 != NULL);
   List new = createList();

   //selects the longer of the two lists as first in each pair of nodes in the new list
   link curr1 = (l1->length > l2->length) ? l1->head : l2->head;
   link curr2 = (l1->length > l2->length) ? l2->head : l1->head;

   //performs a pairwise merge of the common length of the two lists
   while (curr1 != NULL && curr2 != NULL) {
      insertAtTail(new, curr1->data);
      insertAtTail(new, curr2->data);
      curr1 = curr1->next;
      curr2 = curr2->next;
   }

   //inserts the remaining nodes at the end of the new list
   while (curr1 != NULL) {
      insertAtTail(new, curr1->data);
      curr1 = curr1->next;
   }

   return new;
}

//creates and returns a new node with given data
static link createNode(item data) {

   link new = malloc(sizeof(node));
   assert(new != NULL);
   new->data = copy(data);
   new->next = NULL;
   return new;
}

//recursively performs the fold operation on a given list
static item doFold(link curr, item (*f)(item, item), item identity) {

   item result, temp;
   if (curr->next != NULL) {
      temp = doFold(curr->next, f, identity);
      result = f(temp, curr->data);
      del(temp);
   } else {
      result = f(curr->data, identity);
   }
   return result;
}
