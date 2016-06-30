/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 18 February 2016
Last Revision: 26 February 2016
Description: This is an abstract interface file for Complex.c.
*/

#include "bool.h"

#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complexNumber *Complex;

//complex number initialisation
Complex createComplex(long double real, long double imaginary);
Complex copyComplex(Complex z);
void disposeComplex(Complex z);

//complex number query
void showComplex(Complex z);
bool isEqual(Complex z1, Complex z2);
long double getRealPart(Complex z);
long double getImaginaryPart(Complex z);
Complex getComplexConjugate(Complex z);
Complex getInverse(Complex z);
long double getModulus(Complex z);
long double getArgument(Complex z);

//complex number operations
Complex add(Complex z1, Complex z2);
Complex subtract(Complex z1, Complex z2);
Complex multiply(Complex z1, Complex z2);
Complex divide(Complex z1, Complex z2);

#endif
