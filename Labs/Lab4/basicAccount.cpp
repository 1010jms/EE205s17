/* Lab 4 Task 1
 * Objective: Create a .cpp file for basicAccount
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 1/31/17
 * Date Finished: 2/6/17 
 */

#include "basicAccount.h"

BasicAccount::BasicAccount(){
	accountNumber = 0;
	name = "";
	balance = 0;
}

BasicAccount::BasicAccount(long int a, string n, float b){
	accountNumber = a;
	name = n;
	balance = b;
}

BasicAccount::BasicAccount(BasicAccount& ba){
	accountNumber = ba.accountNumber;
	name = ba.name;
	balance = ba.balance;
}

void BasicAccount::withdraw(float amount){
	balance -= amount;
}

void BasicAccount::deposit(float amount){
	balance += amount;
}

float BasicAccount::getBalance(){
	return balance;
}

void BasicAccount::setAccountNumber(long int a){
	accountNumber = a;
}

void BasicAccount::setName(string n){
	name = n;
}

void BasicAccount::setBalance(float amount){
	balance = amount;
}

void BasicAccount::prettyprint(){
	cout << "Account Number: " << accountNumber << endl;
	cout << "Name: " << name << endl;
	cout << "Balance: " << balance << endl;
	cout << endl;
}

void BasicAccount::operator = (const BasicAccount& ba){
	accountNumber = ba.accountNumber;
	name = ba.name;
	balance = ba.balance;
}

bool BasicAccount::operator == (const BasicAccount& ba){
	if(accountNumber == ba.accountNumber
	    && name == ba.name 
	    && balance == ba.balance)	return true;

	else return false;
}
	

