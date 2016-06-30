/*
Contributor: Constantinos Paraskevopoulos
Creation Date: 1 February 2016
Last Revision: 26 February 2016
Description: This file defines a generic string data type.
*/

#include <stdio.h>
#include <string.h>

#ifndef ITEM_H
#define ITEM_H

typedef char *item;
typedef item key;

#define key(it) ((it))
#define del(it) free((it))
#define copy(s) strdup((s))
#define show(s) printf("%s", (s))
#define eq(s,t) (strcmp((s), (t)) == 0)
#define lt(s,t) (strcmp((s), (t)) < 0)
#define le(s,t) (strcmp((s), (t)) <= 0)
#define gt(s,t) (strcmp((s), (t)) > 0)
#define ge(s,t) (strcmp((s), (t)) >= 0)

#endif
