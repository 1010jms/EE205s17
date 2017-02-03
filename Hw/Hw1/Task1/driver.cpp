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

//Main driver file for Task 1
int main() {
	int n;
	int tempL, tempR, tempT, tempB;

	//Initialize dimensions of matrix
	cout << "Insert Dimension of Matrix n >= 4: ";
	cin >> n;

	//Initialize the temperature of each edge of the matrix
	cout << "Insert Left Border Temperature: ";
	cin >> tempL;

	cout << "Insert Right Border Temperature: ";
	cin >> tempR;

	cout << "Insert Top Border Temperature: ";
	cin >> tempT;

	cout << "Insert Bottom Border Temperature: ";
	cin >> tempB;

	//Generate a nXn matrix
	int** matrix = MatrixGenerator(n);

	//Set edges of the matrix to the given temperature values
	int** borderedMatrix = SetBorder(matrix,n,tempL, tempR, tempB, tempT);
	//print the initial matrix
	printMatrix(borderedMatrix, n);
	
	//Find the first average temperatures of the inner nodes of the
	//matrix
	int** avgMatrix = AverageTemp(borderedMatrix,n);
	printMatrix(avgMatrix, n);

	//Continue finding the average temperatures of the inner nodes of
	//the matrix until the top-left inner node is equal to the top
	//edge's temperature - 2 if the top and left edge temperatures are
	//equal or is equal to the average of the top and left temperatures
	//- 1 if the top and left temperatures are different.
	int corner;
	if(tempT == tempL) corner = tempT - 2;
	else corner = ((tempT + tempL)/2) - 1;
	while(avgMatrix[1][1] < corner){
		avgMatrix = AverageTemp(avgMatrix,n);
		printMatrix(avgMatrix, n);
	}

	return 0;
}
