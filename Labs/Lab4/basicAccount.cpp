/* Lab 4 Task 1
 * Objective: Create a .cpp file for basicAccount
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 1/31/17
 * Date Finished: 
 */

#include "basicAccount.h"

int main(){
	BasicAccount ba1;
	BasicAccount ba2;

	ba1.display();
	ba2.display();

	ba1.setBalance(400);
	ba2.setName("Alice");

	ba1.display();
	ba2.display();

	BasicAccount ba3(100325, "Bob", 4310);
	ba3.display();

	BasicAccount ba4(ba2);
	ba4.display();

	ba4.setBalance(ba3.getBalance());
	ba4.setAccountNumber(12345);
	ba4.display();

	ba3.withdraw(300);
	ba3.display();

	ba1.deposit(2000);
	ba1.display();
}
