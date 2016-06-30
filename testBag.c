/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 4 February 2016
Last Revision: 26 February 2016
Description: This program makes assertions to test Bag.c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Bag.h"
#include "bool.h"
#include "item.h"

int main(int argc, char *argv[]) {

   //tests bag initialisation
   printf("Testing bag initialisation:\n");
   Bag b = createBag();
   assert(b != NULL);
   assert(getBagDimension(b) == 0);
   assert(getBagCardinality(b) == 0);
   assert(isEmptyBag(b) == TRUE);
   printf("Expected output: \u2205\nPrinted output:  ");
   showBag(b);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests insertMember(), getBagDimension() and getBagCardinality()
   printf("Testing insertMember(), getBagDimension() and getBagCardinality():\n");
   insertMember(b, 5, 1);
   assert(getBagDimension(b) == 1);
   assert(getBagCardinality(b) == 1);
   assert(isEmptyBag(b) == FALSE);
   insertMember(b, 2, 2);
   assert(getBagDimension(b) == 2);
   assert(getBagCardinality(b) == 3);
   insertMember(b, 99, 1);
   assert(getBagDimension(b) == 3);
   assert(getBagCardinality(b) == 4);
   insertMember(b, -63, 0); //"inserts" member with 0 multiplicity
   assert(getBagDimension(b) == 3);
   assert(getBagCardinality(b) == 4);
   insertMember(b, -63, 1);
   assert(getBagDimension(b) == 4);
   assert(getBagCardinality(b) == 5);
   insertMember(b, 4209, 1);
   assert(getBagDimension(b) == 5);
   assert(getBagCardinality(b) == 6);
   insertMember(b, 4209, 2);
   assert(getBagDimension(b) == 5);
   assert(getBagCardinality(b) == 8);
   insertMember(b, 99, 3);
   assert(getBagDimension(b) == 5);
   assert(getBagCardinality(b) == 11);
   insertMember(b, 8888, 1);
   assert(getBagDimension(b) == 6);
   assert(getBagCardinality(b) == 12);
   printf("Expected output: {-63, 2, 2, 5, 99, 99, 99, 99, 4209, 4209, 4209, 8888}\n");
   printf("Printed output:  ");
   showBag(b);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isMember() and getMultiplicity()
   printf("Testing isMember() and getMultiplicity():\n");
   assert(isEmptyBag(b) == FALSE);
   assert(isMember(b, 1111) == FALSE);
   assert(getMultiplicity(b, 1111) == 0);
   assert(isMember(b, 2222) == FALSE);
   assert(getMultiplicity(b, 2222) == 0);
   assert(isMember(b, 0) == FALSE);
   assert(getMultiplicity(b, 0) == 0);
   assert(isMember(b, -333) == FALSE);
   assert(getMultiplicity(b, -333) == 0);
   assert(isMember(b, 44) == FALSE);
   assert(getMultiplicity(b, 44) == 0);
   assert(isMember(b, 16) == FALSE);
   assert(getMultiplicity(b, 16) == 0);
   assert(isMember(b, 5) == TRUE);
   assert(getMultiplicity(b, 5) == 1);
   assert(isMember(b, 2) == TRUE);
   assert(getMultiplicity(b, 2) == 2);
   assert(isMember(b, 99) == TRUE);
   assert(getMultiplicity(b, 99) == 4);
   assert(isMember(b, -63) == TRUE);
   assert(getMultiplicity(b, -63) == 1);
   assert(isMember(b, 4209) == TRUE);
   assert(getMultiplicity(b, 4209) == 3);
   assert(isMember(b, 8888) == TRUE);
   assert(getMultiplicity(b, 8888) == 1);
   printf("Expected output: {-63, 2, 2, 5, 99, 99, 99, 99, 4209, 4209, 4209, 8888}\n");
   printf("Printed output:  ");
   showBag(b);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests removeMember()
   printf("Testing removeMember():\n");
   assert(isEmptyBag(b) == FALSE);
   assert(getBagDimension(b) == 6);
   assert(getBagCardinality(b) == 12);

   assert(isMember(b, 2) == TRUE);
   removeMember(b, 2, 2);
   assert(isMember(b, 2) == FALSE);
   assert(getBagDimension(b) == 5);
   assert(getBagCardinality(b) == 10);

   assert(isMember(b, 4209) == TRUE);
   removeMember(b, 4209, 1);
   assert(isMember(b, 4209) == TRUE);
   assert(getBagDimension(b) == 5);
   assert(getBagCardinality(b) == 9);

   assert(isMember(b, 4209) == TRUE);
   removeMember(b, 4209, 0); //"removes" member by specifying a zero multiplicity
   assert(isMember(b, 4209) == TRUE);
   assert(getBagDimension(b) == 5);
   assert(getBagCardinality(b) == 9);

   assert(isMember(b, 8888) == TRUE);
   removeMember(b, 8888, 1);
   assert(isMember(b, 8888) == FALSE);
   assert(getBagDimension(b) == 4);
   assert(getBagCardinality(b) == 8);

   assert(isMember(b, 99) == TRUE);
   removeMember(b, 99, 4);
   assert(isMember(b, 99) == FALSE);
   assert(getBagDimension(b) == 3);
   assert(getBagCardinality(b) == 4);

   assert(isMember(b, 8888) == FALSE);
   insertMember(b, 8888, 1);
   assert(isMember(b, 8888) == TRUE);
   assert(getBagDimension(b) == 4);
   assert(getBagCardinality(b) == 5);

   assert(isMember(b, 5) == TRUE);
   removeMember(b, 5, 6); //removes member by reducing to a negative multiplicity
   assert(isMember(b, 5) == FALSE);
   assert(getBagDimension(b) == 3);
   assert(getBagCardinality(b) == 4);

   assert(isMember(b, -63) == TRUE);
   removeMember(b, -63, 1);
   assert(isMember(b, -63) == FALSE);
   assert(getBagDimension(b) == 2);
   assert(getBagCardinality(b) == 3);

   assert(isMember(b, -63) == FALSE);
   removeMember(b, -63, 1); //"removes" non-existent member
   assert(isMember(b, -63) == FALSE);
   assert(getBagDimension(b) == 2);
   assert(getBagCardinality(b) == 3);

   assert(isMember(b, 4209) == TRUE);
   removeMember(b, 4209, 2);
   assert(isMember(b, 4209) == FALSE);
   assert(getBagDimension(b) == 1);
   assert(getBagCardinality(b) == 1);

   assert(isMember(b, 8888) == TRUE);
   removeMember(b, 8888, 1);
   assert(isMember(b, 8888) == FALSE);
   assert(getBagDimension(b) == 0);
   assert(getBagCardinality(b) == 0);

   assert(isMember(b, 4209) == FALSE);
   removeMember(b, 4209, 3); //"removes" non-existent member
   assert(isMember(b, 4209) == FALSE);
   assert(getBagDimension(b) == 0);
   assert(getBagCardinality(b) == 0);
   printf("Expected output: \u2205\nPrinted output:  ");
   showBag(b);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getBagMin() and getBagMax()
   printf("Testing getBagMin() and getBagMax():\n");
   assert(isEmptyBag(b) == TRUE);
   insertMember(b, 1, 1);
   assert(getBagMin(b) == 1 && getBagMax(b) == 1);
   insertMember(b, 5, 2);
   assert(getBagMin(b) == 1 && getBagMax(b) == 5);
   insertMember(b, 5, 1);
   assert(getBagMin(b) == 1 && getBagMax(b) == 5);
   insertMember(b, 16, 1);
   assert(getBagMin(b) == 1 && getBagMax(b) == 16);
   insertMember(b, -8, 3);
   assert(getBagMin(b) == -8 && getBagMax(b) == 16);
   insertMember(b, 42, 8);
   assert(getBagMin(b) == -8 && getBagMax(b) == 42);
   removeMember(b, 42, 8);
   assert(getBagMin(b) == -8 && getBagMax(b) == 16);
   removeMember(b, -8, 1);
   assert(getBagMin(b) == -8 && getBagMax(b) == 16);
   insertMember(b, 4, 5);
   assert(getBagMin(b) == -8 && getBagMax(b) == 16);
   removeMember(b, -8, 2);
   assert(getBagMin(b) == 1 && getBagMax(b) == 16);
   removeMember(b, 1, 1);
   assert(getBagMin(b) == 4 && getBagMax(b) == 16);
   insertMember(b, 10, 1);
   assert(getBagMin(b) == 4 && getBagMax(b) == 16);
   removeMember(b, 16, 1);
   assert(getBagMin(b) == 4 && getBagMax(b) == 10);
   removeMember(b, 4, 5);
   assert(getBagMin(b) == 5 && getBagMax(b) == 10);
   removeMember(b, 5, 3);
   assert(getBagMin(b) == 10 && getBagMax(b) == 10);
   printf("Expected output: {10}\nPrinted output:  ");
   showBag(b);
   disposeBag(b);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //creates bags for testing purposes
   Bag emptyBag = createBag();
   Bag unaryBag = createBag();
   Bag dualBag  = createBag();
   Bag smallBag = createBag();
   Bag largeBag = createBag();
   insertMember(unaryBag, 1, 1);
   insertMember(dualBag,  2, 1);
   insertMember(dualBag,  3, 1);
   int i, multiplicity;
   for (i = 3; i <= 7; i++) {
      multiplicity = (i == 3) ? 3 : 1;
      insertMember(smallBag, i, multiplicity);
   }
   for (i = 6; i < 16; i++) {
      multiplicity = (i < 8) ? 2 : 1;
      insertMember(largeBag, i, multiplicity);
   }

   //tests copyBag()
   printf("Testing copyBag():\n");
   printf("Copy of an empty bag: ");
   Bag emptyBag2 = copyBag(emptyBag);
   assert(emptyBag2 != NULL);
   assert(getBagDimension(emptyBag2) == 0);
   assert(getBagCardinality(emptyBag2) == 0);
   assert(isEmptyBag(emptyBag2) == TRUE);
   showBag(emptyBag2);

   printf("Copy of {1}: ");
   Bag unaryBag2 = copyBag(unaryBag);
   assert(unaryBag2 != NULL);
   assert(getBagDimension(unaryBag2) == 1);
   assert(getBagCardinality(unaryBag2) == 1);
   assert(isEmptyBag(unaryBag2) == FALSE);
   showBag(unaryBag2);

   printf("Copy of {2, 3}: ");
   Bag dualBag2 = copyBag(dualBag);
   assert(dualBag2 != NULL);
   assert(getBagDimension(dualBag2) == 2);
   assert(getBagCardinality(dualBag2) == 2);
   assert(isEmptyBag(dualBag2) == FALSE);
   showBag(dualBag2);

   printf("Copy of {3, 3, 3, 4, 5, 6, 7}: ");
   Bag smallBag2 = copyBag(smallBag);
   assert(smallBag2 != NULL);
   assert(getBagDimension(smallBag2) == 5);
   assert(getBagCardinality(smallBag2) == 7);
   assert(isEmptyBag(smallBag2) == FALSE);
   showBag(smallBag2);

   printf("Copy of {6, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14, 15}: ");
   Bag largeBag2 = copyBag(largeBag);
   assert(largeBag2 != NULL);
   assert(getBagDimension(largeBag2) == 10);
   assert(getBagCardinality(largeBag2) == 12);
   assert(isEmptyBag(largeBag2) == FALSE);
   showBag(largeBag2);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isSet() and getRootSet()
   printf("Testing isSet() and getRootSet():\n");
   printf("Root set of an empty bag: ");
   assert(isSet(emptyBag) == TRUE);
   Bag emptySet = getRootSet(emptyBag);
   assert(emptySet != NULL);
   assert(getBagDimension(emptySet) == 0);
   assert(getBagCardinality(emptySet) == 0);
   assert(isEmptyBag(emptySet) == TRUE);
   showBag(emptySet);
   disposeBag(emptySet);

   printf("Root set of {1}: ");
   assert(isSet(unaryBag) == TRUE);
   Bag unarySet = getRootSet(unaryBag);
   assert(unarySet != NULL);
   assert(getBagDimension(unarySet) == 1);
   assert(getBagCardinality(unarySet) == 1);
   assert(isEmptyBag(unarySet) == FALSE);
   showBag(unarySet);
   disposeBag(unarySet);

   printf("Root set of {2, 3}: ");
   assert(isSet(dualBag) == TRUE);
   Bag dualSet = getRootSet(dualBag);
   assert(dualSet != NULL);
   assert(getBagDimension(dualSet) == 2);
   assert(getBagCardinality(dualSet) == 2);
   assert(isEmptyBag(dualSet) == FALSE);
   showBag(dualSet);
   disposeBag(dualSet);

   printf("Root set of {3, 3, 3, 4, 5, 6, 7}: ");
   assert(isSet(smallBag) == FALSE);
   Bag smallSet = getRootSet(smallBag);
   assert(smallSet != NULL);
   assert(getBagDimension(smallSet) == 5);
   assert(getBagCardinality(smallSet) == 5);
   assert(isEmptyBag(smallSet) == FALSE);
   showBag(smallSet);
   disposeBag(smallSet);

   printf("Root set of {6, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14, 15}: ");
   assert(isSet(largeBag) == FALSE);
   Bag largeSet = getRootSet(largeBag);
   assert(largeSet != NULL);
   assert(getBagDimension(largeSet) == 10);
   assert(getBagCardinality(largeSet) == 10);
   assert(isEmptyBag(largeSet) == FALSE);
   showBag(largeSet);
   disposeBag(largeSet);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getMultisetUnion()
   printf("Testing getMultisetUnion():\n");
   printf("\u2205 ∪ \u2205 = ");
   Bag emptyUnion = getMultisetUnion(emptyBag, emptyBag2);
   assert(emptyUnion != NULL);
   assert(getBagDimension(emptyUnion) == 0);
   assert(getBagCardinality(emptyUnion) == 0);
   assert(isEmptyBag(emptyUnion) == TRUE);
   showBag(emptyUnion);

   printf("\u2205 ∪ {1} = ");
   Bag unaryUnion = getMultisetUnion(emptyBag, unaryBag);
   assert(unaryUnion != NULL);
   assert(getBagDimension(unaryUnion) == 1);
   assert(getBagCardinality(unaryUnion) == 1);
   assert(isEmptyBag(unaryUnion) == FALSE);
   showBag(unaryUnion);

   printf("{2, 3} ∪ \u2205 = ");
   Bag dualUnion = getMultisetUnion(dualBag, emptyBag);
   assert(dualUnion != NULL);
   assert(getBagDimension(dualUnion) == 2);
   assert(getBagCardinality(dualUnion) == 2);
   assert(isEmptyBag(dualUnion) == FALSE);
   showBag(dualUnion);

   printf("{1} ∪ {2, 3} = ");
   Bag ternaryUnion = getMultisetUnion(unaryBag, dualBag);
   assert(ternaryUnion != NULL);
   assert(getBagDimension(ternaryUnion) == 3);
   assert(getBagCardinality(ternaryUnion) == 3);
   assert(isEmptyBag(ternaryUnion) == FALSE);
   showBag(ternaryUnion);

   printf("{2, 3} ∪ {3, 3, 3, 4, 5, 6, 7} = ");
   Bag smallUnion = getMultisetUnion(dualBag, smallBag);
   assert(smallUnion != NULL);
   assert(getBagDimension(smallUnion) == 6);
   assert(getBagCardinality(smallUnion) == 8);
   assert(isEmptyBag(smallUnion) == FALSE);
   showBag(smallUnion);

   printf("{3, 3, 3, 4, 5, 6, 7} ∪ {6, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14, 15} = ");
   Bag largeUnion = getMultisetUnion(smallBag, largeBag);
   assert(largeUnion != NULL);
   assert(getBagDimension(largeUnion) == 13);
   assert(getBagCardinality(largeUnion) == 17);
   assert(isEmptyBag(largeUnion) == FALSE);
   showBag(largeUnion);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getMultisetIntersection()
   printf("Testing getMultisetIntersection():\n");
   printf("\u2205 ∩ \u2205 = ");
   Bag emptyIntersection = getMultisetIntersection(emptyBag, emptyBag2);
   assert(emptyIntersection != NULL);
   assert(getBagDimension(emptyIntersection) == 0);
   assert(getBagCardinality(emptyIntersection) == 0);
   assert(isEmptyBag(emptyIntersection) == TRUE);
   showBag(emptyIntersection);

   printf("\u2205 ∩ {1} = ");
   Bag emptyIntersection2 = getMultisetIntersection(emptyBag, unaryBag);
   assert(emptyIntersection2 != NULL);
   assert(getBagDimension(emptyIntersection2) == 0);
   assert(getBagCardinality(emptyIntersection2) == 0);
   assert(isEmptyBag(emptyIntersection2) == TRUE);
   showBag(emptyIntersection2);

   printf("{2, 3} ∩ \u2205 = ");
   Bag emptyIntersection3 = getMultisetIntersection(dualBag, emptyBag);
   assert(emptyIntersection3 != NULL);
   assert(getBagDimension(emptyIntersection3) == 0);
   assert(getBagCardinality(emptyIntersection3) == 0);
   assert(isEmptyBag(emptyIntersection3) == TRUE);
   showBag(emptyIntersection3);

   printf("{1} ∩ {2, 3} = ");
   Bag emptyIntersection4 = getMultisetIntersection(unaryBag, dualBag);
   assert(emptyIntersection4 != NULL);
   assert(getBagDimension(emptyIntersection4) == 0);
   assert(getBagCardinality(emptyIntersection4) == 0);
   assert(isEmptyBag(emptyIntersection4) == TRUE);
   showBag(emptyIntersection4);

   printf("{2, 3, 3} ∩ {3, 3, 3, 4, 5, 6, 7} = ");
   insertMember(dualBag, 3, 1);
   Bag dualIntersection = getMultisetIntersection(dualBag, smallBag);
   assert(dualIntersection != NULL);
   assert(getBagDimension(dualIntersection) == 1);
   assert(getBagCardinality(dualIntersection) == 2);
   assert(isEmptyBag(dualIntersection) == FALSE);
   showBag(dualIntersection);
   removeMember(dualBag, 3, 1);

   printf("{3, 3, 3, 4, 5, 6, 6, 7} ∩ {6, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14, 15} = ");
   insertMember(smallBag, 6, 1);
   Bag ternaryIntersection = getMultisetIntersection(smallBag, largeBag);
   assert(ternaryIntersection != NULL);
   assert(getBagDimension(ternaryIntersection) == 2);
   assert(getBagCardinality(ternaryIntersection) == 3);
   assert(isEmptyBag(ternaryIntersection) == FALSE);
   showBag(ternaryIntersection);
   removeMember(smallBag, 6, 1);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getMultisetDifference()
   printf("Testing getMultisetDifference():\n");
   printf("\u2205 \\ \u2205 = ");
   Bag emptyDifference = getMultisetDifference(emptyBag, emptyBag2);
   assert(emptyDifference != NULL);
   assert(getBagDimension(emptyDifference) == 0);
   assert(getBagCardinality(emptyDifference) == 0);
   assert(isEmptyBag(emptyDifference) == TRUE);
   showBag(emptyDifference);

   printf("\u2205 \\ {1} = ");
   Bag emptyDifference2 = getMultisetDifference(emptyBag, unaryBag);
   assert(emptyDifference2 != NULL);
   assert(getBagDimension(emptyDifference2) == 0);
   assert(getBagCardinality(emptyDifference2) == 0);
   assert(isEmptyBag(emptyDifference2) == TRUE);
   showBag(emptyDifference2);

   printf("{2, 3} \\ \u2205 = ");
   Bag dualDifference = getMultisetDifference(dualBag, emptyBag);
   assert(dualDifference != NULL);
   assert(getBagDimension(dualDifference) == 2);
   assert(getBagCardinality(dualDifference) == 2);
   assert(isEmptyBag(dualDifference) == FALSE);
   showBag(dualDifference);

   printf("{1} \\ {2, 3} = ");
   Bag unaryDifference = getMultisetDifference(unaryBag, dualBag);
   assert(unaryDifference != NULL);
   assert(getBagDimension(unaryDifference) == 1);
   assert(getBagCardinality(unaryDifference) == 1);
   assert(isEmptyBag(unaryDifference) == FALSE);
   showBag(unaryDifference);

   printf("{2, 3} \\ {3, 3, 3, 4, 5, 6, 7} = ");
   Bag unaryDifference2 = getMultisetDifference(dualBag, smallBag);
   assert(unaryDifference2 != NULL);
   assert(getBagDimension(unaryDifference2) == 1);
   assert(getBagCardinality(unaryDifference2) == 1);
   assert(isEmptyBag(unaryDifference2) == FALSE);
   showBag(unaryDifference2);

   printf("{3, 3, 3, 4, 5, 6, 7} \\ {6, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14, 15} = ");
   Bag smallDifference = getMultisetDifference(smallBag, largeBag);
   assert(smallDifference != NULL);
   assert(getBagDimension(smallDifference) == 3);
   assert(getBagCardinality(smallDifference) == 5);
   assert(isEmptyBag(smallDifference) == FALSE);
   showBag(smallDifference);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getMultisetSum()
   printf("Testing getMultisetSum():\n");
   printf("\u2205 ⨄  \u2205 = ");
   Bag emptySum = getMultisetSum(emptyBag, emptyBag2);
   assert(emptySum != NULL);
   assert(getBagDimension(emptySum) == 0);
   assert(getBagCardinality(emptySum) == 0);
   assert(isEmptyBag(emptySum) == TRUE);
   showBag(emptySum);

   printf("\u2205 ⨄  {1} = ");
   Bag unarySum = getMultisetSum(emptyBag, unaryBag);
   assert(unarySum != NULL);
   assert(getBagDimension(unarySum) == 1);
   assert(getBagCardinality(unarySum) == 1);
   assert(isEmptyBag(unarySum) == FALSE);
   showBag(unarySum);

   printf("{2, 3} ⨄  \u2205 = ");
   Bag dualSum = getMultisetSum(dualBag, emptyBag);
   assert(dualSum != NULL);
   assert(getBagDimension(dualSum) == 2);
   assert(getBagCardinality(dualSum) == 2);
   assert(isEmptyBag(dualSum) == FALSE);
   showBag(dualSum);

   printf("{1} ⨄  {2, 3} = ");
   Bag ternarySum = getMultisetSum(unaryBag, dualBag);
   assert(ternarySum != NULL);
   assert(getBagDimension(ternarySum) == 3);
   assert(getBagCardinality(ternarySum) == 3);
   assert(isEmptyBag(ternarySum) == FALSE);
   showBag(ternarySum);

   printf("{2, 3} ⨄  {3, 3, 3, 4, 5, 6, 7} = ");
   Bag smallSum = getMultisetSum(dualBag, smallBag);
   assert(smallSum != NULL);
   assert(getBagDimension(smallSum) == 6);
   assert(getBagCardinality(smallSum) == 9);
   assert(isEmptyBag(smallSum) == FALSE);
   showBag(smallSum);

   printf("{3, 3, 3, 4, 5, 6, 7} ⨄  {6, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14, 15} = ");
   Bag largeSum = getMultisetSum(smallBag, largeBag);
   assert(largeSum != NULL);
   assert(getBagDimension(largeSum) == 13);
   assert(getBagCardinality(largeSum) == 19);
   assert(isEmptyBag(largeSum) == FALSE);
   showBag(largeSum);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isIdentical()
   printf("Testing isIdentical():\n");
   assert(isIdentical(emptyBag, emptyBag2) == TRUE);
   assert(isIdentical(unaryBag, unaryBag2) == TRUE);
   assert(isIdentical(dualBag,   dualBag2) == TRUE);
   assert(isIdentical(smallBag, smallBag2) == TRUE);
   assert(isIdentical(largeBag, largeBag2) == TRUE);
   assert(isIdentical(dualUnion, dualIntersection) == FALSE);
   assert(isIdentical(dualIntersection, dualDifference) == FALSE);
   assert(isIdentical(ternaryIntersection, ternarySum) == FALSE);
   assert(isIdentical(largeUnion, dualDifference) == FALSE);
   assert(isIdentical(emptyBag, smallUnion) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isSubmultiset()
   printf("Testing isSubmultiset():\n");
   assert(isSubmultiset(emptyBag, emptyBag2) == TRUE);
   assert(isSubmultiset(emptyBag, smallBag) == TRUE);
   assert(isSubmultiset(dualDifference, ternaryUnion) == TRUE);
   assert(isSubmultiset(largeBag, largeUnion) == TRUE);
   assert(isSubmultiset(unaryDifference, unaryBag) == TRUE);
   assert(isSubmultiset(largeUnion, largeBag) == FALSE);
   assert(isSubmultiset(ternarySum, emptyBag) == FALSE);
   assert(isSubmultiset(smallDifference, dualIntersection) == FALSE);
   assert(isSubmultiset(dualUnion, unaryDifference) == FALSE);
   assert(isSubmultiset(smallBag, emptyBag) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isStrictSubmultiset()
   printf("Testing isStrictSubmultiset():\n");
   assert(isStrictSubmultiset(emptyBag, smallBag) == TRUE);
   assert(isStrictSubmultiset(unaryDifference2, dualDifference) == TRUE);
   assert(isStrictSubmultiset(dualIntersection, smallUnion) == TRUE);
   assert(isStrictSubmultiset(dualDifference, ternaryUnion) == TRUE);
   assert(isStrictSubmultiset(smallBag, largeUnion) == TRUE);
   assert(isStrictSubmultiset(emptyBag, emptyIntersection) == FALSE);
   assert(isStrictSubmultiset(dualDifference, dualBag) == FALSE);
   assert(isStrictSubmultiset(unaryDifference, unaryBag) == FALSE);
   assert(isStrictSubmultiset(unaryUnion, dualDifference) == FALSE);
   assert(isStrictSubmultiset(dualDifference, dualIntersection) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isDisjointMultisetPair()
   printf("Testing isDisjointMultisetPair():\n");
   assert(isDisjointMultisetPair(emptyBag, dualBag) == TRUE);
   assert(isDisjointMultisetPair(unaryUnion, dualDifference) == TRUE);
   assert(isDisjointMultisetPair(unaryDifference, smallSum) == TRUE);
   assert(isDisjointMultisetPair(largeUnion, unaryBag) == TRUE);
   assert(isDisjointMultisetPair(emptyBag, emptyDifference) == TRUE);
   assert(isDisjointMultisetPair(unaryDifference, ternaryUnion) == FALSE);
   assert(isDisjointMultisetPair(dualBag, largeUnion) == FALSE);
   assert(isDisjointMultisetPair(unaryDifference, ternaryUnion) == FALSE);
   assert(isDisjointMultisetPair(smallUnion, smallDifference) == FALSE);
   assert(isDisjointMultisetPair(smallBag, largeUnion) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   disposeBag(emptyBag);
   disposeBag(emptyBag2);
   disposeBag(emptyUnion);
   disposeBag(emptyIntersection);
   disposeBag(emptyIntersection2);
   disposeBag(emptyIntersection3);
   disposeBag(emptyIntersection4);
   disposeBag(emptyDifference);
   disposeBag(emptyDifference2);
   disposeBag(emptySum);
   disposeBag(unaryBag);
   disposeBag(unaryBag2);
   disposeBag(unaryUnion);
   disposeBag(unaryDifference);
   disposeBag(unaryDifference2);
   disposeBag(unarySum);
   disposeBag(dualBag);
   disposeBag(dualBag2);
   disposeBag(dualUnion);
   disposeBag(dualIntersection);
   disposeBag(dualDifference);
   disposeBag(dualSum);
   disposeBag(ternaryUnion);
   disposeBag(ternaryIntersection);
   disposeBag(ternarySum);
   disposeBag(smallBag);
   disposeBag(smallBag2);
   disposeBag(smallUnion);
   disposeBag(smallDifference);
   disposeBag(smallSum);
   disposeBag(largeBag);
   disposeBag(largeBag2);
   disposeBag(largeUnion);
   disposeBag(largeSum);
   printf("Testing completed: PROGRAM COMPLIES\n");
   return EXIT_SUCCESS;
}
