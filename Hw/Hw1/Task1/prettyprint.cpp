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

//prints an array of alive or dead cells based on outputs of compare function
void printorganisms(int array[32][72]){
        for(int i = 0; i < 31; i++){
                for(int j = 1; j < 71; j++){
                        //alive cell/born cell
                        if(array[i][j] == 1)
                                cout << 'o';
                         //dead cell
                        else
                                cout << ' ';
                }
                cout << endl;
        }
}

