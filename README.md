# ADTs
A collection of generic ADTs written in C

The ADTs provided here are written in the C programming language
and have been compiled on Ubuntu 64-bit 14.04 LTS using GCC 4.8.
Each of the programs were compiled using the Wall, Werror, O3 and
std=gnu99 options alongside their corresponding test suite files.
All programs have been tested thoroughly including a check for
memory leaks using Valgrind 3.10.0 but are not guaranteed to be bug-free.

Nine of the ten ADTs are generic ADTs and can be used in conjunction
with any of the item.h files provided or any other properly-formatted
item.h file. The trie ADT makes no assumption as to the data type of
the items themselves but assumes that all keys are strings and
as a result, is not a true generic ADT.

Copyright (C) 2016 Constantinos Paraskevopoulos

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
