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

//Matrix Generator Function
int** MatrixGenerator(int n){
	try{
		//If the dimension value is < 4, return error output
		if(n < 4) throw "error";

		//Create an nXn matrix with each node's value initially set
		//to 10
		int** matrix = new int*[n];
		for(int x=0; x < n; x++){
			matrix[x] = new int[n];
			for(int y=0; y < n; y++){
				matrix[x][y] = 10;
			}
		}

		//return nXn matrix
		return matrix;
	}
	catch(const char* e){
		//Print error message if n < 4
		cout << "ERROR: Invalid Input." << endl;
	}
}

//Set Border Function
int** SetBorder(int **matrix, int n, int tempL, int tempR, int tempT, int tempB){
	for(int x = 0; x < n; x++){
		//Set temperature value of bottom edge
		if(x == 0){
			for(int y = 0; y < n; y++){
				matrix[x][y] = tempB;
			}
		}
		
		//Set temperature value of top edge
		else if(x == n-1){
			for(int y = 0; y < n; y++){
				matrix[x][y] = tempT;
			}
		}
		else{
			//Set temperature value of left edge
			matrix[x][0] = tempL;
	
			//Set temperature value of right edge
			matrix[x][n-1] = tempR;

			//Fill inner nodes of matrix with either 1's, 10's
			//or 100's depending on the value of the left edge
			//temperature
			for(int y = 1; y < n-1; y++){
				if(tempL < 10) matrix[x][y] = 1;
				else if(tempL >= 10 && tempL < 100) matrix[x][y] = 10;
				else if(tempL > 100) matrix[x][y] = 100;
			}	
		}
	}
	
	//return nXn matrix with new edge values
	return matrix;
}

//Calculating Average Temperature of Inner Nodes
int** AverageTemp(int ** matrix, int n){
	float sum;
	//Find the sum of the nodes surrounding the
	//automatically-designated node.
	for(int x = 1; x < n-1; x++){
		for(int y = 1; y < n-1; y++){ 
			sum = matrix[x-1][y] + matrix[x][y-1] + matrix[x+1][y] + matrix[x][y+1];
			//Find the average of the surrounding nodes and set
			//that value to the designated node.
			matrix[x][y] = sum/4;
		}
	}

	//Return nXn matrix with averaged inner nodes
	return matrix;
}
	
