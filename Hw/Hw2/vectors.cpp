/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: vectors.cpp
 * Objective: Create a vector with the values 10, 20, 30, and 40
 *
 * Date Started: 2/14/17
 * Date Finished: 2/14/17
 */

#include <iostream>
#include <vector>

using namespace std;

void display(const vector<int> &v);
void displayWithIterator(vector<int> &v);

int main() {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	display(v);
	return 0;
}

void display(const vector<int> &v){
	int i;
	for (i=0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void displayWithIterator(vector<int> &v){
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
