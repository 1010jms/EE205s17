/* queue-array.h
 * Jaymark Ganibi
 * EE205 S1
 * Objective: prototypes of basic queue functions implemented by array
 * 3/14/17
 */

#include <iostream>
#include <string>

#define SIZE 100000

using namespace std;

class queue {
private:
	int a[SIZE];
	int head;
	int tail;
	int size;
public:
	//Constructor where head = tail = -1
	queue() {
		head = 0;
		tail = 0;
		size = SIZE;
	}
	
	queue(int s) {
		head = 0;
		tail = 0;
		size = s;
	}

	void setSize(int s) { size = s;}

	//Check if queue is empty
	bool isEmpty();

	//Check if queue is full
	bool isFull();

	//Insert element in queue at the end of the queue
	void enqueue(int x, int q);

	//Remove element from the front of the queue
	//Record the element that was removed 
	//to move that element from queue 1 to queue 2 or 3
	int dequeue(int q);

	//print elements in queue from front to end
	void prettyprint(int q);
};

