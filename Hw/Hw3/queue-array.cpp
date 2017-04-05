/* queue-array.cpp
 * Jaymark Ganibi
 * EE205 S1
 * Objective: implement queue as an array
 * 3/14/17
 */

#include "queue-array.h"

using namespace std;

bool queue::isEmpty() {
	if(head == 0 && tail == 0)	return true;

	else 	return false;
}

bool queue::isFull() {
	return (tail+1)%SIZE == head ? true: false;
}

void queue::enqueue(int x) {
	cout << "Enqueing " << x << endl;
	if(isFull()) { 
//		head = tail = 0; 
		cout << "Queue is full" << endl;
	}
	else {
//		tail = (tail+1)%SIZE;
		a[tail] = x;
		tail = (tail+1)%SIZE;
	}
}

int queue::dequeue() {
	int dq = 0;
	cout << "Dequeuing " << a[head] << endl;
	if(isEmpty()) {
		cout << "Queue is empty" << endl;
		return 0;
	}
	else if(head == tail) {
		cout << "head == tail" << endl;
		head = tail = 0;
	}
	else { 
		dq = a[head];
		a[head];
		head = (head+1)%SIZE;
	}
	
	return dq;
}

void queue::prettyprint() {
	int length = (tail+SIZE-head)%SIZE;
	cout << "Printing Queue: ";
	for(int i = 0; i < length; i++) {
		int ii = (head + i)% SIZE;
		cout << a[ii] << " ";
	}
	cout << endl;
}
