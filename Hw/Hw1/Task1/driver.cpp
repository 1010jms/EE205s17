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
	int tempL, tempR, tempT, tempB;

	cout << "Insert Dimension of Matrix n >= 4: ";
	cin >> n;

	cout << "Insert Left Border Temperature: ";
	cin >> tempL;

	cout << "Insert Right Border Temperature: ";
	cin >> tempR;

	cout << "Insert Top Border Temperature: ";
	cin >> tempT;

	cout << "Insert Bottom Border Temperature: ";
	cin >> tempB;

	int** matrix = MatrixGenerator(n);

	int** borderedMatrix = SetBorder(matrix,n,tempL, tempR, tempB, tempT);
	
	printMatrix(borderedMatrix, n);
	
	int** avgMatrix = AverageTemp(borderedMatrix,n);
	printMatrix(avgMatrix, n);

	int corner;
	if(tempT == tempL) corner = tempT - 2;
	else corner = ((tempT + tempL)/2) - 1;
	while(avgMatrix[1][1] < corner){
		avgMatrix = AverageTemp(avgMatrix,n);
		printMatrix(avgMatrix, n);
	}

	return 0;
}
