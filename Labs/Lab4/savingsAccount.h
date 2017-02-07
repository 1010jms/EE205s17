/* Lab 4 Task 1
 * Objective: Create a header file for savingsAccount
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 1/31/17
 * Date Finished: 2/7/17 
 */

#include "basicAccount.h"

class SavingsAccount {
public:
	SavingsAccount();
	SavingsAccount(long int a, string n, float b, int w);
	SavingsAccount(SavingsAccount& sa);
	void withdraw(float amount);
	void monthly_check();
	void deposit(float amount);
	float getBalance();
	int getWithdrawNumber();
	void setAccountNumber(long int a);
	void setName(string n);
	void setBalance(float amount);
	void setWithdrawNumber(int w);
	void prettyprint();

	void operator = (const SavingsAccount& sa);
	bool operator == (const SavingsAccount& sa);
private:
	BasicAccount ba;
	int withdrawNumber;
};
