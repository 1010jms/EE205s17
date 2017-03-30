/* Lab 4 Task 1
 * Objective: Create a header file for basicAccount
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 1/31/17
 * Date Finished: 2/6/17 
 */

#include <string>
#include <iostream>
using namespace std;

class BasicAccount {
public:
	BasicAccount();
	BasicAccount(long int a, string n, float b);
	BasicAccount(BasicAccount& ba);
	void withdraw(float amount);
	void deposit(float amount);
	long int getAccountNumber();
	string getName();
	float getBalance();
	void setAccountNumber(long int a);
	void setName(string n);
	void setBalance(float amount);
	void prettyprint();

	void operator = (const BasicAccount& ba);
	bool operator == (const BasicAccount& ba);

private:
	long int accountNumber;
	string name;
	float balance;
};
