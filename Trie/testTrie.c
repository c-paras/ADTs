/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 22 February 2016
Last Revision: 26 February 2016
Description: This program makes assertions to test Trie.c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "bool.h"
#include "item.h"
#include "Trie.h"

int main(int argc, char *argv[]) {

   //tests trie initialisation
   printf("Testing trie initialisation:\n");
   Trie t = createTrie();
   assert(t != NULL);
   assert(getTrieSize(t) == 0);
   assert(isTrieEmpty(t) == TRUE);
   printf("Empty trie:\n");
   showTrie(t);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests insertItem() and getTrieSize()
   printf("Testing insertItem() and getTrieSize():\n");
   insertItem(t, "ace");
   assert(getTrieSize(t) == 1);
   assert(isTrieEmpty(t) == FALSE);
   insertItem(t, "east");
   assert(getTrieSize(t) == 2);
   insertItem(t, "aces");
   assert(getTrieSize(t) == 3);
   insertItem(t, "early");
   assert(getTrieSize(t) == 4);
   insertItem(t, "ear");
   assert(getTrieSize(t) == 5);
   insertItem(t, "earl");
   assert(getTrieSize(t) == 6);
   insertItem(t, "size");
   assert(getTrieSize(t) == 7);
   insertItem(t, "apply");
   assert(getTrieSize(t) == 8);
   insertItem(t, "generate");
   assert(getTrieSize(t) == 9);
   insertItem(t, "generate"); //re-inserts existing item
   assert(getTrieSize(t) == 9);
   insertItem(t, "ace"); //re-inserts existing item
   assert(getTrieSize(t) == 9);
   insertItem(t, "ape");
   assert(getTrieSize(t) == 10);
   insertItem(t, "apes");
   assert(getTrieSize(t) == 11);
   insertItem(t, "apes"); //re-inserts existing item
   assert(getTrieSize(t) == 11);
   insertItem(t, "ear"); //re-inserts existing item
   assert(getTrieSize(t) == 11);
   insertItem(t, "app");
   assert(getTrieSize(t) == 12);
   printf("Trie containing 12 keys:\n");
   showTrie(t);
   insertItem(t, "eastern");
   assert(getTrieSize(t) == 13);
   insertItem(t, "earth");
   assert(getTrieSize(t) == 14);
   insertItem(t, "beach");
   assert(getTrieSize(t) == 15);
   insertItem(t, "accept");
   assert(getTrieSize(t) == 16);
   insertItem(t, "earl"); //re-inserts existing item
   assert(getTrieSize(t) == 16);
   insertItem(t, "accept"); //re-inserts existing item
   assert(getTrieSize(t) == 16);
   printf("Trie containing 16 keys:\n");
   showTrie(t);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getItemInTrie()
   printf("Testing getItemInTrie():\n");
   assert(isTrieEmpty(t) == FALSE);
   assert(getItemInTrie(t, "hello") == NULL);
   assert(getItemInTrie(t, "world") == NULL);
   assert(getItemInTrie(t, "ac") == NULL);
   assert(getItemInTrie(t, "acc") == NULL);
   assert(getItemInTrie(t, "acce") == NULL);
   assert(getItemInTrie(t, "accep") == NULL);
   assert(getItemInTrie(t, "ap") == NULL);
   assert(getItemInTrie(t, "appl") == NULL);
   assert(getItemInTrie(t, "ea") == NULL);
   assert(getItemInTrie(t, "eas") == NULL);
   assert(getItemInTrie(t, "eart") == NULL);
   assert(getItemInTrie(t, "siz") == NULL);
   assert(getItemInTrie(t, "0") == NULL);
   assert(getItemInTrie(t, "gen") == NULL);
   assert(getItemInTrie(t, "est") == NULL);
   assert(getItemInTrie(t, "bea") == NULL);
   assert(strcmp(*getItemInTrie(t, "ace"), "ace") == 0);
   assert(strcmp(*getItemInTrie(t, "east"), "east") == 0);
   assert(strcmp(*getItemInTrie(t, "aces"), "aces") == 0);
   assert(strcmp(*getItemInTrie(t, "early"), "early") == 0);
   assert(strcmp(*getItemInTrie(t, "ear"), "ear") == 0);
   assert(strcmp(*getItemInTrie(t, "earl"), "earl") == 0);
   assert(strcmp(*getItemInTrie(t, "size"), "size") == 0);
   assert(strcmp(*getItemInTrie(t, "apply"), "apply") == 0);
   assert(strcmp(*getItemInTrie(t, "generate"), "generate") == 0);
   assert(strcmp(*getItemInTrie(t, "ape"), "ape") == 0);
   assert(strcmp(*getItemInTrie(t, "apes"), "apes") == 0);
   assert(strcmp(*getItemInTrie(t, "app"), "app") == 0);
   assert(strcmp(*getItemInTrie(t, "eastern"), "eastern") == 0);
   assert(strcmp(*getItemInTrie(t, "beach"), "beach") == 0);
   assert(strcmp(*getItemInTrie(t, "earth"), "earth") == 0);
   assert(strcmp(*getItemInTrie(t, "accept"), "accept") == 0);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests removeItem()
   printf("Testing removeItem():\n");
   assert(isTrieEmpty(t) == FALSE);
   removeItem(t, "beach");
   assert(getTrieSize(t) == 15);
   assert(getItemInTrie(t, "beach") == NULL);
   removeItem(t, "ace");
   assert(getTrieSize(t) == 14);
   assert(getItemInTrie(t, "ace") == NULL);
   removeItem(t, "ape");
   assert(getTrieSize(t) == 13);
   assert(getItemInTrie(t, "ape") == NULL);
   removeItem(t, "east");
   assert(getTrieSize(t) == 12);
   assert(getItemInTrie(t, "east") == NULL);
   removeItem(t, "eastern");
   assert(getTrieSize(t) == 11);
   assert(getItemInTrie(t, "eastern") == NULL);
   removeItem(t, "earth");
   assert(getTrieSize(t) == 10);
   assert(getItemInTrie(t, "earth") == NULL);
   printf("Trie containing 10 keys:\n");
   showTrie(t);
   removeItem(t, "apply");
   assert(getTrieSize(t) == 9);
   assert(getItemInTrie(t, "apply") == NULL);
   assert(getItemInTrie(t, "hello") == NULL);
   removeItem(t, "hello"); //"removes" non-existent item
   assert(getTrieSize(t) == 9);
   assert(getItemInTrie(t, "apply") == NULL);
   removeItem(t, "apply"); //"removes" non-existent item
   assert(getTrieSize(t) == 9);
   removeItem(t, "app");
   assert(getTrieSize(t) == 8);
   assert(getItemInTrie(t, "app") == NULL);
   removeItem(t, "accept");
   assert(getTrieSize(t) == 7);
   assert(getItemInTrie(t, "accept") == NULL);
   removeItem(t, "generate");
   assert(getTrieSize(t) == 6);
   assert(getItemInTrie(t, "generate") == NULL);
   removeItem(t, "apes");
   assert(getTrieSize(t) == 5);
   assert(getItemInTrie(t, "apes") == NULL);
   insertItem(t, "apple");
   assert(getTrieSize(t) == 6);
   insertItem(t, "amplify");
   assert(getTrieSize(t) == 7);
   insertItem(t, "earthling");
   assert(getTrieSize(t) == 8);
   removeItem(t, "early");
   assert(getTrieSize(t) == 7);
   assert(getItemInTrie(t, "early") == NULL);
   removeItem(t, "earl");
   assert(getTrieSize(t) == 6);
   assert(getItemInTrie(t, "earl") == NULL);
   removeItem(t, "earl"); //"removes" non-existent item
   assert(getTrieSize(t) == 6);
   assert(getItemInTrie(t, "trie") == NULL);
   removeItem(t, "earl"); //"removes" non-existent item
   assert(getTrieSize(t) == 6);
   removeItem(t, "ear");
   assert(getTrieSize(t) == 5);
   assert(getItemInTrie(t, "ear") == NULL);
   printf("Trie containing 5 keys:\n");
   showTrie(t);
   removeItem(t, "size");
   assert(getTrieSize(t) == 4);
   assert(getItemInTrie(t, "size") == NULL);
   removeItem(t, "apple");
   assert(getTrieSize(t) == 3);
   assert(getItemInTrie(t, "apple") == NULL);
   removeItem(t, "earthling");
   assert(getTrieSize(t) == 2);
   assert(getItemInTrie(t, "earthling") == NULL);
   removeItem(t, "amplify");
   assert(getTrieSize(t) == 1);
   assert(getItemInTrie(t, "amplify") == NULL);
   removeItem(t, "aces");
   assert(getTrieSize(t) == 0);
   assert(getItemInTrie(t, "aces") == NULL);
   assert(isTrieEmpty(t) == TRUE);
   insertItem(t, "cat");
   assert(getTrieSize(t) == 1);
   assert(isTrieEmpty(t) == FALSE);
   insertItem(t, "cap");
   assert(getTrieSize(t) == 2);
   insertItem(t, "bat");
   assert(getTrieSize(t) == 3);
   insertItem(t, "ape");
   assert(getTrieSize(t) == 4);
   insertItem(t, "capped");
   assert(getTrieSize(t) == 5);
   insertItem(t, "cape");
   assert(getTrieSize(t) == 6);
   removeItem(t, "cape");
   assert(getTrieSize(t) == 5);
   insertItem(t, "batter");
   assert(getTrieSize(t) == 6);
   insertItem(t, "catering");
   assert(getTrieSize(t) == 7);
   assert(getItemInTrie(t, "cape") == NULL);
   removeItem(t, "cape"); //"removes" non-existent item
   assert(getTrieSize(t) == 7);
   assert(getItemInTrie(t, "tap") == NULL);
   removeItem(t, "tap"); //"removes" non-existent item
   assert(getTrieSize(t) == 7);
   removeItem(t, "cat");
   assert(getTrieSize(t) == 6);
   assert(getItemInTrie(t, "cat") == NULL);
   removeItem(t, "batter");
   assert(getTrieSize(t) == 5);
   assert(getItemInTrie(t, "batter") == NULL);
   insertItem(t, "cat");
   assert(getTrieSize(t) == 6);
   removeItem(t, "catering");
   assert(getTrieSize(t) == 5);
   assert(getItemInTrie(t, "catering") == NULL);
   removeItem(t, "capped");
   assert(getTrieSize(t) == 4);
   assert(getItemInTrie(t, "capped") == NULL);
   insertItem(t, "tap");
   assert(getTrieSize(t) == 5);
   insertItem(t, "bad");
   assert(getTrieSize(t) == 6);
   insertItem(t, "mat");
   assert(getTrieSize(t) == 7);
   insertItem(t, "rat");
   assert(getTrieSize(t) == 8);
   assert(strcmp(*getItemInTrie(t, "cat"), "cat") == 0);
   assert(strcmp(*getItemInTrie(t, "cap"), "cap") == 0);
   assert(strcmp(*getItemInTrie(t, "bat"), "bat") == 0);
   assert(strcmp(*getItemInTrie(t, "ape"), "ape") == 0);
   assert(strcmp(*getItemInTrie(t, "tap"), "tap") == 0);
   assert(strcmp(*getItemInTrie(t, "bad"), "bad") == 0);
   assert(strcmp(*getItemInTrie(t, "mat"), "mat") == 0);
   assert(strcmp(*getItemInTrie(t, "rat"), "rat") == 0);
   printf("Trie containing 8 keys:\n");
   showTrie(t);
   printf("Testing completed: UNIT COMPLIES\n\n");

   disposeTrie(t);
   printf("Testing completed: PROGRAM COMPLIES\n");
   return EXIT_SUCCESS;
}
