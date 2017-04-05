/* main.cpp */
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <chrono>
#include <thread>
#include "queue-array.h"

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
        vector<string> tokens1 = tokensplit(line.c_str(), ' ');
        int q1a = atoi(tokens1.at(0).c_str());
        int q1b = atoi(tokens1.at(1).c_str());
        int q1p = atoi(tokens1.at(2).c_str());
        int q1e = atoi(tokens1.at(3).c_str());
        int Q1  = atoi(tokens1.at(4).c_str());

        getline(infile, line);
        vector<string> tokens2 = tokensplit(line.c_str(), ' ');
        int q2p = atoi(tokens2.at(0).c_str());
        int q2e = atoi(tokens2.at(1).c_str());
        int Q2  = atoi(tokens2.at(2).c_str());

        getline(infile, line);
        vector<string> tokens3 = tokensplit(line.c_str(), ' ');
        int q3p = atoi(tokens3.at(0).c_str());
        int q3e = atoi(tokens3.at(1).c_str());
        int Q3  = atoi(tokens3.at(2).c_str());

        infile.close();

	//assign time delay between packet delivery
	int lambda = rand() % q1b + q1a;	//random number between 1 and 3
	//assign time period of delivering packet from queue 1
	int mue = rand() % q1e + q1p;	//random number between 1 and 5
	
	cout << "Time delay between packet deliveries: " 
	     << lambda << " milliseconds" << endl;
	cout << "Time delay between Queue 1 Dequeues: "
	     << mue << " milliseconds" << endl;
	this_thread::sleep_for(chrono::seconds(3));

	//Initialize queues
	queue q1(Q1);
	queue q2(Q2);
	queue q3(Q3);

	//count and average the dequeued values
	int dqcount = 0;
	int dqsum = 0;
	float dqavg;


	//run until all three queues are full
	while(!q1.isFull() || !q2.isFull() || !q3.isFull()) {
		int val = rand() % 20 + 1;
		//assign movement of value from queue 1 to queue 2 or 3
		int direct = rand() % 3 + 2;

		//add values to queue 1 every lambda seconds
		this_thread::sleep_for(chrono::milliseconds(lambda));
		q1.enqueue(val, 1);
		q1.prettyprint(1);
		
		//take values from queue 1 every mue seconds 
		//to queue 2 or queue 3
		this_thread::sleep_for(chrono::milliseconds(mue));
		if(direct == 2) {
			int val2 = q1.dequeue(1);
			q2.enqueue(val2, 2);
			//q2.enqueue(q1.dequeue(1), 2);
			dqsum += val2;
			dqcount ++;
			cout << endl;
		}
		else if(direct == 3) {
			int val2 = q1.dequeue(1);
			q3.enqueue(val2, 3);
			//q3.enqueue(q1.dequeue(1), 3);
			dqsum += val2;
			dqcount ++;
			cout << endl;
		}

		q1.prettyprint(1);
		q2.prettyprint(2);
		q3.prettyprint(3);
		cout << endl;
	}

	dqavg = dqsum/dqcount;
	cout << "Average of dequeued values: " << dqavg << endl;	
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

