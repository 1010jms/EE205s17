#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

/* Config.txt:
 *
 * The first two values on the first line represent the time interval for 
 * packets that are entering queue 1.
 *
 * The next two values on the first line represent the time interval for
 * packets that are being processed/leaving queue 1. They also represent the
 * time interval for packets that are entering either queue 2 or queue 3.
 *
 * The last value on the first line represents the max capacity of queue 1.
 *
 * The first two values on the second line represent the time interval for
 * packets that are being processed/leaving queue 2.
 *
 * The last value on the second line represents the max capacity of queue 2.
 *
 * The first two values on the third line represent the time interval for 
 * packets that are being processed/leaving queue 3.
 *
 * The last value on the third line represents the max capacity of queue 3.
 */

vector<string> tokensplit(const char *str, char c);

int main() {
	string filename = "config.txt";
	ifstream infile(filename.c_str());

	if(!infile.is_open()){
		cout << "error in opening input file" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	char cline[1029];
	
	getline(infile, line);
	cout << "Line: " << line << endl;
		
	vector<string> tokens1 = tokensplit(line.c_str(), ' ');

	int q1a = atoi(tokens1.at(0).c_str());
	cout << "q1a = " << q1a << endl;
	int q1b = atoi(tokens1.at(1).c_str());
	cout << "q1b = " << q1b << endl;
	int q1p = atoi(tokens1.at(2).c_str());
	cout << "q1p = " << q1p << endl;
	int q1e = atoi(tokens1.at(3).c_str());
	cout << "q1e = " << q1e << endl;
	int Q1  = atoi(tokens1.at(4).c_str());
	cout << "Q1 = " << Q1 << endl << endl;

	getline(infile, line);
	cout << "Line: " << line << endl;

	vector<string> tokens2 = tokensplit(line.c_str(), ' ');

	int q2p = atoi(tokens2.at(0).c_str());
	cout << "q2p = " << q2p << endl;
	int q2e = atoi(tokens2.at(1).c_str());
	cout << "q2e = " << q2e << endl;
	int Q2  = atoi(tokens2.at(2).c_str());
	cout << "Q2 = " << Q2 << endl << endl;

	getline(infile, line);
	cout << "Line: " << line << endl;

	vector<string> tokens3 = tokensplit(line.c_str(), ' ');

	int q3p = atoi(tokens3.at(0).c_str());
	cout << "q3p = " << q3p << endl;
	int q3e = atoi(tokens3.at(1).c_str());
	cout << "q3e = " << q3e << endl;
	int Q3  = atoi(tokens3.at(2).c_str());
	cout << "Q3 = " << Q3 << endl << endl;

	infile.close();
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

