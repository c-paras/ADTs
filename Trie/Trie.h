/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 22 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for Trie.c.
*/

#include "bool.h"
#include "item.h"

#ifndef TRIE_H
#define TRIE_H

typedef struct trie *Trie;

//trie initialisation
Trie createTrie(void);
void disposeTrie(Trie t);

//trie progression
void insertItem(Trie t, item data);
void removeItem(Trie t, key k);

//trie query
void showTrie(Trie t);
item *getItemInTrie(Trie t, key k);
unsigned long getTrieSize(Trie t);
bool isTrieEmpty(Trie t);

#endif
