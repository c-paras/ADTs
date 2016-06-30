/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 10 February 2016
Last Revision: 26 February 2016
Description: This program defines a string hash function for a hash table.
*/

#include "item.h"

//Robert Sedgewick's universal hashing function from Algorithms in C, Third Edition (1998)
unsigned long hash(key k, unsigned long n) {

   unsigned long h = 0, a = 127;

   //converts the given key into a numeric index
   for (key c = k; *c != '\0'; c++) {
      h = (a * h + *c) % n;
   }

   return h;
}
