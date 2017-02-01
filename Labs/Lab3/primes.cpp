/* Lab 2 Task 2
 * Objective: Find All Primes Between 2 and a Number N That is Inputted by User
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 *
 * Date Started: 1/24/17
 * Date Finished: 
 */

#include <iostream>
using namespace std;

int main(){
	int n = 0;
	int count = 0;
	
	cout << "Please insert a number greater than 2: ";
	cin >> n;

	int* prime = new int(n);
	
	try{
		if(n < 2) throw "error";
		
		prime[count] = 2;
		count++;

		int i = 0;
		for(int num = 3; num <= n; num++){
			if(num % prime[i] != 0){
				prime[count] = num;
				count++;
				i = 0;
			}
			else{
				i++;
				if(i >= 2) i = 0;
				//break;
			}
			//i = 0;
		}

		cout << "Number of Prime Numbers >= 2: " << count << endl;
		for(int j = 0; j < count; j++){
			cout << prime[j] << " is a prime number." << endl;
		}
	}
	catch(const char* e){
		cout << "ERROR: Input Must be Greater than 2." << endl;
	}

	//delete [] prime;
	return 0;	
}
