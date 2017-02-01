/* Lab 4 Task 1
 * Objective: Create a header file for basicAccount
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 1/31/17
 * Date Finished: 
 */

#include <string>
#include <iostream>
using namespace std;

class BasicAccount {
public:
	BasicAccount(){
		accountNumber = 0;
		name = "";
		balance = 0;
	}

	BasicAccount(long int a, string n, float b){
		accountNumber = a;
		name = n;
		balance = b;
	}

	BasicAccount(BasicAccount& ba){
		balance = ba.balance;
		name = ba.name;
	}

	void withdraw(float amount){
		balance -= amount;
	}

	void deposit(float amount){
		balance += amount;
	}

	float getBalance(){
		return balance;
	}

	void setAccountNumber(long int a){
		accountNumber = a;
	}	

	void setName(string n){
                name = n;
        }

	void setBalance(float amount){
		balance = amount;
	}

	void display(){
		cout << "Account Number: " << accountNumber << endl;
		cout << "Name: " << name << endl;
		cout << "Balance: " << balance << endl;
		cout << endl;
	}
private:
	long int accountNumber;
	string name;
	float balance;
};	
