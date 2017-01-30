/* Lab 2 Task 3
 * Task: Finding the numeric limit of the system
 *
 * Name: Jared Shimabukuro
 * Date: 17 January 2017
 */

#include <iostream>
#include <climits>

int main(){
	int n;
	n = 2;
	for (int i = 1; i < 20; i++) {
		std::cout << n << '\n'; 
		n *= 10;
	}

	std::cout << "\n\n";
	n = INT_MAX - 3; 
	std::cout << "max int is " << INT_MAX << '\n';

	for (int i = 1; i < 10; i++) {
		std::cout << n << '\n';
		n ++;
	}
}
