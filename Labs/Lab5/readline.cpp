/* Lab 3 Task 2
 * Objective: Create a function that assigns grades from a txt file on a curve
 * 
 * File Name: readline.cpp
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 2/7/17
 * Date Finished: 2/14/17
 */

#include <fstream>
#include <string>
#include <vector>
#include <string.h>

#include "curve.h"

vector<string> tokensplit(const char *str, char c);

int main(){

	string filename = "multiplestudents.txt";
	ifstream infile(filename.c_str());

	if(!infile.is_open()){
		cout << "error in opening input file" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	char cline[1029];
	int g = 0;
	int people = 0;
	int gradecount[100];
	vector<int> grades;
	vector<vector<int>> students;
 
	while(getline(infile, line)){
		cout << "Line " << (people+1) << ": " << line << endl << endl;

		strncpy(cline, line.c_str(), line.length());
		cline[sizeof(cline - 1)] = 0;
		
		vector<string> tokens = tokensplit(line.c_str(), ' ');

		gradecount[people] = 0;
		for(vector<string>::const_iterator i = tokens.begin(); i != tokens.end(); i++){	
			grades.push_back(atoi(tokens.at(g).c_str()));
			cout << grades[g] << endl << endl;
			g++;
			gradecount[people]++;
		}
			
		students.push_back(grades);
		grades.clear();
		g = 0;
		tokens.clear();
		people++;
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

	for(int k = 0; k < people; k++){
		float avg = mean(students[k], people);
		float var = stdev(students[k],avg, people); 	

		cout << "Student " << (k+1) <<"'s Grades:" << endl;
		cout << "Mean = " << avg << endl;
		cout << "Standard Deviation = " << var << endl;
	
		vector<int> gdisp = students[k];

		for(int j = 0; j < gradecount[k]; j++){
			float f = avg - ((3/2)*var);
			float d = avg - ((1/2)*var);
			float c = avg + ((1/2)*var);
			float b = avg + ((3/2)*var);

			if (gdisp[j] < f) cout << "Grade " << (j+1) <<" (" << gdisp[j] << ") is an F." << endl;
			else if(gdisp[j] >= f && gdisp[j] <= d) cout << "Grade " << (j+1) << " (" << gdisp[j] << ") is a D." << endl; 
			else if(gdisp[j] >= d && gdisp[j] <= c) cout << "Grade " << (j+1) << " (" << gdisp[j] << ") is a C." << endl;
			else if(gdisp[j] >= c && gdisp[j]<= b) cout << "Grade " << (j+1) << " (" << gdisp[j] << ") is a B." << endl;
			else if(gdisp[j] >= b) cout << "Grade " << (j+1) << " (" << gdisp[j] << ") is an A." << endl;
		}

		cout << endl;
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

