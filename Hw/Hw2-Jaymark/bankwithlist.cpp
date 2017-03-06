/* Project Assignment 2
 * File Name: bankwithlist.cpp
 *
 * Team Name: North Shore Remembers
 * Team Members: Brandon Wong, Jaymark Ganibi, Jared Shimabukuro
 * EE205 S1
 *
 * Objective: Work with code concepts from previous lessons to make
 * a list of bank accounts. A user should be able to run these functions:
 *      1. create a new account and add it to a list in ascending
 *         account numbers. They cannont open an account with an
 *         existing number.
 *      2. find an existing customer by their name OR account number
 *      3. delete a customer, by their name OR account number
 *
 * Revision Started: 2/26/17
 * Revision Finished: 3/4/17
 */

#include "singlylinked.h"


int main() {
	SinglyLinkedList acct;                          //List of accounts
        char input;                                     //key pressed by user
	int v = 1;

        //Welcome message
        cout << endl << "\t\t\t=====Welcome to Bank of Hawaii=====" 
	     << endl << endl;

	cout << "\t\t\t=====You have 3 Basic Accounts=====" << endl;

	//Create and add Basic Accounts
	v++;
	SLink a1;
	a1.value = v;
	a1.id = 44;
	a1.name = "Alex";
	a1.bal = 1000.59;

	v++;
	SLink a2;
	a2.value = v;
	a2.id = 2;
	a2.name = "Cleopatra";
	a2.bal = 28.75;
	
	v++;
	SLink a3;
	a3.value = v;
	a3.id = 3;
	a3.name = "Jesus";
	a3.bal = 777.99;
	
	SLink* acct1 = &a1;
	SLink* acct2 = &a2;
	SLink* acct3 = &a3;

	acct.append(acct1);
	acct.append(acct2);
	acct.append(acct3);

	acct.print_all(acct.getHead());
	
	//Display user commands
	cout << "\t\t\tCreate a new account\t\t(c)" 	 << endl
	     << "\t\t\tFind an existing account\t(f)"    << endl
	     << "\t\t\tAccount Withdrawal/Deposit\t(w)"	 << endl
             << "\t\t\tDelete an existing account\t(d)"  << endl
	     << "\t\t\tPrint all existing accounts\t(p)" << endl
	     << "\t\t\tEnd the program\t\t\t(e)" 	 << endl << endl;
	
        cout << "\t\t\tEnter your command: ";
	cin >> input;
	cout << endl;

	//Actions taken by user
	while(input != 'e') {
		//create a new account
		if(input == 'c') {
			v += 1;
			cout << "\t\t\t==Creating a new account==" << endl;
			acct.createAccount(acct, v);

			//acct.print_all(acct.getHead());
		}

		//find an existing account
		else if(input == 'f') {
			int pinput;		
			SLink* pp = acct.getHead();
			
			cout << "\t\t\t====Searching for an account====" << endl;

			//find an account number or an account name
			cout << "\t\t\tLooking for an account number\t(1)" << endl
			     << "\t\t\tOR an account under a name\t(2): ";
			cin >> pinput;
		
			acct.find(pp, pinput);
		}

		else if(input == 'w') {
			int winput;
			cout << "\t\t\t========Withdraw/Deposit========" << endl;

			//find an account number or an account name
			cout << "\t\t\tLooking for an account number\t(1)" << endl
			     << "\t\t\tOR an account under a name\t(2): ";
			cin >> winput;
		
			SLink* p = acct.find(acct.getHead(), winput);

			cout << "\t\t\tWithdraw (1) or Deposit(2): ";
			cin >> winput;

			if(winput = 1) acct.withdraw(p);
			else if(winput = 2) acct.deposit(p);
			else cout << "\t\t\tInvalid command, enter new command"
				  << endl;	
		}

		//delete an existing acount
		else if(input == 'd') {
			cout << "\t\t\t=====Deleting an account=====" << endl;
			int pinput;

			cout << "\t\t\tDelete an account number\t(1)" << endl
			     << "\t\t\tOR delete an account name\t(2): ";

			SLink* p = acct.find(acct.getHead(), pinput);
			acct.erase(p);
			//acct.print_all(acct.getHead());
		}		

		//print all accounts
		else if(input == 'p') acct.print_all(acct.getHead());

		//invalid commands
		else cout << "\t\t\tERROR: INVALID COMMAND" << endl;

		//Re-Display user commands
		cout << "\t\t\tCreate a new account\t\t(c)" 	 << endl
	     	     << "\t\t\tFind an existing account\t(f)"    << endl
	     	     << "\t\t\tAccount Withdrawal/Deposit\t(w)"	 << endl
             	     << "\t\t\tDelete an existing account\t(d)"  << endl
	     	     << "\t\t\tPrint all existing accounts\t(p)" << endl
	     	     << "\t\t\tEnd the program\t\t\t(e)" 	 << endl << endl;
	
        	cout << "\t\t\tEnter your command: ";
		cin >> input;
		cout << endl;
	}

	//Outgoing message, when user ends the program
	if(input == 'e') {
		cout << "\t\t\tHave a nice day! Winter is coming..." << endl;
	}	
}

