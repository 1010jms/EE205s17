/* queue-array.cpp
 * Jaymark Ganibi
 * EE205 S1
 * Objective: implement queue as an array
 * 3/14/17
 */

#include "queue-array.h"

using namespace std;

bool queue::isEmpty() {
	if(head == 0 && tail == 0) return true;
	else return false;
}

bool queue::isFull() {
	return (tail+1)%(size) == head ? true: false;
}

void queue::enqueue(int x, int q) {
	cout << "Enqueing " << x << " to queue " << q << endl;
	if(isFull()) { 
		cout << "Queue " << q << " is full" << endl;
	}
	else {
		a[tail] = x;
		tail = (tail+1)%(size);
//		a[tail] = x;
	}
}

int queue::dequeue(int q) {
	if(isEmpty()) {
		cout << "Queue " << q << " is empty" << endl;
		return 0;
	}
	else { 
		int h = a[head];
		a[head] = 0;
		head = (head+1)%(size);
//		int h = a[head];
		cout << "Dequeing " << h << endl;
		return h;
	}
}

void queue::prettyprint(int q) {
	int length = (tail+size-head)%size;
	cout << "Printing Queue " << q << ": ";
	for(int i = 0; i < length; i++) {
		int ii = (head + i)% size;
		cout << a[ii] << " ";
	}
	cout << endl;
}

