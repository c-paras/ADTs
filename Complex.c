/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 18 February 2016
Last Revision: 26 February 2016
Description: This program performs operations on an abstract complex number data type.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bool.h"
#include "Complex.h"

//concrete representation of a complex number
typedef struct complexNumber {
   long double real;
   long double imaginary;
} complexNumber;

//creates and returns a new complex number with given real and imaginary parts
Complex createComplex(long double real, long double imaginary) {

   Complex new = malloc(sizeof(complexNumber));
   assert(new != NULL);
   new->real = real;
   new->imaginary = imaginary;
   return new;
}

//returns an exact copy of a given complex number
Complex copyComplex(Complex z) {

   assert(z != NULL);
   Complex copy = createComplex(z->real, z->imaginary);
   return copy;
}

//frees all memory associated with a given complex number
void disposeComplex(Complex z) {

   assert(z != NULL);
   free(z);
}

//displays a given complex number in cartesian and polar forms
void showComplex(Complex z) {

   assert(z != NULL);
   printf("Cartesian form: %Lg ", z->real);
   if (z->imaginary >= 0) {
      printf("+ %Lgi\n", z->imaginary);
   } else {
      printf("- %Lgi\n", -z->imaginary);
   }

   //prints polar form iff it exists
   if ((z->real != 0 || z->imaginary != 0) == FALSE) return;
   long double modulus  = getModulus(z);
   long double argument = getArgument(z);
   printf("Trigonometric polar form: ");
   printf("%.2Lg * (cos(%.2Lg) + i * sin(%.2Lg))\n", modulus, argument, argument);
   printf("Exponential polar form: ");
   printf("%.2Lg * exp(i%.2Lg)\n", modulus, argument);
}

//indicates whether two given complex numbers are equal
bool isEqual(Complex z1, Complex z2) {

   assert(z1 != NULL && z2 != NULL);
   return z1->real == z2->real && z1->imaginary == z2->imaginary;
}

//returns the real part of a given complex number
long double getRealPart(Complex z) {

   assert(z != NULL);
   return z->real;
}

//returns the imaginary part of a given complex number
long double getImaginaryPart(Complex z) {

   assert(z != NULL);
   return z->imaginary;
}

//returns the complex conjugate of a given complex number
Complex getComplexConjugate(Complex z) {

   assert(z != NULL);
   return createComplex(z->real, -z->imaginary);
}

//returns the multiplicative inverse of a given complex number
Complex getInverse(Complex z) {

   assert(z != NULL);
   assert(z->real != 0 || z->imaginary != 0);
   long double denominator = (z->real * z->real) + (z->imaginary * z->imaginary);
   return createComplex(z->real / denominator, -z->imaginary / denominator);
}

//returns the modulus (magnitude) of a given complex number
long double getModulus(Complex z) {

   assert(z != NULL);
   return sqrt((z->real * z->real) + (z->imaginary * z->imaginary));
}

//returns the principal argument (amplitude) of a given complex number if it exists
long double getArgument(Complex z) {

   assert(z != NULL);
   assert(z->real != 0 || z->imaginary != 0);
   return atan2(z->imaginary, z->real);
}

//returns the sum of any two given complex numbers
Complex add(Complex z1, Complex z2) {

   assert(z1 != NULL && z2 != NULL);
   return createComplex(z1->real + z2->real, z1->imaginary + z2->imaginary);
}

//returns the difference between any two given numbers
Complex subtract(Complex z1, Complex z2) {

   assert(z1 != NULL && z2 != NULL);
   return createComplex(z1->real - z2->real, z1->imaginary - z2->imaginary);
}

//returns the product of any two given complex numbers
Complex multiply(Complex z1, Complex z2) {

   assert(z1 != NULL && z2 != NULL);
   long double real = (z1->real * z2->real) - (z1->imaginary * z2->imaginary);
   long double imaginary = (z1->imaginary * z2->real) + (z1->real * z2->imaginary);
   return createComplex(real, imaginary);
}

//returns the quotient of any two given complex numbers, except when z2 = 0 + 0i
Complex divide(Complex z1, Complex z2) {

   assert(z1 != NULL && z2 != NULL);
   assert(z2->real != 0 || z2->imaginary != 0);
   Complex inverse = getInverse(z2);
   Complex product = multiply(z1, inverse);
   disposeComplex(inverse);
   return product;
}
