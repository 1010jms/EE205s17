/* Homework Assignment 1 Task 2
 * Objective: Simulate John Conway's Game of Life
 * 
 * File Name: driver2.cpp
 *
 * Team Name: North Shore Remembers
 * Team Members: Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 * Lab Section: 001
 *
 * Date Started: 2/1/17
 * Date Finished: 2/2/17
 */

#include "life.h"
#include "prettyprint.h"

using namespace std;

int main() {
	int gen0[32][72];
	int todo[32][72];
	int backup[32][72];
	char again;
	char cont;
	bool comparison;
	string decoration;

	do {
		int j = 0;
		do {
			srand(time(NULL));
			//leaves surrounding part of matrix blank to
			//prevent interference with life function's
			//calculations
			for(int i = 1; i < 31; i++) {
				for(int j = 1; j < 71; j++) {
					gen0[i][j] = rand() % 2;
				}
			}
			if(j < 10)
				decoration = "#############";
			else if(j >= 10 && j < 100)
				decoration = "##############";
			else if(j >= 100 && j < 1000)
				decoration = "###############";
			else if(j >= 1000 && j < 10000)
				decoration = "################";
			else
				decoration = "#################";
			
			//prints the current generation
			cout << decoration << endl << "Generation " << j
			     << ":" << endl << decoration << endl << endl;
			//initializes the arrays by copying gen0
			//array to todo array
			if(j == 0)
				copy(gen0, todo);
			copy(todo, backup);
			printorganisms(todo);
			life(todo);
			j++;

			//pauses system for half a second to allow
			//screen to refresh
			system("sleep, .5");

			//once the array is large enough,
			//asks user if they want to continue the simulation
			if(j % 70 == 1 && j != 1) {
				cout << endl;
				do {
					cout << "Would you like to continue"
					     << " the simulation? "
					     << "'y'es or 'n'o: ";
					cin >> cont;
				} while(cont != 'y' && cont != 'n');
				if(cont == 'n')
					break;
			}
			
			//compares the current and backup generation
			comparison = compare(todo, backup);
			//if they are not the same, screen is cleared
			//and generation process restarts from the 
			//beginning
			if(comparison == false)
				system("clear");
			if(comparison == true)
				cout << endl;
		}while(comparison == false);
		do {
			cout << "Would you like to run another simulation? "
			     << "'y'es or 'n'o: ";
			cin >> again;
		}while(again != 'y' && again != 'n');
	}while(again == 'y');
}
