/* queue-array.cpp
 * Jaymark Ganibi
 * EE205 S1
 * Objective: prototypes of basic queue functions implemented by array
 * 3/14/17
 */

#include <iostream>
#include <stdlib.h>
#include <string>

#define SIZE 10

using namespace std;

class queue {
private:
	int size;
	int a[SIZE];
	int head;
	int tail;
public:
	//Constructor where head = tail = -1
	queue() {
		size = 10;
		head = 0;
		tail = 0;
	}

	//Check if queue is empty
	bool isEmpty();

	//Check if queue is full
	bool isFull();

	//Insert element in queue at the end of the queue
	void enqueue(int x);

	//Remove element from the front of the queue
	int dequeue();

	//print elements in queue from front to end
	void prettyprint();
};

