/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * File Name: savingsAccount.h
 * Objective: Create a Savings Account program that inherits
 * from Basic Account
 *
 * Date Started: 3/21/17
 * Date Finished: 3/21/17
 */

#include "basicAccount.h"

class SavingsAccount : public BasicAccount {
public:
	SavingsAccount();
	SavingsAccount(long int a, string n, float b, int w);
	SavingsAccount(SavingsAccount& sa);
	void monthly_check();
	int getWithdrawNumber();
	void setWithdrawNumber(int w);

private:
	int withdrawNumber;
};
