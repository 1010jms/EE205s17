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

SLink* SinglyLinkedList::create_account(vector<struct SLink> ba, SLink* p, int count){
	long int a = rand();
	string n;
	double b;

	cout << "Count = " << count << endl;

        cout << "Please Enter Name of Account: ";
        cin >> n;

        cout << "Please Enter Account Balance: ";
        cin >> b;

	//Initialize new bank account
        ba[count].accNum = a;
        ba[count].name = n;
        ba[count].bal = b;

	cout << ba[count].accNum << endl;
	cout << ba[count].name << endl;
	cout << ba[count].bal << endl;

	SLink* s1 = &ba[count];	

	cout << endl;
	cout << s1->accNum << endl;
	cout << s1->name << endl;
	cout << s1->bal << endl;

	if(head == NULL) {
		cout << "Head is NULL" << endl;
		head = s1;
	}

	while(p != NULL) {
		cout << "Head is Not NULL" << endl;
		cout << p->accNum << endl;
		cout << p->name << endl;
		cout << p->bal << endl;
		if(p->accNum > s1->accNum) {
			s1->succ = p;
			p = s1;
			p->succ = p->succ->succ;
		//	insert(s1, p);
		//	return p;
		}
	
		cout << p->succ->accNum << endl;
		cout << p->succ->name << endl;
		cout << p->succ->bal << endl;
		p = p->succ;	 
	}

	//if(p == NULL) p = s1;
	return p;
}

SLink* delete_account(SLink* p){ }
	

void SinglyLinkedList::print_account(SLink* p){
	 while (p != NULL) {
                cout << "Account Number: " << p->accNum << endl;
		cout << "          Name: " << p->name << endl;
		cout << "       Balance: " << p->bal << endl;
		cout << endl;

                p = p->succ;
        }

}	
