/* Lab 4 Task 1
 * Objective: Create a cpp file for savingsAccount
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 2/6/17
 * Date Finished: 2/7/17 
 */

#include "savingsAccount.h"

SavingsAccount::SavingsAccount(){
	ba = BasicAccount();
	withdrawNumber = 0;
}

SavingsAccount::SavingsAccount(long int a, string n, float b, int w){
	ba = BasicAccount(a,n,b);
	withdrawNumber = w;
}

SavingsAccount::SavingsAccount(SavingsAccount& sa){
	ba = sa.ba;
	withdrawNumber = sa.withdrawNumber;
}

void SavingsAccount::withdraw(float amount){
	ba.withdraw(amount);
	withdrawNumber++;
}

void SavingsAccount::monthly_check(){
	int w = getWithdrawNumber();
	float b = ba.getBalance();

	if(w > 2){
		ba.withdraw(3);
		cout << "Amount of Withdraws Exceeds 2. $3 has been Charged from Your Account." << endl;
	}

	if(b < 100){
		ba.withdraw(10);
		cout << "Balance is Below $100. $10 has been Charged from Your Account." << endl;
	}
}

void SavingsAccount::deposit(float amount){
	ba.deposit(amount);
}

float SavingsAccount::getBalance(){
	ba.getBalance();
}

int SavingsAccount::getWithdrawNumber(){
	return withdrawNumber;
}

void SavingsAccount::setAccountNumber(long int a){
	ba.setAccountNumber(a);
}

void SavingsAccount::setName(string n){
	ba.setName(n);
}

void SavingsAccount::setBalance(float amount){
	ba.setBalance(amount);
}

void SavingsAccount::setWithdrawNumber(int w){
	withdrawNumber = w;
}

void SavingsAccount::prettyprint(){
	ba.prettyprint();
	cout << "Withdraw Number: " << withdrawNumber << endl;
	cout << endl;
}

void SavingsAccount::operator = (const SavingsAccount& sa){
	ba = sa.ba;
	withdrawNumber = sa.withdrawNumber;
}

bool SavingsAccount:: operator == (const SavingsAccount& sa){
	if(ba == sa.ba && withdrawNumber == sa.withdrawNumber) return true;

	else return false;
}

