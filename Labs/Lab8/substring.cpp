/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: substring.cpp
 * Objective: Test String Library
 *
 * Date Started: 2/28/17
 * Date Finished: 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> findSubString (string str, string substr) {
	vector<int> index;
	int count = 0;
	int placeholder = 0;

	for(int n = 0; n < str.length(); n++){
		int m = 0;
		if(str[n] == substr[m]) {
			placeholder = n;
			while(str[n] == substr[m] && m < substr.length()){
				n++;
				m++;
			}
			if(m == substr.length()){
				index.push_back(placeholder);
				count++;
			}
			m = 0;
			n = placeholder;
		}
	}

	return index;
}

int main() {
	string str;
	string substr;
	vector<int> index;

	cout << "Please Enter a String: ";
	cin >> str;
	cout << endl;

	cout << "Please Enter a SubString: ";
	cin >> substr;
	cout << endl;

	index = findSubString(str, substr);

	for(int i = 0; i < index.size(); i++){
		cout << index[i] << " ";
	}

	cout << endl << endl;

	string sentence = "This is a sentence.";
	cout << sentence << endl;

	sentence.replace(10, 8, "replacement");
	cout << sentence << endl;

	sentence.pop_back();
	sentence.append(" with an addition. q");
	cout << sentence << endl << endl;

	cout << "Removing q..." << endl;
	sentence.pop_back();

	cout << sentence << endl;
}

