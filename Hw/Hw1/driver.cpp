/* Project Assignment 1 Task 1
 * Objective: Create a nXn matrix that will calculate the temperatures of
 * the inner squares of the matrix.
 *
 * File Name: driver.cpp
 *
 * Team Name: North Shore Remembers
 * Team Members: Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 * Lab Section: 001
 *
 * Date Started: 2/1/17
 * Date Finished: 
 */

#include "stats.h"
#include "prettyprint.h"

int main() {
	int n;

	cout << "Insert Dimension of Matrix n >= 4: ";
	cin >> n;

	int** matrix = MatrixGenerator(n);
	
	printMatrix(matrix, n);
	
	return 0;
}
