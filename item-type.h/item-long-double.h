/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This file defines a generic extended-precision floating-point data type.
*/

#include <stdio.h>

#ifndef ITEM_H
#define ITEM_H

#define EPSILON 1e-10

typedef long double item;
typedef item key;

#define key(it) ((it))
#define del(it) ((it = it))
#define copy(x) ((x))
#define show(x) printf("%Lg", (x))
#define eq(x,y) (fabs((x) - (y)) < EPSILON)
#define lt(x,y) ((x) < (y))
#define le(x,y) ((x) <= (y))
#define gt(x,y) ((x) > (y))
#define ge(x,y) ((x) >= (y))

#endif
