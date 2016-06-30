/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 4 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for Bag.c.
*/

#include "bool.h"
#include "item.h"

#ifndef BAG_H
#define BAG_H

typedef struct multiset *Bag;

//bag initialisation
Bag  createBag(void);
Bag  copyBag(Bag b);
void disposeBag(Bag b);

//bag progression
void insertMember(Bag b, item data, unsigned int multiplicity);
void removeMember(Bag b, item data, unsigned int multiplicity);

//bag query
void showBag(Bag b);
bool isMember(Bag b, item data);
bool isEmptyBag(Bag b);
bool isSet(Bag b);

//getter functions
item getBagMin(Bag b);
item getBagMax(Bag b);
unsigned long getBagDimension(Bag b);
unsigned long getBagCardinality(Bag b);
unsigned long getMultiplicity(Bag b, item data);
Bag getRootSet(Bag b);

//algebraic operations
Bag getMultisetUnion(Bag b, Bag c);
Bag getMultisetIntersection(Bag b, Bag c);
Bag getMultisetDifference(Bag b, Bag c);
Bag getMultisetSum(Bag b, Bag c);

//bag relations
bool isIdentical(Bag b, Bag c);
bool isSubmultiset(Bag b, Bag c);
bool isStrictSubmultiset(Bag b, Bag c);
bool isDisjointMultisetPair(Bag b, Bag c);

#endif
