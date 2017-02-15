/* Lab 3 Task 1
 * Objective: Create a function that assigns grades from a txt on a curve
 * 
 * File Name: readfromfile.cpp
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 2/7/17
 * Date Finished: 2/7/17 
 */

#include <fstream>
#include <string>
#include <vector>
#include <string.h>

#include "curve.h"

vector<string> tokensplit(const char *str, char c);

int main(){

	string filename = "onestudent.txt";
	ifstream infile(filename.c_str());

	if(!infile.is_open()){
		cout << "error in opening input file" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	char cline[1029];
	int people = 0;
	vector<int> grades;

	while(getline(infile, line)){
		cout << "Line: " << line << endl << endl;

		strncpy(cline, line.c_str(), line.length());
		cline[sizeof(cline - 1)] = 0;
		
		vector<string> tokens = tokensplit(line.c_str(), ' ');
		for(vector<string>::const_iterator i = tokens.begin(); i != tokens.end(); i++){	
		//	cout << *i << ' ';
			grades.push_back(atoi(tokens.at(people).c_str()));
			cout << grades[people] << endl << endl;
			people++;
		}
	}

	infile.close();
	
	/*int people;
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
	 }*/

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

		if (grades[j] < f) cout << "Grade " << (j+1) <<" (" << grades[j] << ") is an F." << endl;
		else if(grades[j] >= f && grades[j] <= d) cout << "Grade " << (j+1) << " (" << grades[j] << ") is a D." << endl; 
		else if(grades[j] >= d && grades[j] <= c) cout << "Grade " << (j+1) << " (" << grades[j] << ") is a C." << endl;
		else if(grades[j] >= c && grades[j]<= b) cout << "Grade " << (j+1) << " (" << grades[j] << ") is a B." << endl;
		else if(grades[j] >= b) cout << "Grade " << (j+1) << " (" << grades[j] << ") is an A." << endl;
	}

	//delete [] grades;
	return 0;
} 

vector<string> tokensplit(const char *str, char c = ' ' )
{
	
	vector<string> result;

	do
	{
		const char *begin = str;

		while (*str != c && *str)
			str++;

		result.push_back(string(begin, str));
	} while (0 != *str++);

	return result;
}

