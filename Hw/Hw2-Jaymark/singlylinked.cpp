/* Project Assignment 2
 * File Name: singlylinked.cpp
 *
 * Team Name: North Shore Remembers
 * Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 * EE205 S1
 *
 * Objective: Write basic functions for singly linked lists
 * 
 * Revision Started: 2/26/17
 * Revision Finished: 3/4/17
 */

#include "singlylinked.h"

using namespace std;

void SinglyLinkedList::append(SLink* p) {
	if(p == NULL)
		return;

	else {
		if(head == NULL) {
			p->succ = NULL;
			head = p;
			tail = p;
		}
		else {
			tail->succ = p;
			tail = p;
		}
	}
	p = p->succ;
}

//deposit money into an account
SLink* SinglyLinkedList::deposit(SLink* p) {
	cout << "\t\t\t=======Depositing=======" << endl;
	int n;

	cout << "\t\t\tEnter the amount you would like to deposit: ";
	cin >> n;
	
	p->bal += n;
	printAccount(p);
}

//withdraw money from an account
SLink* SinglyLinkedList::withdraw(SLink* p) {
	cout << "\t\t\t========Withdraw========" << endl;
	int n;

	cout << "\t\t\tEnter the amount you would like to withdraw: ";
	cin >> n;

	while(p->bal < n) {
		cout << "\t\t\tERROR: INSUFFICIENT FUNDS TO WITHDRAW" << endl;
		cout << "\t\t\tEnter the amount you would like to withdraw: ";
		cin >> n;
	}
	if(p->bal >= n) {
		p->bal -= n;
		printAccount(p);
	}
}

//user creates a new bank account, which is then added to the list of accounts
SLink* SinglyLinkedList::createAccount(SinglyLinkedList acct, int v) {

	//create a new account struct
	SLink an;	
	an.value = v;

	//user determines features of account
	//1. id number
	long int id;
	cout << "\t\t\tEnter account number: ";
	cin >> id;
	an.id = id;

	//2. name of the account's owner
	string n;
	cout << "\t\t\tEnter the name of the account: ";
	cin >> n;
	an.name = n;

	//3. balance in the account
	double b;
	cout << "\t\t\tEnter the balance: ";
	cin >> b;
	an.bal = b;

	//Print the newly created account
	cout << endl << "\t\t\t==Successfully created account==" << endl;

	//Add new account to the accounts list
	SLink* a = &an;
	acct.append(a);
	acct.printAccount(a);
	acct.print_all(acct.getHead());
}

//print an account
SLink* SinglyLinkedList::printAccount(SLink* p) {
	cout << "\t\t\tAccount #"  << p->id << ": "
	     << p->name << endl
	     << "\t\t\tBalance: $" << p->bal 	<< endl << endl;
}


//insert n before p, return pointer to n
SLink* SinglyLinkedList::insert(SLink* p, SLink* n) {
	SLink* succ = NULL;
	//n before p
	n->succ = p;
	return n;
}

//search a list from first to last element, looking for value
//returns the first pointer containing the desired value
SLink* SinglyLinkedList::find(SLink* beg, int pinput) {
	SLink* p = beg;
	long int val;
	string s;

	//display error message until proper command is entered
	while(pinput != 1 && pinput != 2) {
		cout << "\t\t\t"
		     << "\t\t\tEnter 1(acct number) or 2(acct name): ";
		cin >> pinput; 
	}

	//looking for an account number
	if(pinput == 1) {
		cout << endl << "\t\t\tEnter account number: ";
		cin >> val;
		while(p->succ != NULL) {
			if(p->id != val) p = p->succ;
			else {
				cout << "\t\t\tFound " << p->id << endl; 
				printAccount(p); 
				return p;
			}
		
		}

		//last element of the list
		if(p->succ == NULL) {
			//unsuccessful find
			if(p->id != val) {
				cout << "\t\t\t"
				     << "Could not find corresponding account" 
				     << endl << endl;
				return NULL;
			}
			//successful find
			else {
				cout << "\t\t\tFound " << p->id << endl; 
				printAccount(p); 
				return p;
			}
		}
	}
	
	//looking for a name
	else if(pinput = 2) {
		cout << "\t\t\tEnter account name: ";
		cin >> s;

		while(p->succ != NULL) {
			if(p->name != s) p = p->succ;
			else {
				cout << "\t\t\tFound " << p->name << endl; 
				printAccount(p); 
				return p;
			}
		}

		//last element of the list
		if(p->succ == NULL) {
			//unsuccessful find
			if(p->name != s) {
				cout << "\t\t\t"
				     << "Could not find corresponding account" 
				     << endl << endl;
				return NULL;
			}
			//successful find
			else {
				cout << "\t\t\tFound " << p->name << endl; 
				printAccount(p); 
				return p;
			}
		}
	}	
}

//delete an existing account
SLink* SinglyLinkedList::erase(SLink* p) {
	SLink* s(head);
	if(p == 0) return 0;

	while(s->succ != NULL) {
		if(p == head) head = p->succ;
		if(s->succ == p) s->succ = p->succ;
		else s = s->succ;
	}
	
	return s;
}

//print a list
void SinglyLinkedList::print_all(SLink* p) {
	cout << "\t\t\t========Current Accounts========" << endl;
	while(p->succ != NULL) {
		printAccount(p);
		p = p->succ;
	}
	if(p->succ == NULL) {
		printAccount(p);
	}
	cout << endl;
}


