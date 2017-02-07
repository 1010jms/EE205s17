/* Lab 4 Task 1
 * Objective: Create a bank file to test basicAccount and
 * savingsAccount.
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 2/7/17
 * Date Finished: 
 */

#include "savingsAccount.h"

int main(){
	BasicAccount alice;
	BasicAccount bob;
	BasicAccount charlie;

	long int num = rand();

	for(int basicCount = 0; basicCount < 3; basicCount++){
		if(basicCount == 0){
			alice.setAccountNumber(num);
			alice.setName("Alice");
			alice.setBalance(3000);
		}
		else if(basicCount == 1){
			bob.setAccountNumber(num);
			bob.setName("Bob");
			bob.setBalance(2000);
		}
		else if(basicCount == 2){
			charlie.setAccountNumber(num);
			charlie.setName("Charlie");
			charlie.setBalance(4000);
		}
		num++;
	}

	alice.prettyprint();
	bob.prettyprint();
	charlie.prettyprint();

	SavingsAccount xing;
	SavingsAccount yi;
	SavingsAccount zed;

	num = rand();

	xing.setAccountNumber(num);
	xing.setName("Xing");
	xing.setBalance(5000);
	xing.setWithdrawNumber(0);

	xing.prettyprint();
}
