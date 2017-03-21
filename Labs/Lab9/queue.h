/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: stack-array.h
 * Objective: Implement a stack using an array
 *
 * Date Started: 7 March 2017
 * Date Finished:
 */

#include <iostream>
#include <vector>
#include "singlylinked.h"
using namespace std;

#define N 100

class Stack {
public:
	Stack();
	int enqueue_array(int val, int array[], int size);
	int dequeue_array(int array[], int size);
	void prettyprint_array(int array[], int size);

	SinglyLinkedList enqueue_link(SLink* s, SinglyLinkedList sll);
	SinglyLinkedList dequeue_link(SinglyLinkedList sll);
	void prettyprint_link(SLink *s);
};


