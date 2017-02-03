/* Homework Assignment 1 Tasks 1 and 2
 * Objective (task 1): Create an nXn grid that calculates the 
 * temperatures of the inner squares of a grid
 * Objective (task 2): Print the grid that simulates Conway's Game of Life
 *
 * File Name: prettyprint.cpp
 *
 * Team Name: North Shore Remembers
 * Team Members: Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 * Lab Section: 001
 *
 * Date Started: 2/1/17
 * Date Finished: 2/2/17
 */

#include "prettyprint.h"

void printMatrix(int** matrix, int n) {
	for(int x = 0; x < n; x++) {
		for(int y = 0; y < n; y++) {
			cout << matrix[x][y] << "   ";
		}
		cout << endl;
	}
}

//prints an array of alive or dead cells based on outputs of compare
//function
void printorganisms(int array[32][72]) {
	for(int i = 0; i < 31; i++) {
		for(int j = 0; j < 71; j++) {
			//alive cell/born cell
			if(array[i][j] == 1)
				cout << 'o';
			//dead cell
			else
				cout << " ";
		}
		cout << endl;
	}
}
