/* Project Assignment 1 Task 1
 * Objective: Create a nXn grid that will calculate the temperatures of the
 * inner squares of the grid.
 *
 * File Name: prettyprint.cpp
 *
 * Team Name: North Shore Remembers
 * Team Members: Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 * Lab Section: 001
 *
 * Date Started: 2/1/17
 * Date Finished: 
 */

#include "prettyprint.h"

void printMatrix(int** matrix, int n){
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			cout << matrix[x][y] << " ";
		}
		cout << endl;
	}

	cout << endl;
}
 
