/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: dictionary.cpp
 * Objective: Create a dictionary function that either adds integers in ascending order or deletes an element in the list.
 *
 * Date Started: 2/23/17
 * Date Finished: 
 */

#include "singlylinked.h"

int main(){
	int n;
	int taskNum;
	SinglyLinkedList s;

	while(1){
		cout << "Please Enter an Integer Value: ";
		cin >> n;
		SLink sl(n);

		cout << endl << "Please Enter the Number Corresponding to the Desired Task:" << endl;

		cout << endl << "(1) = Inserting the Entered Integer into the Dictionary" << endl;
	
		cout << endl << "(2) = Deleting the Entered Integer from the Dictionary" << endl;

		cout << endl << "(3) = Printing the Current Contents from the Dictionary" << endl;

		cout << endl << "(4) = Exiting the Program" << endl;

		cout << endl << "Task Number: ";
		cin >> taskNum;
		
		if(taskNum == 1){
			if(s.getHead() == NULL) {
				s.append(&sl);
				cout << "Inserted " << n << " into the dictionary." << endl;
			}
			else {
				SLink* temp(s.getHead());
				int count = 0;
				while (temp != NULL){
					if(temp->value > n) {
						s.insert(&sl, temp);
						cout << "Inserted " << n << " into the dictionary." << endl;
					}
					temp = temp->succ;
					count++;
				}

				if(temp == NULL){ 
					s.append(&sl);
					cout << "Inserted " << n << " into the dictionary." << endl;
				}
			}
		}

		if(taskNum == 3) {
			cout << "Dictionary Values: " << endl;
			s.print_all(s.getHead());
			cout << endl;
		}

		if(taskNum == 4) return 0;
	}
}
