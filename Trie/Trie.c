/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 22 February 2016
Last Revision: 26 February 2016
Description: This program performs operations on an abstract trie data type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "item.h"
#include "Trie.h"

typedef struct node *link;

typedef struct node {
   char character; //part of a key
   bool endsKey;
   bool isDeleted;
   item data;
   link child, sibling;
} node;

//tree-like concrete representation of trie
typedef struct trie {
   link first;
   unsigned long numKeys;
} trie;

static link createNode(char character);

//creates and returns a new empty trie
Trie createTrie(void) {

   Trie new = malloc(sizeof(trie));
   assert(new != NULL);
   new->first = NULL;
   new->numKeys = 0;
   return new;
}

//frees all memory associated with a given trie
void disposeTrie(Trie t) {

   assert(t != NULL);
   link *siblings = malloc(sizeof(link));
   assert(siblings != NULL);
   if (t->first != NULL) siblings[0] = t->first;
   unsigned long numSiblings = 1;
   link curr = t->first, temp;

   //deallocates each node in the trie
   while (numSiblings > 0) {
      curr = siblings[--numSiblings];

      //deallocates all children linked from current sibling
      while (curr != NULL) {
         if (curr->sibling != NULL) {
            siblings = realloc(siblings, ++numSiblings * sizeof(link));
            assert(siblings != NULL);
            siblings[numSiblings - 1] = curr->sibling;
         }
         temp = curr;
         curr = temp->child;
         if (temp->endsKey == TRUE) del(temp->data);
         free(temp);
      }

   }

   free(siblings);
   free(t);
}

//updates or inserts a given item into a given trie
//assumes that keys are strings
void insertItem(Trie t, item data) {

   assert(t != NULL);
   key str = key(data);
   assert(str != NULL);
   link curr = t->first, prev = NULL;
   unsigned long i = 0;
   bool nextChild = FALSE;

   //traverses trie for correct location of insertion
   while (str[i] != '\0') {
      while (curr != NULL && curr->character != str[i]) {
         nextChild = 0;
         prev = curr;
         curr = curr->sibling;
      }
      if (curr == NULL) {
         link new = createNode(str[i]);

         //links new chain of nodes to rest of trie
         if (prev == NULL) {
            t->first = new;
         } else {
            if (nextChild == FALSE) prev->sibling = new;
            if (nextChild == TRUE)  prev->child   = new;
         }

         if (str[++i] == '\0') {
            new->endsKey = TRUE;
            new->data = copy(data);
         }
         prev = new;

         //adds remaining nodes corresponding to remaining parts of key
         for (unsigned long j = i; str[j] != '\0'; j++) {
            new = createNode(str[j]);
            prev->child = new;
            if (str[j + 1] == '\0') {
               new->endsKey = TRUE;
               new->data = copy(data);
            }
            prev = new;
         }

         t->numKeys++;
         return;
      } else {
         prev = curr;
         curr = curr->child;
         nextChild = TRUE;
      }
      i++;
   }

   //updates existing data
   if (prev->endsKey == TRUE && prev->isDeleted == FALSE) {
      del(prev->data);
      prev->data = copy(data);
   }

   //reassigns non-finishing node of longer key
   if (prev->endsKey == FALSE) {
      prev->data = copy(data);
      prev->endsKey = TRUE;
      t->numKeys++;
   }

   //re-inserts a previously deleted item
   if (prev->endsKey == TRUE && prev->isDeleted == TRUE) {
      del(prev->data);
      prev->data = copy(data);
      prev->isDeleted = FALSE;
      t->numKeys++;
   }

}

//removes the given item from the given trie if it exists
void removeItem(Trie t, key k) {

   assert(t != NULL && k != NULL);
   if (isTrieEmpty(t) == TRUE) return;
   link curr = t->first, prev = NULL;
   unsigned long i = 0;

   //traverses trie in search for ending node
   while (k[i] != '\0') {
      while (curr != NULL && curr->character != k[i]) {
         prev = curr;
         curr = curr->sibling;
      }
      if (curr == NULL) return; //key not present
      prev = curr;
      curr = curr->child;
      i++;
   }

   //"removes" key from trie
   if (prev->endsKey == TRUE && prev->isDeleted == FALSE) {
      prev->isDeleted = TRUE;
      t->numKeys--;
   }

}

//displays all the keys in the given trie
void showTrie(Trie t) {

   assert(t != NULL);
   if (isTrieEmpty(t) == TRUE) return;
   link *siblings = malloc(sizeof(link));
   assert(siblings != NULL);
   if (t->first != NULL) siblings[0] = t->first;
   unsigned long numSiblings = 1;

   //prints all keys by traversing through all nodes
   while (numSiblings > 0) {
      for (link curr = siblings[--numSiblings]; curr != NULL; curr = curr->child) {
         if (curr->sibling != NULL) {
            siblings = realloc(siblings, ++numSiblings * sizeof(link));
            assert(siblings != NULL);
            siblings[numSiblings - 1] = curr->sibling;
         }
         if (curr->endsKey && curr->isDeleted == FALSE) printf("%s\n", key(curr->data));
      }
   }

   free(siblings);
}

//returns a pointer to the specified item if it exists in the given trie
item *getItemInTrie(Trie t, key k) {

   assert(t != NULL && k != NULL);
   link curr = t->first, prev = NULL;
   unsigned long i = 0;

   //traverses relevant nodes in the trie
   while (k[i] != '\0') {
      while (curr != NULL && curr->character != k[i]) {
         prev = curr;
         curr = curr->sibling;
      }
      if (curr == NULL) return NULL;
      prev = curr;
      curr = curr->child;
      i++;
   }

   //returns pointer if item found and not marked as deleted
   if (prev->endsKey == TRUE && prev->isDeleted == FALSE) {
      return &prev->data;
   } else {
      return NULL;
   }

}

//returns the number of keys in a given trie
unsigned long getTrieSize(Trie t) {

   assert(t != NULL);
   return t->numKeys;
}

//indicates whether a given trie is empty
bool isTrieEmpty(Trie t) {

   assert(t != NULL);
   return t->numKeys == 0;
}

//creates and returns a new node with the given character
static link createNode(char character) {

   link new = malloc(sizeof(node));
   assert(new != NULL);
   new->character = character;
   new->endsKey   = FALSE;
   new->isDeleted = FALSE;
   new->child = new->sibling = NULL;
   return new;
}
