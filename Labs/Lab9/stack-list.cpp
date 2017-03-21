/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: stack-list.cpp
 * Objective: Implement a stack using a singly linked list
 *
 * Date Started: 14 March 2017
 * Date Finished: 
 */

#include "stack.h"
#include <vector>

// Stack::Stack() { }

SinglyLinkedList Stack::push_link(SLink* s, SinglyLinkedList sll) {
	SLink* temp = sll.getHead();
	int count = 0;
	while(temp != NULL){
		temp = temp->succ;
		count++;
	}

	if(count > N) {
		cout << "Error: Stack is Full" << endl;
	}

	else {
		sll.append(s);
	}

	return sll;
}

SinglyLinkedList Stack::pop_link(SinglyLinkedList sll)
{
	SLink* temp = sll.getHead();
	while(temp->succ != NULL) temp = temp->succ;

	sll.erase(temp);

	return sll;
}

void Stack::prettyprint_link(SLink *s) {
	while(s != NULL) {
		cout << s->value << endl;
		s = s->succ;
	}

}
