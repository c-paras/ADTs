/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This program makes assertions to test Set.c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Set.h"
#include "bool.h"
#include "item.h"

int main(int argc, char *argv[]) {

   //tests set initialisation
   printf("Testing set initialisation:\n");
   Set s = createSet();
   assert(s != NULL);
   assert(getSetCardinality(s) == 0);
   assert(isEmptySet(s) == TRUE);
   printf("Expected output: \u2205\nPrinted output:  ");
   showSet(s);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests insertElement() and getSetCardinality()
   printf("Testing insertElement() and getSetCardinality():\n");
   insertElement(s, 5);
   assert(getSetCardinality(s) == 1);
   assert(isEmptySet(s) == FALSE);
   insertElement(s, 2);
   assert(getSetCardinality(s) == 2);
   insertElement(s, 99);
   assert(getSetCardinality(s) == 3);
   insertElement(s, -63);
   assert(getSetCardinality(s) == 4);
   insertElement(s, 4209);
   assert(getSetCardinality(s) == 5);
   insertElement(s, 4209);
   assert(getSetCardinality(s) == 5);
   insertElement(s, 4209);
   assert(getSetCardinality(s) == 5);
   insertElement(s, 99);
   assert(getSetCardinality(s) == 5);
   insertElement(s, 8888);
   assert(getSetCardinality(s) == 6);
   printf("Expected output: {-63, 2, 5, 99, 4209, 8888}\nPrinted output:  ");
   showSet(s);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isElement()
   printf("Testing isElement():\n");
   assert(isEmptySet(s)      == FALSE);
   assert(isElement(s, 1111) == FALSE);
   assert(isElement(s, 2222) == FALSE);
   assert(isElement(s,    0) == FALSE);
   assert(isElement(s, -333) == FALSE);
   assert(isElement(s,   44) == FALSE);
   assert(isElement(s,   16) == FALSE);
   assert(isElement(s,    5) ==  TRUE);
   assert(isElement(s,    2) ==  TRUE);
   assert(isElement(s,   99) ==  TRUE);
   assert(isElement(s,  -63) ==  TRUE);
   assert(isElement(s, 4209) ==  TRUE);
   assert(isElement(s, 8888) ==  TRUE);
   printf("Expected output: {-63, 2, 5, 99, 4209, 8888}\nPrinted output:  ");
   showSet(s);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests removeElement()
   printf("Testing removeElement():\n");
   assert(isEmptySet(s) == FALSE);
   assert(getSetCardinality(s) == 6);
   assert(isElement(s, 2) == TRUE);
   removeElement(s, 2);
   assert(isElement(s, 2) == FALSE);
   assert(getSetCardinality(s) == 5);
   assert(isElement(s, 4209) == TRUE);
   removeElement(s, 4209);
   assert(isElement(s, 4209) == FALSE);
   assert(getSetCardinality(s) == 4);
   assert(isElement(s, 8888) == TRUE);
   removeElement(s, 8888);
   assert(isElement(s, 8888) == FALSE);
   assert(getSetCardinality(s) == 3);
   assert(isElement(s, 99) == TRUE);
   removeElement(s, 99);
   assert(isElement(s, 99) == FALSE);
   assert(getSetCardinality(s) == 2);
   assert(isElement(s, 4209) == FALSE);
   insertElement(s, 4209);
   assert(isElement(s, 4209) == TRUE);
   assert(getSetCardinality(s) == 3);
   assert(isElement(s, 5) == TRUE);
   removeElement(s, 5);
   assert(isElement(s, 5) == FALSE);
   assert(getSetCardinality(s) == 2);
   assert(isElement(s, -63) == TRUE);
   removeElement(s, -63);
   assert(isElement(s, -63) == FALSE);
   assert(getSetCardinality(s) == 1);
   removeElement(s, -63); //"removes" non-existent element
   assert(isElement(s, -63) == FALSE);
   assert(getSetCardinality(s) == 1);
   assert(isElement(s, 4209) == TRUE);
   removeElement(s, 4209);
   assert(isElement(s, 4209) == FALSE);
   assert(getSetCardinality(s) == 0);
   removeElement(s, 4209); //"removes" non-existent element
   assert(isElement(s, 4209) == FALSE);
   assert(getSetCardinality(s) == 0);
   printf("Expected output: \u2205\nPrinted output:  ");
   showSet(s);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getSetMin() and getSetMax()
   printf("Testing getSetMin() and getSetMax():\n");
   assert(isEmptySet(s) == TRUE);
   insertElement(s, 1);
   assert(getSetMin(s) == 1 && getSetMax(s) == 1);
   insertElement(s, 5);
   assert(getSetMin(s) == 1 && getSetMax(s) == 5);
   insertElement(s, 5);
   assert(getSetMin(s) == 1 && getSetMax(s) == 5);
   insertElement(s, 16);
   assert(getSetMin(s) == 1 && getSetMax(s) == 16);
   insertElement(s, -8);
   assert(getSetMin(s) == -8 && getSetMax(s) == 16);
   insertElement(s, 42);
   assert(getSetMin(s) == -8 && getSetMax(s) == 42);
   removeElement(s, 42);
   assert(getSetMin(s) == -8 && getSetMax(s) == 16);
   removeElement(s, -8);
   assert(getSetMin(s) == 1 && getSetMax(s) == 16);
   removeElement(s, 1);
   assert(getSetMin(s) == 5 && getSetMax(s) == 16);
   insertElement(s, 10);
   assert(getSetMin(s) == 5 && getSetMax(s) == 16);
   removeElement(s, 16);
   assert(getSetMin(s) == 5 && getSetMax(s) == 10);
   removeElement(s, 5);
   assert(getSetMin(s) == 10 && getSetMax(s) == 10);
   printf("Expected output: {10}\nPrinted output:  ");
   showSet(s);
   disposeSet(s);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //creates sets for testing purposes
   Set emptySet = createSet();
   Set unarySet = createSet();
   Set dualSet  = createSet();
   Set smallSet = createSet();
   Set largeSet = createSet();
   insertElement(unarySet, 1);
   insertElement(dualSet,  2);
   insertElement(dualSet,  3);
   int i;
   for (i = 3; i <= 7; i++) insertElement(smallSet, i);
   for (i = 6; i < 16; i++) insertElement(largeSet, i);

   //tests copySet()
   printf("Testing copySet():\n");
   printf("Copy of an empty set: ");
   Set emptySet2 = copySet(emptySet);
   assert(emptySet2 != NULL);
   assert(getSetCardinality(emptySet2) == 0);
   assert(isEmptySet(emptySet2) == TRUE);
   showSet(emptySet2);

   printf("Copy of {1}: ");
   Set unarySet2 = copySet(unarySet);
   assert(unarySet2 != NULL);
   assert(getSetCardinality(unarySet2) == 1);
   assert(isEmptySet(unarySet2) == FALSE);
   showSet(unarySet2);

   printf("Copy of {2, 3}: ");
   Set dualSet2 = copySet(dualSet);
   assert(dualSet2 != NULL);
   assert(getSetCardinality(dualSet2) == 2);
   assert(isEmptySet(dualSet2) == FALSE);
   showSet(dualSet2);

   printf("Copy of {3, 4, 5, 6, 7}: ");
   Set smallSet2 = copySet(smallSet);
   assert(smallSet2 != NULL);
   assert(getSetCardinality(smallSet2) == 5);
   assert(isEmptySet(smallSet2) == FALSE);
   showSet(smallSet2);

   printf("Copy of {6, 7, 8, 9, 10, 11, 12, 13, 14, 15}: ");
   Set largeSet2 = copySet(largeSet);
   assert(largeSet2 != NULL);
   assert(getSetCardinality(largeSet2) == 10);
   assert(isEmptySet(largeSet2) == FALSE);
   showSet(largeSet2);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getUnion()
   printf("Testing getUnion():\n");
   printf("\u2205 ∪ \u2205 = ");
   Set emptyUnion = getUnion(emptySet, emptySet2);
   assert(emptyUnion != NULL);
   assert(getSetCardinality(emptyUnion) == 0);
   assert(isEmptySet(emptyUnion) == TRUE);
   showSet(emptyUnion);

   printf("\u2205 ∪ {1} = ");
   Set unaryUnion = getUnion(emptySet, unarySet);
   assert(unaryUnion != NULL);
   assert(getSetCardinality(unaryUnion) == 1);
   assert(isEmptySet(unaryUnion) == FALSE);
   showSet(unaryUnion);

   printf("{2, 3} ∪ \u2205 = ");
   Set dualUnion = getUnion(dualSet, emptySet);
   assert(dualUnion != NULL);
   assert(getSetCardinality(dualUnion) == 2);
   assert(isEmptySet(dualUnion) == FALSE);
   showSet(dualUnion);

   printf("{1} ∪ {2, 3} = ");
   Set ternaryUnion = getUnion(unarySet, dualSet);
   assert(ternaryUnion != NULL);
   assert(getSetCardinality(ternaryUnion) == 3);
   assert(isEmptySet(ternaryUnion) == FALSE);
   showSet(ternaryUnion);

   printf("{2, 3} ∪ {3, 4, 5, 6, 7} = ");
   Set smallUnion = getUnion(dualSet, smallSet);
   assert(smallUnion != NULL);
   assert(getSetCardinality(smallUnion) == 6);
   assert(isEmptySet(smallUnion) == FALSE);
   showSet(smallUnion);

   printf("{3, 4, 5, 6, 7} ∪ {6, 7, 8, 9, 10, 11, 12, 13, 14, 15} = ");
   Set largeUnion = getUnion(smallSet, largeSet);
   assert(largeUnion != NULL);
   assert(getSetCardinality(largeUnion) == 13);
   assert(isEmptySet(largeUnion) == FALSE);
   showSet(largeUnion);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getIntersection()
   printf("Testing getIntersection():\n");
   printf("\u2205 ∩ \u2205 = ");
   Set emptyIntersection = getIntersection(emptySet, emptySet2);
   assert(emptyIntersection != NULL);
   assert(getSetCardinality(emptyIntersection) == 0);
   assert(isEmptySet(emptyIntersection) == TRUE);
   showSet(emptyIntersection);

   printf("\u2205 ∩ {1} = ");
   Set emptyIntersection2 = getIntersection(emptySet, unarySet);
   assert(emptyIntersection2 != NULL);
   assert(getSetCardinality(emptyIntersection2) == 0);
   assert(isEmptySet(emptyIntersection2) == TRUE);
   showSet(emptyIntersection2);

   printf("{2, 3} ∩ \u2205 = ");
   Set emptyIntersection3 = getIntersection(dualSet, emptySet);
   assert(emptyIntersection3 != NULL);
   assert(getSetCardinality(emptyIntersection3) == 0);
   assert(isEmptySet(emptyIntersection3) == TRUE);
   showSet(emptyIntersection3);

   printf("{1} ∩ {2, 3} = ");
   Set emptyIntersection4 = getIntersection(unarySet, dualSet);
   assert(emptyIntersection4 != NULL);
   assert(getSetCardinality(emptyIntersection4) == 0);
   assert(isEmptySet(emptyIntersection4) == TRUE);
   showSet(emptyIntersection4);

   printf("{2, 3} ∩ {3, 4, 5, 6, 7} = ");
   Set unaryIntersection = getIntersection(dualSet, smallSet);
   assert(unaryIntersection != NULL);
   assert(getSetCardinality(unaryIntersection) == 1);
   assert(isEmptySet(unaryIntersection) == FALSE);
   showSet(unaryIntersection);

   printf("{3, 4, 5, 6, 7} ∩ {6, 7, 8, 9, 10, 11, 12, 13, 14, 15} = ");
   Set dualIntersection = getIntersection(smallSet, largeSet);
   assert(dualIntersection != NULL);
   assert(getSetCardinality(dualIntersection) == 2);
   assert(isEmptySet(dualIntersection) == FALSE);
   showSet(dualIntersection);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getDifference()
   printf("Testing getDifference():\n");
   printf("\u2205 \\ \u2205 = ");
   Set emptyDifference = getDifference(emptySet, emptySet2);
   assert(emptyDifference != NULL);
   assert(getSetCardinality(emptyDifference) == 0);
   assert(isEmptySet(emptyDifference) == TRUE);
   showSet(emptyDifference);

   printf("\u2205 \\ {1} = ");
   Set emptyDifference2 = getDifference(emptySet, unarySet);
   assert(emptyDifference2 != NULL);
   assert(getSetCardinality(emptyDifference2) == 0);
   assert(isEmptySet(emptyDifference2) == TRUE);
   showSet(emptyDifference2);

   printf("{2, 3} \\ \u2205 = ");
   Set dualDifference = getDifference(dualSet, emptySet);
   assert(dualDifference != NULL);
   assert(getSetCardinality(dualDifference) == 2);
   assert(isEmptySet(dualDifference) == FALSE);
   showSet(dualDifference);

   printf("{1} \\ {2, 3} = ");
   Set unaryDifference = getDifference(unarySet, dualSet);
   assert(unaryDifference != NULL);
   assert(getSetCardinality(unaryDifference) == 1);
   assert(isEmptySet(unaryDifference) == FALSE);
   showSet(unaryDifference);

   printf("{2, 3} \\ {3, 4, 5, 6, 7} = ");
   Set unaryDifference2 = getDifference(dualSet, smallSet);
   assert(unaryDifference2 != NULL);
   assert(getSetCardinality(unaryDifference2) == 1);
   assert(isEmptySet(unaryDifference2) == FALSE);
   showSet(unaryDifference2);

   printf("{3, 4, 5, 6, 7} \\ {6, 7, 8, 9, 10, 11, 12, 13, 14, 15} = ");
   Set ternaryDifference = getDifference(smallSet, largeSet);
   assert(ternaryDifference != NULL);
   assert(getSetCardinality(ternaryDifference) == 3);
   assert(isEmptySet(ternaryDifference) == FALSE);
   showSet(ternaryDifference);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isEquivalent()
   printf("Testing isEquivalent():\n");
   assert(isEquivalent(emptySet, emptySet2) == TRUE);
   assert(isEquivalent(unarySet, unarySet2) == TRUE);
   assert(isEquivalent(dualSet,   dualSet2) == TRUE);
   assert(isEquivalent(smallSet, smallSet2) == TRUE);
   assert(isEquivalent(largeSet, largeSet2) == TRUE);
   assert(isEquivalent(dualUnion, dualIntersection) == FALSE);
   assert(isEquivalent(dualIntersection, ternaryDifference) == FALSE);
   assert(isEquivalent(unaryIntersection, unaryDifference) == FALSE);
   assert(isEquivalent(largeUnion, dualDifference) == FALSE);
   assert(isEquivalent(emptySet, smallUnion) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isSubset()
   printf("Testing isSubset():\n");
   assert(isSubset(emptySet, emptySet2) == TRUE);
   assert(isSubset(emptySet, smallSet) == TRUE);
   assert(isSubset(dualDifference, ternaryUnion) == TRUE);
   assert(isSubset(largeSet, largeUnion) == TRUE);
   assert(isSubset(unaryDifference, unarySet) == TRUE);
   assert(isSubset(largeUnion, largeSet) == FALSE);
   assert(isSubset(unaryIntersection, emptySet) == FALSE);
   assert(isSubset(dualIntersection, ternaryDifference) == FALSE);
   assert(isSubset(dualUnion, unaryDifference) == FALSE);
   assert(isSubset(smallSet, emptySet) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isProperSubset()
   printf("Testing isProperSubset():\n");
   assert(isProperSubset(emptySet, smallSet) == TRUE);
   assert(isProperSubset(unaryIntersection, dualDifference) == TRUE);
   assert(isProperSubset(dualIntersection, smallUnion) == TRUE);
   assert(isProperSubset(dualDifference, ternaryUnion) == TRUE);
   assert(isProperSubset(smallSet, largeUnion) == TRUE);
   assert(isProperSubset(emptySet, emptyIntersection) == FALSE);
   assert(isProperSubset(dualDifference, dualSet) == FALSE);
   assert(isProperSubset(unaryDifference, unarySet) == FALSE);
   assert(isProperSubset(unaryUnion, dualDifference) == FALSE);
   assert(isProperSubset(unaryDifference, unaryIntersection) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests isDisjointPair()
   printf("Testing isDisjointPair():\n");
   assert(isDisjointPair(emptySet, dualSet) == TRUE);
   assert(isDisjointPair(unaryUnion, dualDifference) == TRUE);
   assert(isDisjointPair(ternaryUnion, dualIntersection) == TRUE);
   assert(isDisjointPair(largeUnion, unarySet) == TRUE);
   assert(isDisjointPair(emptySet, emptyDifference) == TRUE);
   assert(isDisjointPair(unaryDifference, ternaryUnion) == FALSE);
   assert(isDisjointPair(dualSet, largeUnion) == FALSE);
   assert(isDisjointPair(unaryDifference, ternaryUnion) == FALSE);
   assert(isDisjointPair(largeSet, dualIntersection) == FALSE);
   assert(isDisjointPair(smallSet, largeUnion) == FALSE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   disposeSet(emptySet);
   disposeSet(emptySet2);
   disposeSet(emptyUnion);
   disposeSet(emptyIntersection);
   disposeSet(emptyIntersection2);
   disposeSet(emptyIntersection3);
   disposeSet(emptyIntersection4);
   disposeSet(emptyDifference);
   disposeSet(emptyDifference2);
   disposeSet(unarySet);
   disposeSet(unarySet2);
   disposeSet(unaryUnion);
   disposeSet(unaryIntersection);
   disposeSet(unaryDifference);
   disposeSet(unaryDifference2);
   disposeSet(dualSet);
   disposeSet(dualSet2);
   disposeSet(dualUnion);
   disposeSet(dualIntersection);
   disposeSet(dualDifference);
   disposeSet(ternaryUnion);
   disposeSet(ternaryDifference);
   disposeSet(smallSet);
   disposeSet(smallSet2);
   disposeSet(smallUnion);
   disposeSet(largeSet);
   disposeSet(largeSet2);
   disposeSet(largeUnion);
   printf("Testing completed: PROGRAM COMPLIES\n");
   return EXIT_SUCCESS;
}
