/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: singlylinked.h
 * Objective: Create a Single and Double Linked List
 *
 * Date Started: 2/14/17
 * Date Finished: 
 */

#include <iostream>
using namespace std;

struct SLink { 		//Singly Linked Node
	int value;
	string name;
	double bal;
	SLink* succ;
	SLink(const int& v, SLink* s = 0)
		:value(v), succ(s) {}
};

class SinglyLinkedList {
public:
	SinglyLinkedList() { head = NULL; tail=NULL; }
	SLink* insert(SLink* n, SLink* p);  //insert n before p, return pointer to n
	SLink* add(SLink* p, SLink* n);	//insert n after p, return pointer to n
	SLink* erase(SLink* p);		//erase node at p
	SLink* find(SLink* p, const int& s);	//find node with specified content
	SLink* advance(SLink* p, int n);
	void append(SLink *p);		//add a list node at the end
	void print_all(SLink* p);

	SLink* getHead() { return head; }
	SLink* setHead(SLink *p) { head = p; }

private:
	//class SLink { //… }    //could also be struct Link {  }
	SLink* head;
	SLink* tail; int size;  //one or the other is sufficient
};
