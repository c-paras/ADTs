/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 4 February 2016
Last Revision: 26 February 2016
Description: This program performs operations on an abstract multiset (bag) data type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Bag.h"
#include "bool.h"
#include "item.h"

#define PREVENT_OVERFLOW if (multiplicity > oldMultiplicity) multiplicity = oldMultiplicity;
#define UPDATE_BAG b->dimension--; \
        b->cardinality -= oldMultiplicity; \
        if (b->cardinality == 0) b->head = b->tail = NULL; \
        return;

typedef struct node *link;

typedef struct node {
   item data;
   unsigned long multiplicity;
   link next;
} node;

//sorted list-like concrete representation of multiset
typedef struct multiset {
   link head, tail;
   unsigned long dimension, cardinality;
} multiset;

static link getMember(Bag b, item data);

//creates and returns a new empty bag
Bag createBag(void) {

   Bag new = malloc(sizeof(multiset));
   assert(new != NULL);
   new->head = new->tail = NULL;
   new->dimension = new->cardinality = 0;
   return new;
}

//returns an exact copy of a given bag
Bag copyBag(Bag b) {

   assert(b != NULL);
   Bag copy = createBag();
   for (link curr = b->head; curr != NULL; curr = curr->next) {
      insertMember(copy, curr->data, curr->multiplicity);
   }
   return copy;
}

//frees all memory associated with a given bag
void disposeBag(Bag b) {

   assert(b != NULL);
   if (isEmptyBag(b) == TRUE) {
      free(b);
      return;
   }

   //recursively removes all members in the given bag
   link temp = b->head;
   b->head = temp->next;
   del(temp->data);
   free(temp);
   disposeBag(b);
}

//inserts the given item into a given bag with given multiplicity
//increases the multiplicity of the item if it already exists
void insertMember(Bag b, item data, unsigned int multiplicity) {

   assert(b != NULL);
   if (multiplicity == 0) return;

   //updates the existing member if it exists
   link member = getMember(b, data);
   if (member != NULL) {
      member->multiplicity += multiplicity;
      b->cardinality += multiplicity;
      return;
   }

   link new = malloc(sizeof(node));
   assert(new != NULL);
   new->data = copy(data);
   new->multiplicity = multiplicity;

   //inserts member in sorted order
   if (isEmptyBag(b) == TRUE) {
      new->next = NULL;
      b->head = b->tail = new;
   } else if (lt(data, b->head->data)) {
      new->next = b->head;
      b->head = new;
   } else if (lt(b->tail->data, data)) {
      new->next = NULL;
      b->tail->next = new;
      b->tail = new;
   } else {
      for (link curr = b->head; curr->next != NULL; curr = curr->next) {
         if (lt(curr->data, data) && gt(curr->next->data, data)) {
            new->next = curr->next;
            curr->next = new;
         }
      }
   }

   b->dimension++;
   b->cardinality += multiplicity;
}

//reduces the multiplicity of the given member by the given multiplicity
//removes the member if the resultant multiplicity is non-positive
void removeMember(Bag b, item data, unsigned int multiplicity) {

   assert(b != NULL);
   if (multiplicity == 0) return;
   if (isEmptyBag(b) == TRUE) return;

   //"removes" member if at head or tail
   if (eq(b->head->data, data)) {
      unsigned long oldMultiplicity = b->head->multiplicity;
      PREVENT_OVERFLOW;
      b->head->multiplicity -= multiplicity;
      if (b->head->multiplicity > 0) {b->cardinality -= multiplicity; return;}
      link temp = b->head;
      b->head = b->head->next;
      del(temp->data);
      free(temp);
      UPDATE_BAG;
   } else if (eq(b->tail->data, data)) {
      unsigned long oldMultiplicity = b->tail->multiplicity;
      PREVENT_OVERFLOW;
      b->tail->multiplicity -= multiplicity;
      if (b->tail->multiplicity > 0) {b->cardinality -= multiplicity; return;}
      link curr = b->head;
      link prev = curr;
      while (curr->next != NULL) {prev = curr; curr = curr->next;}
      del(b->tail->data);
      free(b->tail);
      prev->next = NULL;
      b->tail = prev;
      UPDATE_BAG;
   }

   //locates and "removes" the specified member
   for (link curr = b->head; curr->next != NULL; curr = curr->next) {
      if (eq(curr->next->data, data)) {
         unsigned long oldMultiplicity = curr->next->multiplicity;
         PREVENT_OVERFLOW;
         curr->next->multiplicity -= multiplicity;
         if (curr->next->multiplicity > 0) {b->cardinality -= multiplicity; return;}
         link temp = curr->next;
         curr->next = temp->next;
         del(temp->data);
         free(temp);
         UPDATE_BAG;
      }
   }

}

//displays the members contained in a given bag in order
void showBag(Bag b) {

   assert(b != NULL);

   //prints an empty bag as ∅
   if (isEmptyBag(b) == TRUE) {
      printf("\u2205\n");
      return;
   } else {
      printf("{");
   }

   unsigned long i;
   for (link curr = b->head; curr != NULL; curr = curr->next) {

      //prints current member at least once
      for (i = 0; i < curr->multiplicity; i++) {
         show(curr->data);
         if (i < curr->multiplicity - 1) printf(", ");
      }

      if (curr->next != NULL) printf(", ");
   }
   printf("}\n");
}

//returns whether a given member belongs to a given bag
bool isMember(Bag b, item data) {

   assert(b != NULL);

   //performs a linear scan of the bag
   for (link curr = b->head; curr != NULL; curr = curr->next) {
      if (eq(curr->data, data)) return TRUE;
   }

   return FALSE;
}

//indicates whether a given bag is an empty bag
bool isEmptyBag(Bag b) {

   assert(b != NULL);
   return b->head == NULL;
}

//indicates whether a given bag is a set
bool isSet(Bag b) {

   for (link curr = b->head; curr != NULL; curr = curr->next) {
      if (curr->multiplicity > 1) return FALSE;
   }
   return TRUE;
}

//returns the minimum member of a given bag
item getBagMin(Bag b) {

   assert(b != NULL);
   assert(isEmptyBag(b) == FALSE); //undefined for an empty bag
   return b->head->data;
}

//returns the maximum member of a given bag
item getBagMax(Bag b) {

   assert(b != NULL);
   assert(isEmptyBag(b) == FALSE); //undefined for an empty bag
   return b->tail->data;
}

//returns the number of distinct members in a given bag (cardinality of the root set)
unsigned long getBagDimension(Bag b) {

   assert(b != NULL);
   return b->dimension;
}

//returns the total number of members (with multiplicity) in a given bag
unsigned long getBagCardinality(Bag b) {

   assert(b != NULL);
   return b->cardinality;
}

//returns the multiplicity of a given member in a given bag
unsigned long getMultiplicity(Bag b, item data) {

   assert(b != NULL);
   link member = getMember(b, data);
   if (member != NULL) return member->multiplicity;
   return 0;
}

//returns the corresponding root set of the given multiset
Bag getRootSet(Bag b) {

   assert(b != NULL);
   Bag new = createBag();
   for (link curr = b->head; curr != NULL; curr = curr->next) insertMember(new, curr->data, 1);
   return new;
}

//obtains and returns the multiset union of any two given bags
Bag getMultisetUnion(Bag b, Bag c) {

   assert(b != NULL && c != NULL);
   if (isEmptyBag(b) == TRUE) return copyBag(c);
   if (isEmptyBag(c) == TRUE) return copyBag(b);

   //combines the members of the given bags with maximal multiplicity
   Bag bagUnion = copyBag(b);
   for (link curr = c->head; curr != NULL; curr = curr->next) {
      unsigned long oldMultiplicity = getMultiplicity(bagUnion, curr->data);
      unsigned long multiplicity, newMultiplicity = curr->multiplicity;
      multiplicity = (oldMultiplicity > newMultiplicity) ? oldMultiplicity : newMultiplicity;
      multiplicity -= oldMultiplicity;
      insertMember(bagUnion, curr->data, multiplicity);
   }

   return bagUnion;
}

//obtains and returns the multiset intersection of any two given bags
Bag getMultisetIntersection(Bag b, Bag c) {

   assert(b != NULL && c != NULL);
   if (isEmptyBag(b) == TRUE || isEmptyBag(c) == TRUE) return createBag();

   //finds common members of the given bags with minimal multiplicity
   Bag intersection = createBag();
   for (link curr = b->head; curr != NULL; curr = curr->next) {
      if (isMember(c, curr->data) == TRUE) {
         unsigned long cMultiplicity = getMultiplicity(c, curr->data);
         unsigned long multiplicity, bMultiplicity = curr->multiplicity;
         multiplicity = (bMultiplicity > cMultiplicity) ? cMultiplicity : bMultiplicity;
         insertMember(intersection, curr->data, multiplicity);
      }
   }

   return intersection;
}

//obtains and returns the multiset difference between any two given bags
Bag getMultisetDifference(Bag b, Bag c) {

   assert(b != NULL && c != NULL);
   Bag diff = copyBag(b);
   for (link curr = c->head; curr != NULL; curr = curr->next) {
      removeMember(diff, curr->data, curr->multiplicity);
   }
   return diff;
}

//obtains and returns the multiset sum for the given multisets
Bag getMultisetSum(Bag b, Bag c) {

   assert(b != NULL && c != NULL);
   if (isEmptyBag(b) == TRUE) return copyBag(c);
   if (isEmptyBag(c) == TRUE) return copyBag(b);

   //combines the members of the given bags with combined multiplicity
   Bag bagSum = copyBag(b);
   for (link curr = c->head; curr != NULL; curr = curr->next) {
      insertMember(bagSum, curr->data, curr->multiplicity);
   }

   return bagSum;
}

//determines whether a pair of given bags are identical
bool isIdentical(Bag b, Bag c) {

   assert(b != NULL && c != NULL);
   if (getBagCardinality(b) != getBagCardinality(c)) return FALSE;

   //checks whether all members are identical and have corresponding multiplicities
   link sCurr = b->head;
   link tCurr = c->head;
   while (sCurr != NULL) {
      if (!eq(sCurr->data, tCurr->data)) return FALSE;
      if (sCurr->multiplicity != tCurr->multiplicity) return FALSE;
      sCurr = sCurr->next;
      tCurr = tCurr->next;
   }

   return TRUE;
}

//determines whether a given bag is a submultiset of another given bag
bool isSubmultiset(Bag b, Bag c) {

   assert(b != NULL && c != NULL);
   if (isEmptyBag(b) == TRUE) return TRUE;
   if (getBagCardinality(b) > getBagCardinality(c)) return FALSE;

   //checks that for all x ∈ b, x ∈ c and ν_b(x) <= ν_c(x)
   for (link curr = b->head; curr != NULL; curr = curr->next) {
      if (isMember(c, curr->data) == FALSE) return FALSE;
      if (getMultiplicity(c, curr->data) < curr->multiplicity) return FALSE;
   }

   return TRUE;
}

//determines whether a given bag is a strict (proper) submultiset of another given bag
bool isStrictSubmultiset(Bag b, Bag c) {

   assert(b != NULL && c != NULL);
   if (isSubmultiset(b, c) == FALSE) return FALSE;
   return !(isIdentical(b, c));
}

//determines whether a pair of given bags is disjoint
bool isDisjointMultisetPair(Bag b, Bag c) {

   assert(b != NULL && c != NULL);

   //uses the definition of disjoint multisets: b ∩ c = ∅
   Bag intersection = getMultisetIntersection(b, c);
   bool isEmpty = isEmptyBag(intersection);
   disposeBag(intersection);
   return isEmpty == TRUE;
}

//returns a pointer to the member corresponding to the given item or NULL
static link getMember(Bag b, item data) {

   assert(b != NULL);
   for (link curr = b->head; curr != NULL; curr = curr->next) {
      if (eq(curr->data, data)) return curr;
   }

   return NULL;
}
