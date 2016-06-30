/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 10 February 2016
Last Revision: 26 February 2016
Description: This program performs operations on an abstract hash table data type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "HashTable.h"
#include "hash.h"

typedef struct node {
   item data;
   struct node *next;
} *link;

//list array concrete representation of hash table
typedef struct hashTable {
   link *chains; //uses separate chaining as collision resolution strategy
   unsigned long numSlots, numItems;
} hashTable;

static void disposeHashTableChains(HashTable ht);
static void expandHashTable(HashTable ht);

//creates and returns a new empty hash table with a given number of slots
HashTable createHashTable(unsigned long numSlots) {

   assert(numSlots > 0);
   HashTable new = malloc(sizeof(hashTable));
   assert(new != NULL);
   new->chains = malloc(numSlots * sizeof(link));
   assert(new->chains != NULL);
   for (unsigned long i = 0; i < numSlots; i++) new->chains[i] = NULL;
   new->numSlots = numSlots;
   new->numItems = 0;
   return new;
}

//frees all memory associated with a given hash table
void disposeHashTable(HashTable ht) {

   assert(ht != NULL);
   disposeHashTableChains(ht);
   free(ht->chains);
   free(ht);
}

//updates or inserts a given item into a given hash table
void insertHashElement(HashTable ht, item data) {

   assert(ht != NULL);
   if (ht->numItems > 2 * ht->numSlots) expandHashTable(ht);
   unsigned long index = hash(key(data), ht->numSlots);
   for (link curr = ht->chains[index]; curr != NULL; curr = curr->next) {

      //updates existing item
      if (eq(key(curr->data), key(data))) {
         del(curr->data);
         curr->data = copy(data);
         return;
      }

   }

   //inserts new item at head of list
   link new = malloc(sizeof(struct node));
   assert(new != NULL);
   new->data = copy(data);
   new->next = ht->chains[index];
   ht->chains[index] = new;
   ht->numItems++;
}

//removes the given item from the given hash table if it exists
void removeHashElement(HashTable ht, key k) {

   assert(ht != NULL);
   unsigned long index = hash(k, ht->numSlots);
   link prev = NULL;

   //searches for item in the relevant list
   for (link curr = ht->chains[index]; curr != NULL; curr = curr->next) {
      if (eq(key(curr->data), k)) {
         if (prev != NULL) {
            prev->next = curr->next;
         } else {
            ht->chains[index] = curr->next;
         }
         del(curr->data);
         free(curr);
         ht->numItems--;
         return;
      } else {
         prev = curr;
      }
   }

}

//prints the chains of the given hash table in order
void showHashTable(HashTable ht) {

   assert(ht != NULL);
   for (unsigned long i = 0; i < ht->numSlots; i++) {
      printf("Slot %2lu: ", i);

      //prints the corresponding list
      for (link curr = ht->chains[i]; curr != NULL; curr = curr->next) {
         show(curr->data);
         if (curr->next != NULL) printf(", ");
      }

      printf("\n");
   }
}

//returns a pointer to the specified item if it exists in the given hash table
item *getHashTableElement(HashTable ht, key k) {

   assert(ht != NULL);
   unsigned long index = hash(k, ht->numSlots);
   for (link curr = ht->chains[index]; curr != NULL; curr = curr->next) {
      if (eq(key(curr->data), k)) return &curr->data;
   }

   return NULL;
}

//returns the number of inserted items in a given hash table
unsigned long getHashTableSize(HashTable ht) {

   assert(ht != NULL);
   return ht->numItems;
}

//indicates whether a given hash table is empty
bool isHashTableEmpty(HashTable ht) {

   assert(ht != NULL);
   return ht->numItems == 0;
}

//frees all memory associated with the chains of a given hash table
static void disposeHashTableChains(HashTable ht) {

   assert(ht != NULL);
   for (unsigned long i = 0; i < ht->numSlots; i++) {
      link curr = ht->chains[i];
      link temp;

      //frees the nodes in the current list
      while (curr != NULL) {
         temp = curr->next;
         del(curr->data);
         free(curr);
         curr = temp;
      }

   }
}

//doubles the number of available slots in a given hash table
static void expandHashTable(HashTable ht) {

   assert(ht != NULL);
   unsigned long i, numItems = 0;

   //extracts all values from the hash table
   item data[ht->numItems];
   for (i = 0; i < ht->numSlots; i++) {
      for (link curr = ht->chains[i]; curr != NULL; curr = curr->next) {
         data[numItems++] = copy(curr->data);
      }
   }

   //replaces ht->chains with a new empty array
   disposeHashTableChains(ht);
   free(ht->chains);
   ht->numSlots *= 2;
   ht->chains = malloc(ht->numSlots * sizeof(link));
   assert(ht->chains != NULL);
   ht->numItems = 0;
   for (i = 0; i < ht->numSlots; i++) ht->chains[i] = NULL;

   //re-hashes existing data
   for (i = 0; i < numItems; i++) {
      insertHashElement(ht, data[i]);
      del(data[i]);
   }

}
