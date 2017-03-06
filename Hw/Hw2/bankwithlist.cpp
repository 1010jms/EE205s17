/* Project Assignment 2
 *
 * Team Name: North Shore Remembers
 * Team Members: Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 *
 * File Name: bankwithlist.cpp
 * Objective: Create a basic bank account w/ singly linked list.
 *
 * Revision Date Start: 3/1/17
 * Revision Date Finished: 
 */

#include "singlylinked.h"

int main() {
char command;
int count = 0;
SinglyLinkedList accounts;
vector<struct SLink> ba;
SLink ba2;

long int a; string n; double b;

cout << "Please Enter Command: ";
cin >> command;

while(command != 'q'){
	if(command == 'c'){
/*		a = rand();
	
		cout << "Please Enter Name of Account: ";
		cin >> n;

		cout << "Please Enter Account Balance: ";
		cin >> b;

		ba.push_back(SLink());
		ba[count].accNum = a;
		ba[count].name = n;
		ba[count].bal = b;*/

		cout << "Count = " << count << endl;
		ba.push_back(SLink());
		accounts.create_account(ba, accounts.getHead(), count);
		count++;

		//Inserts values into SLink ba
/*		if(ba.value == 0 && ba2.value == 0){
			cout << "Writing in ba" << endl;
			ba.value = 1;
			ba.accNum = a;
			ba.name = n;
			ba.bal = b;

			accounts.create_account(ba, accounts.getHead());
		}

		//If SLink ba is used, insert values into ba2
		//and clear ba
		else if(ba.value == 1 && ba2.value == 0){
			cout << "Writing in ba2" << endl;
			ba2.value = 1;
			ba2.accNum = a;
			ba2.name = n;
			ba2.bal = b;

			accounts.create_account(ba2, accounts.getHead());
			ba.value = 0;
		}

		//If SLink ba2 is used, insert values into ba
		//and clear ba
		else if(ba.value == 0 && ba2.value == 1) {
			cout << "Writing in ba" << endl;
			ba.value = 1;
			ba.accNum = a;
			ba.name = n;
			ba.bal = b;

			accounts.create_account(ba, accounts.getHead());
			ba2.value = 0;
		}*/
	}
	
	if(command == 'p'){
		//Print all of the available accounts
		accounts.print_account(accounts.getHead());
	}

	cout << "Please Enter Command: ";
	cin >> command;

}

return 0;
}
