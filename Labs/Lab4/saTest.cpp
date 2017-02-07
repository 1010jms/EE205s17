/*Lab 4 Task 1
 * Objective: Create a test file for savingsAccount
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 2/7/17
 * Date Finished: 2/7/17 
 */

#include "savingsAccount.h"

int main(){
	SavingsAccount sa1;
	sa1.prettyprint();

	sa1.setAccountNumber(1234567);
	sa1.setName("Shaq");
	sa1.setBalance(300);
	sa1.setWithdrawNumber(2);
	sa1.prettyprint();

	sa1.withdraw(210);
	sa1.monthly_check();
	sa1.prettyprint();

	SavingsAccount sa2(9876543, "Kobe", 1500, 1);
	sa2.prettyprint();

	SavingsAccount sa3(sa2);
	sa3.deposit(200);
	sa3.prettyprint();

	sa2.setBalance(2000);
	sa2.setWithdrawNumber(0);
	sa2.prettyprint();

	SavingsAccount sa4 = sa1;
	sa4.prettyprint();
	if(sa4 == sa1) cout << "It Works!!!" << endl;
	if(sa4 == sa3) cout << "Nevermind..." << endl;
}
