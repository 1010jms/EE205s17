/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * File Name: savingsAccount.cpp
 * Objective: Create savings account and have it inherit from
 * basic account
 *
 * Date Started: 3/21/17
 * Date Finished: 3/21/17
 */

#include "savingsAccount.h"

SavingsAccount::SavingsAccount(){
	setAccountNumber(0);
	setName("");
	setBalance(0);
	withdrawNumber = 0;
}

SavingsAccount::SavingsAccount(long int a, string n, float b, int w) {
	setAccountNumber(a);
	setName(n);
	setBalance(b);
	withdrawNumber = w;
}

SavingsAccount::SavingsAccount(SavingsAccount& sa) {
	setAccountNumber(sa.getAccountNumber());
	setName(sa.getName());
	setBalance(sa.getBalance());
	withdrawNumber = sa.withdrawNumber;
}

void SavingsAccount::monthly_check() {
	withdrawNumber++;
	float b = getBalance();

	if(withdrawNumber > 2) {
		withdraw(3);
		cout <<"Amount of Withdraws Exceeds 2. $3 has been Charged from Your Account." << endl;
	}

	if(b < 100) {
		withdraw(10);
		cout << "Balance is Below $100. $10 has been Charged from Your Account." << endl;
	}
}

int SavingsAccount::getWithdrawNumber() {
	return withdrawNumber;
}

void SavingsAccount:: setWithdrawNumber(int w) {
	withdrawNumber = w;
}
 
