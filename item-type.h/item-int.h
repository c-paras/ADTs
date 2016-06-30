/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This file defines a generic integer data type.
*/

#include <stdio.h>

#ifndef ITEM_H
#define ITEM_H

typedef int item;
typedef item key;

#define key(it) ((it))
#define del(it) ((it = it))
#define copy(x) ((x))
#define show(x) printf("%d", (x))
#define eq(x,y) ((x) == (y))
#define lt(x,y) ((x) < (y))
#define le(x,y) ((x) <= (y))
#define gt(x,y) ((x) > (y))
#define ge(x,y) ((x) >= (y))

#endif
