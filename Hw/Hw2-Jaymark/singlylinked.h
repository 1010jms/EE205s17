/* Project Assignment 2
 * File Name: singlylinked.h
 * 
 * Team Name: North Shore Remembers
 * Team Members: Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 * EE205 S1
 *
 * Objective: Initialize basic functions of singly-linked lists
 * 
 * Revision Started: 2/26/17
 * Revision Finished: 3/4/17
 */

#include <iostream>
#include <string>

using namespace std;

struct SLink {
	//Locates account in the list
	int value;

	//Account information, entered by user	
	long int id;
	string name;
	double bal;

	SLink* succ;
	SLink(SLink* s = 0)
		:value(value), succ(s) {}

};

class SinglyLinkedList {
public:
	SinglyLinkedList() { head = NULL; tail = NULL; }
	SLink* insert(SLink* p, SLink* n);//insert n before p, return ptr n
	SLink* erase(SLink* p);	//erase node at p
	//from b to NULL, find node with specified content s
	SLink* find(SLink* b, int s);
	void append(SLink* p);	//add a list node at the end
	void print_all(SLink* p);

	//creating an account
	SLink* createAccount(SinglyLinkedList acct, int v);
	//printing an account
	SLink* printAccount(SLink* p);
	//deleing an account
	SLink* deleteAccount(SLink* p);
	//withdraw
	SLink* withdraw(SLink* p);
	//deposit
	SLink* deposit(SLink* p);

	SLink* getTail() { return tail; }
	SLink* setTail(SLink* p) { tail = p; }
	SLink* getHead() { return head; }
	SLink* setHead(SLink* p) { tail = p; }
private:
	SLink* head;
	SLink* tail; //or int size to keep track of the tail
};
