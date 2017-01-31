/* Lab 3 Task 1
 * Objective: Create a function that assigns grades on a curve
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 *
 * Date Started: 1/24/17
 * Date Finished: 1/24/27
 */

#include <iostream>
#include <math.h>
using namespace std;

float mean(int* grades, int count);
float stdev(int* grades, float mean, int count);

int main(){
	int people;
	cout << "Amount of People in the Class: ";
	cin >> people;

	int* grades = new int(people);

	for(int i = 1; i <= people; i++){
		try {
			int grade;
			cout << "Insert Grade for Person " << i << ": ";
			cin >> grade; 
			if(grade > 100 || grade < 0) throw "error";
			

			grades[i-1] = grade;
		}
		catch(const char* e){
			cout << "ERROR: Invalid Grade" << endl;
			i--;
		}
	}

	float avg = mean(grades, people);
	float var = stdev(grades,avg, people); 
	
	cout << endl;
	cout << "Mean = " << avg << endl;
	cout << "Standard Deviation = " << var << endl;
	
	for(int j = 0; j < people; j++){
		float f = avg - ((3/2)*var);
		float d = avg - ((1/2)*var);
		float c = avg + ((1/2)*var);
		float b = avg + ((3/2)*var);

		if (grades[j] < f) cout << "Person " << (j+1) << "'s grade is F." << endl;
		else if(grades[j] >= f && grades[j] <= d) cout << "Person " << (j+1) << "'s grade is D." << endl; 
		else if(grades[j] >= d && grades[j] <= c) cout << "Person " << (j+1) << "'s grade is C." << endl;
		else if(grades[j] >= c && grades[j]<= b) cout << "Person " << (j+1) << "'s grade is B." << endl;
		else if(grades[j] >= b) cout << "Person " << (j+1) << "'s grade is A." << endl;
	}

	delete [] grades;
	return 0;
}

float mean(int* grades, int count){
	int sum = 0;
	for(int i = 0; i < count; i++){
		sum += grades[i];
	}

	return sum/count;
}

float stdev(int* grades, float mean, int count){
	int sum = 0;
	for(int i = 0; i < count; i++){
		sum += ((grades[i] - mean)*(grades[i] - mean));
	}

	return sqrt(sum/count);
} 
