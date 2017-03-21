/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: main.cpp
 * Objective: Test the stack and queue implementations
 *
 * Date Started: 7 March 2017
 * Date Finished: 
 */

#include "stack.h"
#include <vector>

int main(){
	Stack a;
	char command;
	int array[N];
	SinglyLinkedList sll;
	vector<struct SLink> vs;
	SLink s(0);
	int size = 0;

        cout << "Commands: " << endl;
	cout << "\t p = (p)ush, " <<endl;
	cout << "\t o = p(o)p, " <<endl;
	cout << "\t r = p(r)ettyprint, " << endl;
	cout << "\t q = (q)uit" << endl << endl;
	cout << "Please Insert the Desired Command: ";
	cin >> command;

	while(command != 'q'){
		if(command == 'p'){
			int num;
			cout << "Please insert a number to push: ";
			cin >> num;
			*array = a.push_array(num, array, size);
			
			s.value = num;
			vs.push_back(s);
			sll = a.push_link(&vs[size], sll);
			
			size++;
			cout << endl;
		}

		else if(command == 'o'){
			*array = a.pop_array(array, size);
			sll = a.pop_link(sll);
			size--;
			cout << endl;
		}

		else if(command == 'r'){
			a.prettyprint_array(array, size);
			cout << endl;
			a.prettyprint_link(sll.getHead());
		}

        	cout << "Commands: (p)ush, p(o)p, p(r)ettyprint, (q)uit" << endl;
        	cout << "Please Insert the Desired Command: ";
        	cin >> command;
	}

	return 0;
}
