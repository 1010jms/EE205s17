/* Lab 4 Task 1
 * Objective: Create a header file for savingsAccount
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 1/31/17
 * Date Finished: 
 */

#include "basicAccount.h"

class SavingsAccount {
public:
	SavingsAccount(){
		ba = BasicAccount();
		withdrawNumber = 0;
	}

	SavingsAccount(long int a, string n, float b, int w) {
		ba = BasicAccount(a,n,b);
		withdrawNumber = w;
	}

	SavingsAccount(SavingsAccount& sa){}

	void withdraw(float amount){
		ba.withdraw(amount);
		withdrawNumber++;
	
		if(withdrawNumber > 2){
			ba.withdraw(3);
			cout << "Amount of Withdraws Exceeds 2. $3 has Been Charged from Your Account." << endl;
		}

		if(ba.getBalance() < 100){
			ba.withdraw(10);
			cout << "Balance is Below $100. $10 has Been Charged from Your Account." << endl;
		}
	}
	
	void deposit(float amount){
		ba.deposit(amount);
	}
private:
	BasicAccount ba;
	int withdrawNumber;
};
