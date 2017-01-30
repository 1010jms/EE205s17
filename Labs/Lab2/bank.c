/* Lab 2 Task 4
 * Task: Create a struct that represents a simple bank account, a struct that represents a simple savings account, a deposit function, and a withdraw
 * function(s).
 *
 * Name: Jared Shimabukuro
 * Date Started: 17 January 2017
 * Date Completed: 23 January 2017
 */

#include <iostream>
#include <string.h>

struct bankAccount{     //Simple bank account struct containing account number, name, and balance.
       long int accountNumber;
       char name [35];
       float balance;
};


struct savingsAccount {		//Savings account struct containing bank account struct and number of withdrawals.
	struct bankAccount Account[7];
	int withdrawNumber;
};

float deposit(struct bankAccount *account);			//deposit function for bank and savings account
float withdraw(struct bankAccount *account);			//withdraw function for bank account
float savingsWithdraw(struct savingsAccount *account, int accNum);	//withdraw function for savings account

int main(){
	struct bankAccount Account[3]; 		//initialize bankAccount Account
	struct savingsAccount Savings[3]; 	//initialize savingsAccount Savings
	
	int randAccNum = rand(); 		//develop random number for bank account number

	//Test simple bank account struct
	for(int basicCount = 0; basicCount <= 2; basicCount++){
		//Create Random Account Number
		Account[basicCount].accountNumber = randAccNum;
		
		//Create account info for "Alice"
		if(basicCount == 0){
			strcpy(Account[basicCount].name, "Alice");
			Account[basicCount].balance = 1000.01;
		}

		//Create account info for "Bob"
		else if(basicCount == 1){
			strcpy(Account[basicCount].name,"Bob");
			Account[basicCount].balance = 296.38;
		}

		//Create account info for "Charlie"
		else if(basicCount == 2){
			strcpy(Account[basicCount].name, "Charlie");
			Account[basicCount].balance = 3423.27;
		}
		
		//Print out account number, name, and balance for each account.
        	std::cout << "Account Number: " << Account[basicCount].accountNumber << std::endl;
        	std::cout << "Name: " << Account[basicCount].name << std::endl;
        	std::cout << "Balance: " << Account[basicCount].balance << std::endl;
	        std::cout << std::endl;

		//increment random account number by 1.
		randAccNum++;
	}

	int basicCount = 3;
	//Test savings bank account struct
	randAccNum = rand();
	for(int savingsCount = 0; savingsCount <= 2; savingsCount++){
		//Create random account number
		Savings[savingsCount].Account[basicCount].accountNumber = randAccNum;
		
		//Create savings account info for "Xing"
		if(savingsCount == 0){
			strcpy(Savings[savingsCount].Account[basicCount].name, "Xing");
			Savings[savingsCount].Account[basicCount].balance = 863.26;
			Savings[savingsCount].withdrawNumber = 0;
		}

		//Create savings account info for "Yu"
		else if(savingsCount == 1){
			strcpy(Savings[savingsCount].Account[basicCount].name, "Yu");
			Savings[savingsCount].Account[basicCount].balance = 4963.20;
			Savings[savingsCount].withdrawNumber = 2;
		}

		//Create savings account info for "ZiggyPop"
		else if(savingsCount == 2){
			strcpy(Savings[savingsCount].Account[basicCount].name, "ZiggyPop");
			Savings[savingsCount].Account[basicCount].balance = 463.79;
			Savings[savingsCount].withdrawNumber = 1;
		}

		//Print out savings account number, name, balance, and number of withdrawals for each account.
		std::cout << "Savings Account Number: " << Savings[savingsCount].Account[basicCount].accountNumber << std::endl;
		std::cout << "Name: " << Savings[savingsCount].Account[basicCount].name << std::endl;
		std::cout << "Balance: " << Savings[savingsCount].Account[basicCount].balance << std::endl;
		std::cout << "Amount of Withdraws: " << Savings[savingsCount].withdrawNumber << std::endl;
		std::cout << std::endl;

		//Increment random account number and basic account counter by 1
		randAccNum++;
		basicCount++;
	}

	//Run until user requests to quit the program.
	while(1){
		char bankFunction;
		char accountName [35];

		//Set bank function (i.e. deposit, withdraw, or quit)
		std::cout << "Would you like to deposit or withdraw from a bank account?" << std::endl;
		std::cout << "'d' = deposit; 'w' = withdraw; 'q' = quit: ";
		std::cin >> bankFunction;
		std::cout << std::endl;

		//Deposit Function
		if(bankFunction == 'd' || bankFunction == 'D'){
			//Enter account name
			std::cout << "Please enter the name of the person who's account you are depositing into." << std::endl;
			std::cout << "(Current Available Bank Accounts: 'Alice', 'Bob', 'Charlie')" << std:: endl;
			std::cout << "(Current Available Savings Accounts: 'Xing', 'Yu', 'ZiggyPop')" << std::endl;
			std::cin >> accountName;
			std::cout << std::endl;

			//Compare name input to "Alice", "Bob", "Charlie", "Xing", "Yu", "ZiggyPop"
			int alice = strcmp("Alice", accountName);
			int bob = strcmp("Bob", accountName);
			int charlie = strcmp("Charlie", accountName);
			int xing = strcmp("Xing", accountName);
			int yu = strcmp("Yu", accountName);
			int ziggypop = strcmp("ZiggyPop", accountName);

			//Perform deposit for Alice's account
			if(alice == 0){
				float depo = deposit(&Account[0]);
				std::cout << std:: endl << "New Account Balance: " << depo << std::endl << std::endl;
			}

			//Perform deposit for Bob's account
			else if(bob == 0){
				float depo = deposit(&Account[1]);
                                std::cout << std:: endl << "New Account Balance: " << depo << std::endl << std::endl;
                        }

			//Perform deposit for Charlie's account
			else if(charlie == 0){
				float depo = deposit(&Account[2]);
                                std::cout << std:: endl << "New Account Balance: " << depo << std::endl << std::endl;
                        }

			//Perform deposit for Xing's account
			else if(xing == 0){
				float depo = deposit(&Savings[0].Account[3]);
                                std::cout << std:: endl << "New Account Balance: " << depo << std::endl << std::endl;
                        }

			//Perform deposit for Yu's account
			else if(yu == 0){
				float depo = deposit(&Savings[1].Account[4]);
                                std::cout << std::endl << "New Account Balance: " << depo << std::endl << std::endl;
                        }

			//Perform deposit for ZiggyPop's account
			else if(ziggypop == 0){
				float depo = deposit(&Savings[2].Account[5]);
                                std::cout << std::endl << "New Account Balance: " << depo << std::endl << std::endl;
                        }
			
			//Print error if input does not match any of the names
			else std::cout << "ERROR: Invalid Account Name" << std::endl << std::endl;
		}

		//Withdraw Function	
		else if(bankFunction == 'w' || bankFunction == 'W'){
			//Enter account name
			std::cout << "Please enter the name of the person who's account you are withdrawing from." << std::endl;
                        std::cout << "(Current Available Bank Accounts: 'Alice', 'Bob', 'Charlie')" << std:: endl;
                        std::cout << "(Current Available Savings Accounts: 'Xing', 'Yu', 'ZiggyPop')" << std::endl;
                        std::cin >> accountName;
			std::cout << std::endl;

			//Compare name input to "Alice", "Bob", "Charlie", "Xing", "Yu", "ZiggyPop"
			int alice = strcmp("Alice", accountName);
                        int bob = strcmp("Bob", accountName);
                        int charlie = strcmp("Charlie", accountName);
                        int xing = strcmp("Xing", accountName);
                        int yu = strcmp("Yu", accountName);
                        int ziggypop = strcmp("ZiggyPop", accountName);

			//Perform withdraw on Alice's account
                        if(alice == 0){
                                float wd = withdraw(&Account[0]);
                                std::cout << std:: endl << "New Account Balance: " << wd << std::endl << std::endl;
                        }

			//Perform withdraw on Bob's account
                        else if(bob == 0){
                                float wd = withdraw(&Account[1]);
                                std::cout << std:: endl << "New Account Balance: " << wd << std::endl << std::endl;
                        }

			//Perform withdraw on Charlie's account
                        else if(charlie == 0){
                                float wd = withdraw(&Account[2]);
                                std::cout << std:: endl << "New Account Balance: " << wd << std::endl << std::endl;
                        }

			//Perform savingsWithdraw on Xing's account
                        else if(xing == 0){
                                float swd = savingsWithdraw(&Savings[0], 3);
                                std::cout << std:: endl << "New Account Balance: " << swd << std::endl << std::endl;
                        }

			//Perform savingsWithdraw on Yu's account
                        else if(yu == 0){
                                float swd = savingsWithdraw(&Savings[1], 4);
                                std::cout << std::endl << "New Account Balance: " << swd << std::endl << std::endl;
                        }

			//Perform savingsWithdraw on ZiggyPop's account
                        else if(ziggypop == 0){
                                float swd = savingsWithdraw(&Savings[2], 5);
                                std::cout << std::endl << "New Account Balance: " << swd << std::endl << std::endl;
                        }

			//Print error if input does not match any of the names
                        else std::cout << "ERROR: Invalid Account Name" << std::endl << std::endl;

		}

		//Quit Function
		else if(bankFunction == 'q' || bankFunction == 'Q')	return 0;

		//Print error if input is not 'd', 'w', or 'q'
		else std::cout << "ERROR: Invalid Input" << std::endl << std::endl;
	}
}

//Deposit function for bank and savings account
float deposit(struct bankAccount *account){
	float money = 0;
	
	std::cout << "Please enter the amount of money you wish to deposit: ";
	std::cin >> money;
	account->balance +=money;
	
	return account->balance;
}


//Withdraw function for bank account
float withdraw(struct bankAccount *account){
	float money = 0;

        std::cout << "Please enter the amount of money you wish to withdraw: ";
        std::cin >> money;
        account->balance -=money;

        return account->balance;
}

//Withdraw function for savings account
float savingsWithdraw(struct savingsAccount *account, int accNum){
	float money = 0;

        std::cout << "Please enter the amount of money you wish to withdraw: ";
        std::cin >> money;
        account->Account[accNum].balance -=money;
	account->withdrawNumber++;

	//Subtract $10 if account balance < $100
	if(account->Account[accNum].balance < 100){
		std::cout << "Balance is less than $100. $10 has been subtracted from your account." << std::endl;
		account->Account[accNum].balance -= 10;
        }

	//Subtract $3 if number of withdraws > 2
	if(account->withdrawNumber > 2){
		std::cout << "Amount of withdraws this month exceeds 2. $3 has been subtracted from your account." << std::endl;
		account->Account[accNum].balance -= 3;
	}
	
	return account->Account[accNum].balance;
 
}
