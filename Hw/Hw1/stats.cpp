/* Project Assignment 1 Task 1
 * Objective: Create a nXn grid that will calculate the temperatures of the
 * inner squares of the grid.
 *
 * File Name: stats.cpp
 *
 * Team Name: North Shore Remembers
 * Team Members: Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 * Lab Section: 001
 *
 * Date Started: 1/31/17
 * Date Finished: 
 */

#include "stats.h"

int** MatrixGenerator(int n){
	try{
		if(n < 4) throw "error";
		int** matrix = new int*[n];
		for(int x=0; x < n; x++){
			matrix[x] = new int[n];
			for(int y=0; y <=n; y++){
				matrix[x][y] = 1;
			}
		}

		return matrix;
	}
	catch(const char* e){
		cout << "ERROR: Invalid Input." << endl;
	}
}

