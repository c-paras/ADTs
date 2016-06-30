/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for Set.c.
*/

#include "bool.h"
#include "item.h"

#ifndef SET_H
#define SET_H

typedef struct set *Set;

//set initialisation
Set  createSet(void);
Set  copySet(Set s);
void disposeSet(Set s);

//set progression
void insertElement(Set s, item data);
void removeElement(Set s, item data);

//set query
void showSet(Set s);
bool isElement(Set s, item data);
item getSetMin(Set s);
item getSetMax(Set s);
unsigned long getSetCardinality(Set s);
bool isEmptySet(Set s);

//algebraic operations
Set getUnion(Set s, Set t);
Set getIntersection(Set s, Set t);
Set getDifference(Set s, Set t);

//set relations
bool isEquivalent(Set s, Set t);
bool isSubset(Set s, Set t);
bool isProperSubset(Set s, Set t);
bool isDisjointPair(Set s, Set t);

#endif
