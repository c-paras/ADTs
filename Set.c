/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This program performs operations on an abstract set data type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Set.h"
#include "bool.h"
#include "item.h"

typedef struct node *link;

typedef struct node {
   item data;
   link next;
} node;

//sorted list-like concrete representation of set
typedef struct set {
   link head, tail;
   unsigned long numElements;
} set;

//creates and returns a new empty set
Set createSet(void) {

   Set new = malloc(sizeof(set));
   assert(new != NULL);
   new->head = new->tail = NULL;
   new->numElements = 0;
   return new;
}

//returns an exact copy of a given set
Set copySet(Set s) {

   assert(s != NULL);
   Set copy = createSet();
   for (link curr = s->head; curr != NULL; curr = curr->next) insertElement(copy, curr->data);
   return copy;
}

//frees all memory associated with a given set
void disposeSet(Set s) {

   assert(s != NULL);
   if (isEmptySet(s) == TRUE) {
      free(s);
      return;
   }

   //recursively removes all elements in the given set
   link temp = s->head;
   s->head = temp->next;
   del(temp->data);
   free(temp);
   disposeSet(s);
}

//inserts distinct elements into a given set
void insertElement(Set s, item data) {

   assert(s != NULL);

   //adds only distinct elements to set
   if (isElement(s, data) == FALSE) {
      link new = malloc(sizeof(node));
      assert(new != NULL);
      new->data = copy(data);

      //inserts element in sorted order
      if (isEmptySet(s) == TRUE) {
         new->next = NULL;
         s->head = s->tail = new;
      } else if (lt(data, s->head->data)) {
         new->next = s->head;
         s->head = new;
      } else if (lt(s->tail->data, data)) {
         new->next = NULL;
         s->tail->next = new;
         s->tail = new;
      } else {
         for (link curr = s->head; curr->next != NULL; curr = curr->next) {
            if (lt(curr->data, data) && gt(curr->next->data, data)) {
               new->next = curr->next;
               curr->next = new;
            }
         }
      }

      s->numElements++;
   }

}

//removes the given element from the given set if it exists
void removeElement(Set s, item data) {

   assert(s != NULL);
   if (isEmptySet(s) == TRUE) return;

   //removes element if at head or tail
   if (eq(s->head->data, data)) {
      link temp = s->head;
      s->head = s->head->next;
      del(temp->data);
      free(temp);
      s->numElements--;
      if (s->numElements == 0) s->head = s->tail = NULL;
      return;
   } else if (eq(s->tail->data, data)) {
      link curr = s->head;
      link prev = curr;
      while (curr->next != NULL) {prev = curr; curr = curr->next;}
      del(s->tail->data);
      free(s->tail);
      prev->next = NULL;
      s->tail = prev;
      s->numElements--;
      if (s->numElements == 0) s->head = s->tail = NULL;
      return;
   }

   //locates and removes the specified element
   for (link curr = s->head; curr->next != NULL; curr = curr->next) {
      if (eq(curr->next->data, data)) {
         link temp = curr->next;
         curr->next = temp->next;
         del(temp->data);
         free(temp);
         s->numElements--;
         if (s->numElements == 0) s->head = s->tail = NULL;
         return;
      }
   }

}

//displays the elements contained in a given set in order
void showSet(Set s) {

   assert(s != NULL);

   //prints an empty set as ∅
   if (isEmptySet(s) == TRUE) {
      printf("\u2205\n");
      return;
   } else {
      printf("{");
   }

   for (link curr = s->head; curr != NULL; curr = curr->next) {
      show(curr->data);
      if (curr->next != NULL) printf(", ");
   }
   printf("}\n");
}

//returns whether a given element belongs to a given set
bool isElement(Set s, item data) {

   assert(s != NULL);

   //performs a linear scan of the set
   for (link curr = s->head; curr != NULL; curr = curr->next) {
      if (eq(curr->data, data)) return TRUE;
   }

   return FALSE;
}

//returns the minimum element of a given set
item getSetMin(Set s) {

   assert(s != NULL);
   assert(isEmptySet(s) == FALSE); //undefined for an empty set
   return s->head->data;
}

//returns the maximum element of a given set
item getSetMax(Set s) {

   assert(s != NULL);
   assert(isEmptySet(s) == FALSE); //undefined for an empty set
   return s->tail->data;
}

//returns the number of elements in a given set
unsigned long getSetCardinality(Set s) {

   assert(s != NULL);
   return s->numElements;
}

//indicates whether a given set is an empty set
bool isEmptySet(Set s) {

   assert(s != NULL);
   return s->head == NULL;
}

//obtains and returns the union of any two given sets
Set getUnion(Set s, Set t) {

   assert(s != NULL && t != NULL);
   if (isEmptySet(s) == TRUE) return copySet(t);
   if (isEmptySet(t) == TRUE) return copySet(s);

   //combines the elements of the given sets
   Set setUnion = copySet(s);
   for (link curr = t->head; curr != NULL; curr = curr->next) insertElement(setUnion, curr->data);

   return setUnion;
}

//obtains and returns the intersection of any two given sets
Set getIntersection(Set s, Set t) {

   assert(s != NULL && t != NULL);
   if (isEmptySet(s) == TRUE || isEmptySet(t) == TRUE) return createSet();

   //finds common elements of the given sets
   Set intersection = createSet();
   for (link curr = s->head; curr != NULL; curr = curr->next) {
      if (isElement(t, curr->data) == TRUE) insertElement(intersection, curr->data);
   }

   return intersection;
}

//obtains and returns the difference between any two given sets
Set getDifference(Set s, Set t) {

   assert(s != NULL && t != NULL);
   Set diff = copySet(s);
   for (link curr = t->head; curr != NULL; curr = curr->next) removeElement(diff, curr->data);
   return diff;
}

//determines whether a pair of given sets are equivalent
bool isEquivalent(Set s, Set t) {

   assert(s != NULL && t != NULL);
   if (getSetCardinality(s) != getSetCardinality(t)) return FALSE;

   //checks whether all elements are identical
   link sCurr = s->head;
   link tCurr = t->head;
   while (sCurr != NULL) {
      if (!eq(sCurr->data, tCurr->data)) return FALSE;
      sCurr = sCurr->next;
      tCurr = tCurr->next;
   }

   return TRUE;
}

//determines whether a given set is a subset of another given set
bool isSubset(Set s, Set t) {

   assert(s != NULL && t != NULL);
   if (isEmptySet(s) == TRUE) return TRUE;
   if (getSetCardinality(s) > getSetCardinality(t)) return FALSE;

   //checks that for all x ∈ s, x ∈ t
   for (link curr = s->head; curr != NULL; curr = curr->next) {
      if (isElement(t, curr->data) == FALSE) return FALSE;
   }

   return TRUE;
}

//determines whether a given set is a proper subset of another given set
bool isProperSubset(Set s, Set t) {

   assert(s != NULL && t != NULL);
   if (isSubset(s, t) == FALSE) return FALSE;
   return !(isEquivalent(s, t));
}

//determines whether a pair of given sets is disjoint
bool isDisjointPair(Set s, Set t) {

   assert(s != NULL && t != NULL);

   //uses the definition of disjoint sets: s ∩ t = ∅
   Set intersection = getIntersection(s, t);
   bool isEmpty = isEmptySet(intersection);
   disposeSet(intersection);
   return isEmpty == TRUE;
}
