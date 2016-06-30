/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 10 February 2016
Last Revision: 26 February 2016
Description: This program defines an integer hash function for a hash table.
*/

#include "item.h"

//generic hash function that converts a given integer key into a numeric index
unsigned long hash(key k, unsigned long n) {

   return k % n;
}
