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
#include <string>
#include <vector>
using namespace std;

struct SLink { 		//Singly Linked Node
	int value;
	
	long int accNum;		//Account Number
	string name;			//Name
	double bal;			//Balance

	SLink* succ;
	SLink() {
		value = 0;
		accNum = 0;
		name = "";
		bal = 0;
		succ = 0;
	}
	SLink(const int& v, long int& a, string& n, double& b, SLink* s = 0) : value(v), accNum(a), name(n), bal(b), succ(s) {}

/*	long int setAccNum(long int a) { accNum = a; }
	string setName(string n) {name = n; }
	double setBal(double b) {bal = b; } */
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

	SLink* create_account(vector<struct SLink> ba, SLink* p, int count);
	
	SLink* delete_account(SLink* p);
	void print_account(SLink* p);

	SLink* getHead() { return head; }
	SLink* setHead(SLink *p) { head = p; }

private:
	//class SLink { //… }    //could also be struct Link {  }
	SLink* head;
	SLink* tail; int size;  //one or the other is sufficient
};
