/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: doublylinked.h
 * Objective: Create a Double Linked List
 *
 * Date Started: 2/14/17
 * Date Finished: 
 */

#include <iostream>
using namespace std;

struct DLink { 		//Doubly Linked Node
	int value;
	DLink* pred;
	DLink* succ;
	DLink(const int& v, DLink* p = 0, DLink* s = 0)
		:value(v), pred(p), succ(s) {}
};

class DoublyLinkedList {
public:
	DoublyLinkedList(){ head = NULL; tail = NULL; } 
	DLink* insert(DLink* n, DLink* p);
	DLink* add(DLink* p, DLink* n);
	DLink* erase(DLink* p);
	DLink* find(DLink* p, const int& s);
	DLink* advance(DLink* p, int n);
	void append(DLink *p);
	void print_all(DLink* p);

	DLink* getHead() { return head; }
	DLink* setHead(DLink *p) { head = p; }

private:
	DLink* head;
	DLink* tail; int size;  //one or the other is sufficient
};

