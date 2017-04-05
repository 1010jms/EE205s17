/* main2.cpp
 * Jaymark Ganibi
 * EE205 S1
 * Objective: Lab 9 Task 3 and 4, implement queues as arrays and lists
 * 3/14/17
 */

#include "queue-array.h"
//#include "queue-list.h"

using namespace std;

int main() {

	//test array functions
	cout << "Testing array: ";
	queue q;
/*	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.prettyprint();
	q.dequeue();
	q.prettyprint();
	q.enqueue(8);
	q.prettyprint();
	q.dequeue();
	q.prettyprint();*/

	for(int i = 0; i <= SIZE; i++){
		q.enqueue(i);
	}
	
	q.prettyprint();

	int front = q.dequeue();
	q.enqueue(9);
	q.enqueue(10);

	q.prettyprint();

	int second = q.dequeue();
	int third = q.dequeue();
	q.enqueue(10);

	q.prettyprint();

	cout << endl << "First Dequeued Value = " << front << endl;
	cout << "Second Dequeued Value = " << second << endl;
	cout << "Third Dequeued Value = " << third << endl << endl;

	//test list functions
	/*cout << "Testing list: ";
	lqueue lq;
	lq.lenqueue(1);
	lq.lenqueue(2);
	lq.lenqueue(3);
	lq.ldequeue();
	lqueue* plq = &lq;
	lq.lprettyprint(plq);
	*/
}
