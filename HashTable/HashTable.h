/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 10 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for HashTable.c.
*/

#include "bool.h"
#include "item.h"

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct hashTable *HashTable;

//hash table initialisation
HashTable createHashTable(unsigned long numSlots);
void disposeHashTable(HashTable ht);

//hash table progression
void insertHashElement(HashTable ht, item data);
void removeHashElement(HashTable ht, key k);

//hash table query
void showHashTable(HashTable ht);
item *getHashTableElement(HashTable ht, key k);
unsigned long getHashTableSize(HashTable ht);
bool isHashTableEmpty(HashTable ht);

#endif
