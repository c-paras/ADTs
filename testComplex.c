/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 18 February 2016
Last Revision: 26 February 2016
Description: This program makes assertions to test Complex.c.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "Complex.h"

#define EPSILON 1e-10

bool compareLongDouble(long double a, long double b);

int main(int argc, char *argv[]) {

   //tests complex number initialisation
   printf("Testing complex number initialisation:\n");
   Complex zeroZero = createComplex(0, 0);
   assert(zeroZero != NULL);
   assert(compareLongDouble(getRealPart(zeroZero), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(zeroZero), 0) == TRUE);
   Complex oneOne = createComplex(1, 1);
   assert(oneOne != NULL);
   assert(compareLongDouble(getRealPart(oneOne), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(oneOne), 1) == TRUE);
   Complex minusTwoTwo = createComplex(-2, 2);
   assert(minusTwoTwo != NULL);
   assert(compareLongDouble(getRealPart(minusTwoTwo), -2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(minusTwoTwo), 2) == TRUE);
   Complex threeFour = createComplex(3, 4);
   assert(threeFour != NULL);
   assert(compareLongDouble(getRealPart(threeFour), 3) == TRUE);
   assert(compareLongDouble(getImaginaryPart(threeFour), 4) == TRUE);
   Complex minusTwoMinusSix = createComplex(-2, -6);
   assert(minusTwoMinusSix != NULL);
   assert(compareLongDouble(getRealPart(minusTwoMinusSix), -2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(minusTwoMinusSix), -6) == TRUE);
   Complex oneMinusOne = createComplex(1, -1);
   assert(oneMinusOne != NULL);
   assert(compareLongDouble(getRealPart(oneMinusOne), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(oneMinusOne), -1) == TRUE);
   Complex zeroTwo = createComplex(0, 2);
   assert(zeroTwo != NULL);
   assert(compareLongDouble(getRealPart(zeroTwo), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(zeroTwo), 2) == TRUE);
   Complex oneZero = createComplex(1, 0);
   assert(oneZero != NULL);
   assert(compareLongDouble(getRealPart(oneZero), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(oneZero), 0) == TRUE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests copyComplex() and isEqual()
   printf("Testing copyComplex() and isEqual():\n");
   Complex zeroZeroCopy = copyComplex(zeroZero);
   assert(zeroZeroCopy != NULL);
   assert(compareLongDouble(getRealPart(zeroZeroCopy), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(zeroZeroCopy), 0) == TRUE);
   assert(isEqual(zeroZero, zeroZeroCopy) == TRUE);
   assert(isEqual(zeroZero, threeFour) == FALSE);
   Complex oneOneCopy = copyComplex(oneOne);
   assert(oneOneCopy != NULL);
   assert(compareLongDouble(getRealPart(oneOneCopy), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(oneOneCopy), 1) == TRUE);
   assert(isEqual(oneOne, oneOneCopy) == TRUE);
   assert(isEqual(oneOne, minusTwoTwo) == FALSE);
   Complex minusTwoTwoCopy = copyComplex(minusTwoTwo);
   assert(minusTwoTwoCopy != NULL);
   assert(compareLongDouble(getRealPart(minusTwoTwoCopy), -2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(minusTwoTwoCopy), 2) == TRUE);
   assert(isEqual(minusTwoTwo, minusTwoTwoCopy) == TRUE);
   assert(isEqual(minusTwoTwo, oneMinusOne) == FALSE);
   Complex threeFourCopy = copyComplex(threeFour);
   assert(threeFourCopy != NULL);
   assert(compareLongDouble(getRealPart(threeFourCopy), 3) == TRUE);
   assert(compareLongDouble(getImaginaryPart(threeFourCopy), 4) == TRUE);
   assert(isEqual(threeFour, threeFourCopy) == TRUE);
   assert(isEqual(threeFour, oneZero) == FALSE);
   Complex minusTwoMinusSixCopy = copyComplex(minusTwoMinusSix);
   assert(minusTwoMinusSixCopy != NULL);
   assert(compareLongDouble(getRealPart(minusTwoMinusSixCopy), -2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(minusTwoMinusSixCopy), -6) == TRUE);
   assert(isEqual(minusTwoMinusSix, minusTwoMinusSixCopy) == TRUE);
   assert(isEqual(minusTwoMinusSix, zeroTwo) == FALSE);
   Complex oneMinusOneCopy = copyComplex(oneMinusOne);
   assert(oneMinusOneCopy != NULL);
   assert(compareLongDouble(getRealPart(oneMinusOneCopy), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(oneMinusOneCopy), -1) == TRUE);
   assert(isEqual(oneMinusOne, oneMinusOneCopy) == TRUE);
   assert(isEqual(oneMinusOne, threeFour) == FALSE);
   Complex zeroTwoCopy = copyComplex(zeroTwo);
   assert(zeroTwoCopy != NULL);
   assert(compareLongDouble(getRealPart(zeroTwoCopy), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(zeroTwoCopy), 2) == TRUE);
   assert(isEqual(zeroTwo, zeroTwoCopy) == TRUE);
   assert(isEqual(zeroTwo, zeroZero) == FALSE);
   Complex oneZeroCopy = copyComplex(oneZero);
   assert(oneZeroCopy != NULL);
   assert(compareLongDouble(getRealPart(oneZeroCopy), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(oneZeroCopy), 0) == TRUE);
   assert(isEqual(oneZero, oneZeroCopy) == TRUE);
   assert(isEqual(oneZero, zeroZero) == FALSE);
   disposeComplex(zeroZeroCopy);
   disposeComplex(oneOneCopy);
   disposeComplex(minusTwoTwoCopy);
   disposeComplex(threeFourCopy);
   disposeComplex(minusTwoMinusSixCopy);
   disposeComplex(oneMinusOneCopy);
   disposeComplex(zeroTwoCopy);
   disposeComplex(oneZeroCopy);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests showComplex()
   printf("Testing showComplex():\n");
   printf("Cartesian and polar representation of (0, 0):\n");
   showComplex(zeroZero);
   printf("Cartesian and polar representation of (1, 1):\n");
   showComplex(oneOne);
   printf("Cartesian and polar representation of (-2, 2):\n");
   showComplex(minusTwoTwo);
   printf("Cartesian and polar representation of (3, 4):\n");
   showComplex(threeFour);
   printf("Cartesian and polar representation of (-2, -6):\n");
   showComplex(minusTwoMinusSix);
   printf("Cartesian and polar representation of (1, -1):\n");
   showComplex(oneMinusOne);
   printf("Cartesian and polar representation of (0, 2):\n");
   showComplex(zeroTwo);
   printf("Cartesian and polar representation of (1, 0):\n");
   showComplex(oneZero);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getComplexConjugate()
   printf("Testing getComplexConjugate():\n");
   Complex conjugate = getComplexConjugate(zeroZero);
   assert(conjugate != NULL);
   assert(compareLongDouble(getRealPart(conjugate), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(conjugate), 0) == TRUE);
   disposeComplex(conjugate);
   conjugate = getComplexConjugate(oneOne);
   assert(conjugate != NULL);
   assert(compareLongDouble(getRealPart(conjugate), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(conjugate), -1) == TRUE);
   disposeComplex(conjugate);
   conjugate = getComplexConjugate(minusTwoTwo);
   assert(conjugate != NULL);
   assert(compareLongDouble(getRealPart(conjugate), -2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(conjugate), -2) == TRUE);
   disposeComplex(conjugate);
   conjugate = getComplexConjugate(threeFour);
   assert(conjugate != NULL);
   assert(compareLongDouble(getRealPart(conjugate), 3) == TRUE);
   assert(compareLongDouble(getImaginaryPart(conjugate), -4) == TRUE);
   disposeComplex(conjugate);
   conjugate = getComplexConjugate(minusTwoMinusSix);
   assert(conjugate != NULL);
   assert(compareLongDouble(getRealPart(conjugate), -2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(conjugate), 6) == TRUE);
   disposeComplex(conjugate);
   conjugate = getComplexConjugate(oneMinusOne);
   assert(conjugate != NULL);
   assert(compareLongDouble(getRealPart(conjugate), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(conjugate), 1) == TRUE);
   disposeComplex(conjugate);
   conjugate = getComplexConjugate(zeroTwo);
   assert(conjugate != NULL);
   assert(compareLongDouble(getRealPart(conjugate), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(conjugate), -2) == TRUE);
   disposeComplex(conjugate);
   conjugate = getComplexConjugate(oneZero);
   assert(conjugate != NULL);
   assert(compareLongDouble(getRealPart(conjugate), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(conjugate), 0) == TRUE);
   disposeComplex(conjugate);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests add()
   printf("Testing add():\n");
   Complex sum = add(zeroZero, oneOne);
   assert(sum != NULL);
   assert(compareLongDouble(getRealPart(sum), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(sum), 1) == TRUE);
   disposeComplex(sum);
   sum = add(oneOne, minusTwoTwo);
   assert(sum != NULL);
   assert(compareLongDouble(getRealPart(sum), -1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(sum), 3) == TRUE);
   disposeComplex(sum);
   sum = add(threeFour, oneMinusOne);
   assert(sum != NULL);
   assert(compareLongDouble(getRealPart(sum), 4) == TRUE);
   assert(compareLongDouble(getImaginaryPart(sum), 3) == TRUE);
   disposeComplex(sum);
   sum = add(zeroTwo, threeFour);
   assert(sum != NULL);
   assert(compareLongDouble(getRealPart(sum), 3) == TRUE);
   assert(compareLongDouble(getImaginaryPart(sum), 6) == TRUE);
   disposeComplex(sum);
   sum = add(oneMinusOne, zeroTwo);
   assert(sum != NULL);
   assert(compareLongDouble(getRealPart(sum), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(sum), 1) == TRUE);
   disposeComplex(sum);
   sum = add(oneOne, minusTwoMinusSix);
   assert(sum != NULL);
   assert(compareLongDouble(getRealPart(sum), -1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(sum), -5) == TRUE);
   disposeComplex(sum);
   sum = add(oneMinusOne, zeroZero);
   assert(sum != NULL);
   assert(compareLongDouble(getRealPart(sum), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(sum), -1) == TRUE);
   disposeComplex(sum);
   sum = add(oneZero, minusTwoTwo);
   assert(sum != NULL);
   assert(compareLongDouble(getRealPart(sum), -1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(sum), 2) == TRUE);
   disposeComplex(sum);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests subtract()
   printf("Testing subtract():\n");
   Complex diff = subtract(zeroZero, oneOne);
   assert(diff != NULL);
   assert(compareLongDouble(getRealPart(diff), -1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(diff), -1) == TRUE);
   disposeComplex(diff);
   diff = subtract(oneOne, minusTwoTwo);
   assert(diff != NULL);
   assert(compareLongDouble(getRealPart(diff), 3) == TRUE);
   assert(compareLongDouble(getImaginaryPart(diff), -1) == TRUE);
   disposeComplex(diff);
   diff = subtract(threeFour, oneMinusOne);
   assert(diff != NULL);
   assert(compareLongDouble(getRealPart(diff), 2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(diff), 5) == TRUE);
   disposeComplex(diff);
   diff = subtract(zeroTwo, threeFour);
   assert(diff != NULL);
   assert(compareLongDouble(getRealPart(diff), -3) == TRUE);
   assert(compareLongDouble(getImaginaryPart(diff), -2) == TRUE);
   disposeComplex(diff);
   diff = subtract(oneMinusOne, zeroTwo);
   assert(diff != NULL);
   assert(compareLongDouble(getRealPart(diff), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(diff), -3) == TRUE);
   disposeComplex(diff);
   diff = subtract(oneOne, minusTwoMinusSix);
   assert(diff != NULL);
   assert(compareLongDouble(getRealPart(diff), 3) == TRUE);
   assert(compareLongDouble(getImaginaryPart(diff), 7) == TRUE);
   disposeComplex(diff);
   diff = subtract(oneMinusOne, zeroZero);
   assert(diff != NULL);
   assert(compareLongDouble(getRealPart(diff), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(diff), -1) == TRUE);
   disposeComplex(diff);
   diff = subtract(oneZero, minusTwoTwo);
   assert(diff != NULL);
   assert(compareLongDouble(getRealPart(diff), 3) == TRUE);
   assert(compareLongDouble(getImaginaryPart(diff), -2) == TRUE);
   disposeComplex(diff);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests multiply()
   printf("Testing multiply():\n");
   Complex product = multiply(zeroZero, oneOne);
   assert(product != NULL);
   assert(compareLongDouble(getRealPart(product), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(product), 0) == TRUE);
   disposeComplex(product);
   product = multiply(oneOne, minusTwoTwo);
   assert(product != NULL);
   assert(compareLongDouble(getRealPart(product), -4) == TRUE);
   assert(compareLongDouble(getImaginaryPart(product), 0) == TRUE);
   disposeComplex(product);
   product = multiply(threeFour, oneMinusOne);
   assert(product != NULL);
   assert(compareLongDouble(getRealPart(product), 7) == TRUE);
   assert(compareLongDouble(getImaginaryPart(product), 1) == TRUE);
   disposeComplex(product);
   product = multiply(zeroTwo, threeFour);
   assert(product != NULL);
   assert(compareLongDouble(getRealPart(product), -8) == TRUE);
   assert(compareLongDouble(getImaginaryPart(product), 6) == TRUE);
   disposeComplex(product);
   product = multiply(oneMinusOne, zeroTwo);
   assert(product != NULL);
   assert(compareLongDouble(getRealPart(product), 2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(product), 2) == TRUE);
   disposeComplex(product);
   product = multiply(oneOne, minusTwoMinusSix);
   assert(product != NULL);
   assert(compareLongDouble(getRealPart(product), 4) == TRUE);
   assert(compareLongDouble(getImaginaryPart(product), -8) == TRUE);
   disposeComplex(product);
   product = multiply(oneMinusOne, zeroZero);
   assert(product != NULL);
   assert(compareLongDouble(getRealPart(product), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(product), 0) == TRUE);
   disposeComplex(product);
   product = multiply(oneZero, minusTwoTwo);
   assert(product != NULL);
   assert(compareLongDouble(getRealPart(product), -2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(product), 2) == TRUE);
   disposeComplex(product);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getInverse()
   printf("Testing getInverse():\n");
   Complex inverse = getInverse(oneOne);
   assert(inverse != NULL);
   assert(compareLongDouble(getRealPart(inverse), 0.5) == TRUE);
   assert(compareLongDouble(getImaginaryPart(inverse), -0.5) == TRUE);
   disposeComplex(inverse);
   inverse = getInverse(minusTwoTwo);
   assert(inverse != NULL);
   assert(compareLongDouble(getRealPart(inverse), -0.25) == TRUE);
   assert(compareLongDouble(getImaginaryPart(inverse), -0.25) == TRUE);
   disposeComplex(inverse);
   inverse = getInverse(threeFour);
   assert(inverse != NULL);
   assert(compareLongDouble(getRealPart(inverse), 0.12) == TRUE);
   assert(compareLongDouble(getImaginaryPart(inverse), -0.16) == TRUE);
   disposeComplex(inverse);
   inverse = getInverse(minusTwoMinusSix);
   assert(inverse != NULL);
   assert(compareLongDouble(getRealPart(inverse), -0.05) == TRUE);
   assert(compareLongDouble(getImaginaryPart(inverse), 0.15) == TRUE);
   disposeComplex(inverse);
   inverse = getInverse(oneMinusOne);
   assert(inverse != NULL);
   assert(compareLongDouble(getRealPart(inverse), 0.5) == TRUE);
   assert(compareLongDouble(getImaginaryPart(inverse), 0.5) == TRUE);
   disposeComplex(inverse);
   inverse = getInverse(zeroTwo);
   assert(inverse != NULL);
   assert(compareLongDouble(getRealPart(inverse), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(inverse), -0.5) == TRUE);
   disposeComplex(inverse);
   inverse = getInverse(oneZero);
   assert(inverse != NULL);
   assert(compareLongDouble(getRealPart(inverse), 1) == TRUE);
   assert(compareLongDouble(getImaginaryPart(inverse), 0) == TRUE);
   disposeComplex(inverse);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests divide()
   printf("Testing divide():\n");
   Complex quotient = divide(zeroZero, oneOne);
   assert(quotient != NULL);
   assert(compareLongDouble(getRealPart(quotient), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(quotient), 0) == TRUE);
   disposeComplex(quotient);
   quotient = divide(oneOne, minusTwoTwo);
   assert(quotient != NULL);
   assert(compareLongDouble(getRealPart(quotient), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(quotient), -0.5) == TRUE);
   disposeComplex(quotient);
   quotient = divide(threeFour, oneMinusOne);
   assert(quotient != NULL);
   assert(compareLongDouble(getRealPart(quotient), -0.5) == TRUE);
   assert(compareLongDouble(getImaginaryPart(quotient), 3.5) == TRUE);
   disposeComplex(quotient);
   quotient = divide(zeroTwo, threeFour);
   assert(quotient != NULL);
   assert(compareLongDouble(getRealPart(quotient), 0.32) == TRUE);
   assert(compareLongDouble(getImaginaryPart(quotient), 0.24) == TRUE);
   disposeComplex(quotient);
   quotient = divide(oneMinusOne, zeroTwo);
   assert(quotient != NULL);
   assert(compareLongDouble(getRealPart(quotient), -0.5) == TRUE);
   assert(compareLongDouble(getImaginaryPart(quotient), -0.5) == TRUE);
   disposeComplex(quotient);
   quotient = divide(oneOne, minusTwoMinusSix);
   assert(quotient != NULL);
   assert(compareLongDouble(getRealPart(quotient), -0.2) == TRUE);
   assert(compareLongDouble(getImaginaryPart(quotient), 0.1) == TRUE);
   disposeComplex(quotient);
   quotient = divide(oneMinusOne, oneOne);
   assert(quotient != NULL);
   assert(compareLongDouble(getRealPart(quotient), 0) == TRUE);
   assert(compareLongDouble(getImaginaryPart(quotient), -1) == TRUE);
   disposeComplex(quotient);
   quotient = divide(oneZero, minusTwoTwo);
   assert(quotient != NULL);
   assert(compareLongDouble(getRealPart(quotient), -0.25) == TRUE);
   assert(compareLongDouble(getImaginaryPart(quotient), -0.25) == TRUE);
   disposeComplex(quotient);
   printf("Testing completed: UNIT COMPLIES\n\n");

   //tests getModulus() and getArgument()
   printf("Testing getModulus() and getArgument():\n");
   assert(compareLongDouble(getModulus(zeroZero), 0) == TRUE);
   assert(compareLongDouble(getModulus(oneOne), sqrt(2)) == TRUE);
   assert(compareLongDouble(getArgument(oneOne), atan(1)) == TRUE);
   assert(compareLongDouble(getModulus(minusTwoTwo), sqrt(8)) == TRUE);
   assert(compareLongDouble(getArgument(minusTwoTwo), atan2(2,-2)) == TRUE);
   assert(compareLongDouble(getModulus(threeFour), 5) == TRUE);
   assert(compareLongDouble(getArgument(threeFour), atan2(4, 3)) == TRUE);
   assert(compareLongDouble(getModulus(minusTwoMinusSix), sqrt(40)) == TRUE);
   assert(compareLongDouble(getArgument(minusTwoMinusSix), atan2(-6, -2)) == TRUE);
   assert(compareLongDouble(getModulus(oneMinusOne), sqrt(2)) == TRUE);
   assert(compareLongDouble(getArgument(oneMinusOne), atan2(-1, 1)) == TRUE);
   assert(compareLongDouble(getModulus(zeroTwo), 2) == TRUE);
   assert(compareLongDouble(getArgument(zeroTwo), atan2(2, 0)) == TRUE);
   assert(compareLongDouble(getModulus(oneZero), 1) == TRUE);
   assert(compareLongDouble(getArgument(oneZero), atan2(0, 1)) == TRUE);
   printf("Testing completed: UNIT COMPLIES\n\n");

   disposeComplex(zeroZero);
   disposeComplex(oneOne);
   disposeComplex(minusTwoTwo);
   disposeComplex(threeFour);
   disposeComplex(minusTwoMinusSix);
   disposeComplex(oneMinusOne);
   disposeComplex(zeroTwo);
   disposeComplex(oneZero);
   printf("Testing completed: PROGRAM COMPLIES\n");
   return EXIT_SUCCESS;
}

//compares two given double-point precision values for equality with a small error bound
bool compareLongDouble(long double a, long double b) {

   return fabs(a - b) < EPSILON;
}
