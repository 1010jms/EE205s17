/* Lab 4 Task 1
 * Objective: Test the functions for basicAccount
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 2/6/17
 * Date Finished: 2/6/17
 */

#include "basicAccount.h"

int main(){
	BasicAccount ba1;
	BasicAccount ba2;

	ba1.prettyprint();
	ba2.prettyprint();

	ba1.setBalance(400);
	ba2.setName("Alice");
	ba2.setAccountNumber(8080808);

	ba1.prettyprint();
	ba2.prettyprint();

	BasicAccount ba3(100325, "Bob", 4310);
	ba3.prettyprint();

	BasicAccount ba4(ba2);
	ba4.prettyprint();

	ba4.setBalance(ba3.getBalance());
	ba4.setAccountNumber(12345);
	ba4.prettyprint();

	ba3.withdraw(300);
	ba3.prettyprint();

	ba1.deposit(2000);
	ba1.prettyprint();

	BasicAccount ba5 = ba3;
	ba3.prettyprint();
	ba5.prettyprint();

	if(ba5 == ba3)	cout << "It Works!!!" << endl;

	if(ba5 == ba2) cout << "Nevermind..." << endl;
}
