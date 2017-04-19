/* Name: Jared Shimabukuro
 * UH ID: 2257-2929
 * Section: 001
 *
 * File Name: ackerman.cpp
 *
 * Date Started: 4 April 2017
 * Date Finished: 4 April 2017
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int ackermann(int m, int n){
/*	ostringstream mVal;
	ostringstream nVal;
	mVal << m;
	nVal << n;

	string msg = "Ackermann function called with m = " + mVal.str() + " and n = " + nVal.str() + ".\n";

	cout << msg; */

	if(m == 0)	return (n + 1);
	else if(m > 0 && n == 0) ackermann((m-1), 1);
	else if(m > 0 && n > 0)  ackermann((m-1), 
					  ackermann(m, n-1));

}

int main() {
	int m = 0;
	int n = 0;
	char c;

	while(c != 'n'){
		cout << "Please Input Value for m: ";
		cin >> m;

		cout << "Please Input Value for n: ";
		cin >> n;
		cout << endl;	

		int A = ackermann(m, n);
		cout << "Ackermann Value: " << A << endl << endl;

		cout << "Continue? (y = yes, n = no): ";
		cin >> c;
	}
	
	return 0;
}

