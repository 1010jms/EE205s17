/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: doublylinked.cpp
 * Objective: Create a Double Linked List
 *
 * Date Started: 2/14/17
 * Date Finished: 
 */

#include "doublylinked.h"

DLink* DoublyLinkedList::insert(DLink* n, DLink *p) {  //insert n before p
        if (n == 0) return p;
        if (p == 0) return n;
        n->succ = p;
        if (p->pred)
                p->pred->succ = n;
        n->pred = p->pred;
        p->pred = n;

	if(head == p) head = n;
	if(tail == p) tail->pred = n;
        return n;
}

DLink* DoublyLinkedList::add(DLink* p, DLink* n) { //insert n after p
	if(n == 0) return p;
	if(p == 0) return n;

	n->pred = p;

	if(p->succ) p->succ->pred = n;
	n->succ = p->succ;
	p->succ = n;

	if(head == p){	
		n->succ = head->succ;
		head->succ = n;
		n->pred = head;
	}

	if(tail == p){
		tail = n;
		tail->pred = p;
	}

	return n;
}

DLink* DoublyLinkedList::erase(DLink *p) {   //version 3; the version in Stroustrup book
        if (p == 0) return 0;

        if (p->succ) {
                p->succ->pred = p->pred;
                if (p == head) head = p->succ;
        }
        if (p->pred) {
                p->pred->succ = p->succ;
                if (p == tail)  tail = p -> pred;
        }
        return p->succ;
}

DLink* DoublyLinkedList::find(DLink* p, const int& s){
	while(p != NULL){
		if(p->value == s){
			cout << "Value " << s << " found." << endl;
			return p;
		}
		p = p->succ;
	}
	
	cout << "Value " << s << " not found." << endl;
	return p;
}

DLink* DoublyLinkedList::advance(DLink* p, int n){
	int count = 1;
	while(count < n && p != NULL){
		p = p->succ;
		count++;
	} 

	if(p == NULL) cout << "Link " << n << " Value Not Found." << endl;
	else cout << "Link " << n << " Value = " << p->value << endl;

	return p;
}

void DoublyLinkedList::append(DLink *p) {
	//insert(p, tail);
	if (head == NULL) {
		head = p;
		p->pred = NULL;
	}
	if (tail != NULL) {
		tail->succ = p;
		p->pred = tail;
	}
	p->succ = NULL;
	tail = p;
	return;
}

void DoublyLinkedList::print_all(DLink* p) {
	while (p) {
		cout << p->value;
		if (p = p->succ) cout << ", ";
	}
	cout << "\n";
}
