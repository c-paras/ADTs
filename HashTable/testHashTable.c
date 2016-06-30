/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 10 February 2016
Last Revision: 26 February 2016
Description: This program makes assertions to test HashTable.c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "bool.h"
#include "item.h"
#include "HashTable.h"

int main(int argc, char *argv[]) {

   //tests hash table initialisation
   printf("Testing hash table initialisation:\n");
   HashTable ht = createHashTable(10);
   assert(ht != NULL);
   assert(getHashTableSize(ht) == 0);
   assert(isHashTableEmpty(ht) == TRUE);
   printf("Empty hash table:\n");
   showHashTable(ht);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests insertHashElement() and getHashtableSize()
   printf("Testing insertHashElement() and getHashTableSize():\n");
   insertHashElement(ht, "0123456789");
   assert(getHashTableSize(ht) == 1);
   assert(isHashTableEmpty(ht) == FALSE);
   insertHashElement(ht, "hello world");
   assert(getHashTableSize(ht) == 2);
   insertHashElement(ht, "qwertyuiop");
   assert(getHashTableSize(ht) == 3);
   insertHashElement(ht, "666");
   assert(getHashTableSize(ht) == 4);
   insertHashElement(ht, "42");
   assert(getHashTableSize(ht) == 5);
   insertHashElement(ht, "ABC");
   assert(getHashTableSize(ht) == 6);
   insertHashElement(ht, "!@#$%^&*()");
   assert(getHashTableSize(ht) == 7);
   insertHashElement(ht, "{[()]}");
   assert(getHashTableSize(ht) == 8);
   insertHashElement(ht, "666"); //re-inserts existing item
   assert(getHashTableSize(ht) == 8);
   insertHashElement(ht, "_---_");
   assert(getHashTableSize(ht) == 9);
   insertHashElement(ht, "QWERTY");
   assert(getHashTableSize(ht) == 10);
   insertHashElement(ht, "173");
   assert(getHashTableSize(ht) == 11);
   insertHashElement(ht, "-28");
   assert(getHashTableSize(ht) == 12);
   insertHashElement(ht, "3.14");
   assert(getHashTableSize(ht) == 13);
   insertHashElement(ht, "hash");
   assert(getHashTableSize(ht) == 14);
   insertHashElement(ht, "0");
   assert(getHashTableSize(ht) == 15);
   insertHashElement(ht, "0"); //re-inserts existing item
   assert(getHashTableSize(ht) == 15);
   insertHashElement(ht, "ABC"); //re-inserts existing item
   assert(getHashTableSize(ht) == 15);
   printf("Hash table containing 15 items:\n");
   showHashTable(ht);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getHashTableElement()
   printf("Testing getHashTableElement():\n");
   assert(isHashTableEmpty(ht) == FALSE);
   assert(getHashTableElement(ht, "1") == NULL);
   assert(getHashTableElement(ht, "-15") == NULL);
   assert(getHashTableElement(ht, "/etc/shadow") == NULL);
   assert(getHashTableElement(ht, "ht&t") == NULL);
   assert(getHashTableElement(ht, "zzzzzzz") == NULL);
   assert(getHashTableElement(ht, "~~~~~~~~~~") == NULL);
   assert(getHashTableElement(ht, "====") == NULL);
   assert(getHashTableElement(ht, "^(_)^") == NULL);
   assert(getHashTableElement(ht, "@#*") == NULL);
   assert(getHashTableElement(ht, "asdvbnm") == NULL);
   assert(getHashTableElement(ht, "pvnqrty") == NULL);
   assert(getHashTableElement(ht, "cdolu") == NULL);
   assert(getHashTableElement(ht, "qwerty") == NULL);
   assert(getHashTableElement(ht, "hash table") == NULL);
   assert(getHashTableElement(ht, "#!/bin/sh") == NULL);
   assert(strcmp(*getHashTableElement(ht, "0123456789"), "0123456789") == 0);
   assert(strcmp(*getHashTableElement(ht, "hello world"), "hello world") == 0);
   assert(strcmp(*getHashTableElement(ht, "qwertyuiop"), "qwertyuiop") == 0);
   assert(strcmp(*getHashTableElement(ht, "666"), "666") == 0);
   assert(strcmp(*getHashTableElement(ht, "42"), "42") == 0);
   assert(strcmp(*getHashTableElement(ht, "ABC"), "ABC") == 0);
   assert(strcmp(*getHashTableElement(ht, "!@#$%^&*()"), "!@#$%^&*()") == 0);
   assert(strcmp(*getHashTableElement(ht, "{[()]}"), "{[()]}") == 0);
   assert(strcmp(*getHashTableElement(ht, "_---_"), "_---_") == 0);
   assert(strcmp(*getHashTableElement(ht, "QWERTY"), "QWERTY") == 0);
   assert(strcmp(*getHashTableElement(ht, "173"), "173") == 0);
   assert(strcmp(*getHashTableElement(ht, "-28"), "-28") == 0);
   assert(strcmp(*getHashTableElement(ht, "3.14"), "3.14") == 0);
   assert(strcmp(*getHashTableElement(ht, "hash"), "hash") == 0);
   assert(strcmp(*getHashTableElement(ht, "0"), "0") == 0);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests removeHashElement()
   printf("Testing removeHashElement():\n");
   assert(isHashTableEmpty(ht) == FALSE);
   removeHashElement(ht, "QWERTY");
   assert(getHashTableSize(ht) == 14);
   removeHashElement(ht, "0123456789");
   assert(getHashTableSize(ht) == 13);
   removeHashElement(ht, "{[()]}");
   assert(getHashTableSize(ht) == 12);
   removeHashElement(ht, "hash");
   assert(getHashTableSize(ht) == 11);
   removeHashElement(ht, "0");
   assert(getHashTableSize(ht) == 10);
   removeHashElement(ht, "ABC");
   assert(getHashTableSize(ht) == 9);
   removeHashElement(ht, "666");
   assert(getHashTableSize(ht) == 8);
   removeHashElement(ht, "3.14");
   assert(getHashTableSize(ht) == 7);
   removeHashElement(ht, "!@#$%^&*()");
   assert(getHashTableSize(ht) == 6);
   insertHashElement(ht, "9999");
   assert(getHashTableSize(ht) == 7);
   removeHashElement(ht, "_---_");
   assert(getHashTableSize(ht) == 6);
   removeHashElement(ht, "173");
   assert(getHashTableSize(ht) == 5);
   removeHashElement(ht, "qwertyuiop");
   assert(getHashTableSize(ht) == 4);
   assert(getHashTableElement(ht, "####") == NULL);
   removeHashElement(ht, "####"); //"removes" non-existent item
   assert(getHashTableSize(ht) == 4);
   assert(getHashTableElement(ht, "$$$") == NULL);
   removeHashElement(ht, "$$$"); //"removes" non-existent item
   assert(getHashTableSize(ht) == 4);
   removeHashElement(ht, "hello world");
   assert(getHashTableSize(ht) == 3);
   removeHashElement(ht, "-28");
   assert(getHashTableSize(ht) == 2);
   removeHashElement(ht, "9999");
   assert(getHashTableSize(ht) == 1);
   removeHashElement(ht, "42");
   assert(getHashTableSize(ht) == 0);
   assert(getHashTableElement(ht, "42") == NULL);
   removeHashElement(ht, "42"); //"removes" non-existent item
   assert(getHashTableSize(ht) == 0);
   assert(isHashTableEmpty(ht) == TRUE);
   insertHashElement(ht, "633");
   assert(getHashTableSize(ht) == 1);
   assert(isHashTableEmpty(ht) == FALSE);
   insertHashElement(ht, "hash table");
   assert(getHashTableSize(ht) == 2);
   printf("Hash table containing 2 items:\n");
   showHashTable(ht);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests hash table expansion
   printf("Testing hash table expansion:\n");
   assert(isHashTableEmpty(ht) == FALSE);
   int i;
   for (i = 0; i < 90; i++) {
      char str[3];
      sprintf(str, "%d", i);
      insertHashElement(ht, str);
      assert(getHashTableSize(ht) == 3 + i);
      assert(isHashTableEmpty(ht) == FALSE);
   }
   for (i = 0; i < 90; i++) {
      char str[3];
      sprintf(str, "%d", i);
      assert(strcmp(*getHashTableElement(ht, str), str) == 0);
   }
   assert(strcmp(*getHashTableElement(ht, "633"), "633") == 0);
   assert(strcmp(*getHashTableElement(ht, "hash table"), "hash table") == 0);
   int size = getHashTableSize(ht);
   for (i = 0; i < 40; i++) {
      char str[3];
      sprintf(str, "%d", i);
      removeHashElement(ht, str);
      assert(getHashTableSize(ht) == size - i - 1);
      assert(isHashTableEmpty(ht) == FALSE);
   }
   for (i = 40; i < 90; i++) {
      char str[3];
      sprintf(str, "%d", i);
      assert(strcmp(*getHashTableElement(ht, str), str) == 0);
   }
   assert(strcmp(*getHashTableElement(ht, "633"), "633") == 0);
   assert(strcmp(*getHashTableElement(ht, "hash table"), "hash table") == 0);
   printf("Testing completed: UNIT COMPLIES\n\n");

   disposeHashTable(ht);
   printf("Testing completed: PROGRAM COMPLIES\n");
   return EXIT_SUCCESS;
}
