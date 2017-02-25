/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: singlylinked.cpp
 * Objective: Create a Single and Double Linked List
 *
 * Date Started: 2/14/17
 * Date Finished: 
 */

#include "singlylinked.h"

SLink* SinglyLinkedList::insert(SLink* n, SLink *p) {  //insert n before p

        SLink *s(head);

        if (n == 0) return p;
        if (p == 0) return n;
        while(s != NULL){
                if(p == head){
                        head = n;
                        n->succ = p;
                }
                if(s->succ == p){
                        s->succ = n;
                        n->succ = p;
                }
                s = s->succ;
        }
        return s;
}

SLink* SinglyLinkedList::add(SLink* p, SLink* n){
	if(n == 0) return p;
	if(p == 0) return n;

	SLink* s(head);

	while(s != NULL){
		if(p == head) {
			n->succ = head->succ;
			head->succ = n;
		}

		if(s == p){
			n->succ = s->succ;
			s->succ = n;
		}
		s = s->succ;
	}
	return s;
}

SLink* SinglyLinkedList::erase(SLink *p) {
        SLink* s(head);
        if (p == 0) return 0;

        while(s->succ != NULL){
                if(p == head) head = p->succ;
                if(s->succ == p){
                        s->succ = p->succ;
                }
                else
                        s = s->succ;
        }

        return s;
}

SLink* SinglyLinkedList::find(SLink* p, const int& s){
	while(p != NULL){
		if(p->value == s){
//			cout << "Value " << s << " found." << endl;
			return p;
		}
		p = p->succ;
	}

//	cout << "Value " << s << " not found." << endl;
	return NULL;
}

SLink* SinglyLinkedList::advance(SLink* p, int n){
	int count = 1;
	while(count < n && p != NULL){
		p = p->succ;
		count++;
	}

//	if(p == NULL) cout << "Link " << n << " Value Not Found." << endl;
//	else cout << "Link " << n << " Value = " << p->value << endl;

	return p;
}

void SinglyLinkedList::append(SLink *p) {
	//cout << "append\n";
	if (head == NULL) {
		head = p;
	}
	if (tail != NULL) {
		tail->succ = p;
	}
	p->succ = NULL;
	tail = p;
	return;
}

void SinglyLinkedList::print_all(SLink* p) {
	while (p) {
		cout << p->value;
		if (p = p->succ) cout << ", ";
	}
	cout << "\n";
}
