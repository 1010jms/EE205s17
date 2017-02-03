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
			for(int y=0; y < n; y++){
				matrix[x][y] = 10;
			}
		}

		return matrix;
	}
	catch(const char* e){
		cout << "ERROR: Invalid Input." << endl;
	}
}

int** SetBorder(int **matrix, int n, int tempL, int tempR, int tempT, int tempB){
	for(int x = 0; x < n; x++){
		if(x == 0){
			for(int y = 0; y < n; y++){
				matrix[x][y] = tempB;
			}
		}
		else if(x == n-1){
			for(int y = 0; y < n; y++){
				matrix[x][y] = tempT;
			}
		}
		else{
			matrix[x][0] = tempL;
			matrix[x][n-1] = tempR;
			for(int y = 1; y < n-1; y++){
				if(tempL < 10) matrix[x][y] = 1;
				else if(tempL >= 10 && tempL < 100) matrix[x][y] = 10;
				else if(tempL > 100) matrix[x][y] = 100;
			}	
		}
	}
	
	return matrix;
}

int** AverageTemp(int ** matrix, int n){
	float sum;
	for(int x = 1; x < n-1; x++){
		for(int y = 1; y < n-1; y++){ 
			sum = matrix[x-1][y] + matrix[x][y-1] + matrix[x+1][y] + matrix[x][y+1];
			matrix[x][y] = sum/4;
		}
	}

	return matrix;
}
	
