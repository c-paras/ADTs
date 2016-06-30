#!/bin/sh
#Written by Constantinos Paraskevopoulos in February 2016
#Compiles and runs test suites for a collection of ADTs

divider='################################################################################'
binaries='stack queue set bag heap priorityQueue HashTable/htable list complex Trie/trie'
compiling_options='gcc -Wall -Werror -O3 -std=gnu99 -o'
rm -f $binaries

#compiles adts
$compiling_options stack Stack.c testStack.c
$compiling_options queue Queue.c testQueue.c
$compiling_options set Set.c testSet.c
$compiling_options bag Bag.c testBag.c
$compiling_options heap Heap.c testHeap.c -lm
$compiling_options priorityQueue PriorityQueue.c testPriorityQueue.c
$compiling_options HashTable/htable HashTable/HashTable.c HashTable/hash.c HashTable/testHashTable.c
$compiling_options list List.c testList.c
$compiling_options complex Complex.c testComplex.c -lm
$compiling_options Trie/trie Trie/Trie.c Trie/testTrie.c

#runs tests
for test in $binaries
do
	echo $divider
	echo $ valgrind ./$test
	valgrind ./$test
done
echo $divider
