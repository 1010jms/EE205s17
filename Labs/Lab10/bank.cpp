/* Lab 4 Task 1
 * Objective: Create a bank file to test basicAccount and
 * savingsAccount.
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

	for(int savingsCount = 0; savingsCount < 3; savingsCount++){
		if(savingsCount == 0){
			xing.setAccountNumber(num);
			xing.setName("Xing");
			xing.setBalance(5000);
			xing.setWithdrawNumber(0);
		}

		else if(savingsCount == 1){
			yi.setAccountNumber(num);
			yi.setName("Yi");
			yi.setBalance(4000);
			yi.setWithdrawNumber(1);
		}

		else if(savingsCount == 2){
			zed.setAccountNumber(num);
			zed.setName("Zed");
			zed.setBalance(6000);
			zed.setWithdrawNumber(2);
		}

		num++;
	}


	xing.prettyprint();
	yi.prettyprint();
	zed.prettyprint();

	while(1){
		char command;
		char n;
		cout << "Commands: (W)ithdraw, (D)eposit, (P)rint, (Q)uit" << endl << "Please select a command:";
		cin >> command;
		if(command == 'w' || command == 'W'){
			cout << "Accounts: (A)lice, (B)ob, (C)harlie, (X)ing, (Y)i, (Z)ed" << endl << "Please select an account: ";
			cin >> n;
			
			float amount;
			cout << "Please enter the amount of money to withdraw: ";
			cin >> amount;
		
			switch(n){
				case 'a':
				case 'A': alice.withdraw(amount);
					  break;
				case 'b':
				case 'B': bob.withdraw(amount);
					  break;
				case 'c':
				case 'C': charlie.withdraw(amount);
					  break;
				case 'x':
				case 'X': xing.withdraw(amount);
					  xing.monthly_check();
					  break;
				case 'y':
				case 'Y': yi.withdraw(amount);
					  yi.monthly_check();
					  break;
				case 'z':
				case 'Z': zed.withdraw(amount);
					  zed.monthly_check();
					  break;
				default: cout << "Invalid Account" << endl;
			}
			cout << "Withdrew " << amount << " from account." << endl;
			cout << endl;
		}

               else if(command == 'd' || command == 'D'){
                        cout << "Accounts: (A)lice, (B)ob, (C)harlie, (X)ing, (Y)i, (Z)ed" << endl << "Please select an account: ";
                        cin >> n;

                        float amount;
                        cout << "Please enter the amount of money to deposit: ";
                        cin >> amount;

                        switch(n){
                                case 'a':
                                case 'A': alice.deposit(amount);
                                          break;
                                case 'b':
                                case 'B': bob.deposit(amount);
                                          break;
                                case 'c':
                                case 'C': charlie.deposit(amount);
                                          break;
                                case 'x':
                                case 'X': xing.deposit(amount);
                                          break;
                                case 'y':
                                case 'Y': yi.deposit(amount);
                                          break;
                                case 'z':
                                case 'Z': zed.deposit(amount);
                                          break;
                                default: cout << "Invalid Account" << endl;
                        }
			cout << "Deposited " << amount << " into account." << endl;
			cout << endl;
                }

		else if(command == 'p' || command == 'P'){
                        cout << "Accounts: (A)lice, (B)ob, (C)harlie, (X)ing, (Y)i, (Z)ed" << endl << "Please select an account: ";
                        cin >> n;

                        switch(n){
                                case 'a':
                                case 'A': alice.prettyprint();
                                          break;
                                case 'b':
                                case 'B': bob.prettyprint();
                                          break;
                                case 'c':
                                case 'C': charlie.prettyprint();
                                          break;
                                case 'x':
                                case 'X': xing.prettyprint();
                                          break;
                                case 'y':
                                case 'Y': yi.prettyprint();
                                          break;
                                case 'z':
                                case 'Z': zed.prettyprint();
                                          break;
                                default: cout << "Invalid Account" << endl;
                        }
                }

		else if(command == 'q' || command == 'Q') return 0;
	}
}
