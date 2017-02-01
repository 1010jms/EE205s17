/* Lab 3 Task 3
 * Objective: Construct a binary full adder
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 *
 * Date Started: 1/31/17
 * Date Finished: 
 */

#include <iostream>
using namespace std;

int binarySize(int num);
int powerOf2(int n);


int main(){
	int num1 = 0;
	int num2 = 0;

	cout << "Insert First Large Number: ";
	cin >> num1;

	cout << "Insert Second Large Number: ";
	cin >> num2;

	int n1 = binarySize(num1);
	int n2 = binarySize(num2);

	int* binNum1 = new int(n1);
	int* binNum2 = new int(n2);

	for(int i = 0; i <= n1; i++){
		binNum1[i] = (num1 % 2);
		num1 = num1 / 2;
	}

	for(int j = 0; j <= n2; j++){
		binNum2[j] = (num2 % 2);
		num2 = num2 / 2;
	}
		
	int carry = 0;
        int k = 0;
	if(n1 >= n2){
                k = n1;
        }
        else{
                k = n2;
        }

        int* binSum = new int(k);

	int n = 0;
        for(int m = k; m >= 0; m--){
                binSum[n] = binNum1[m] + binNum2[m] + carry;
                if(binSum[n] == 2){
                       	binSum[n] = 0;
                       	carry = 1;
               	}
               	else if(binSum[n] == 3) {
                       	binSum[n] = 1;
                       	carry = 1;
               	}
               	else    carry = 0;

		n++;
        }

	int sum = 0;
	for(int p = 0; p <= k; p++){
		//cout << binSum[p];
		sum += binSum[p]*powerOf2(p);
	}

	cout << "Sum of Numbers: " << sum << endl; 
}

int binarySize(int num){
	int n = 0;
	while(num > 0){
		num = num / 2;
		n++;
	}
	return n;
}

int powerOf2(int n){
	int num = 1;
	for(int i = 0; i < n; i++){
		num *= 2;
	}

	return num;
}
