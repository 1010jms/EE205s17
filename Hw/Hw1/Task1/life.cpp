/* Homework Assignment 1 Task 2
 * Objective: Simulate John Conway's Game of Life
 *
 * File Name: life.cpp
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

void copy(int array1[32][72], int array2[32][72]) { //32, 72
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 72; j++) {
			array2[i][j] = array1[i][j];
		}
	}
	
}

//counts number of cells surrounding a cell, this count
//determines whether that cell lives, dies, or stays in place
void life(int array[32][72]) {
	//copies the main array to a temp array
	int temp[32][72];
	copy(array, temp);

	for(int i = 1; i < 31; i++) {
		for(int j = 1; j < 71; j++) {
			int count = 0;
			count = array[i-1][j] +
				array[i+1][j] +
				array[i][j-1] +
				array[i][j+1] +
				array[i+1][j+1] +
				array[i-1][j-1] +
				array[i+1][j-1] +
				array[i-1][j+1];
			//cell dies from isolation or overcrowding
			if(count < 2 || count > 3)
				temp[i][j] = 0;
			//cell remains the same with two neighbors
			if(count == 2)
				temp[i][j] = array[i][j];
			//cell stays alive or is born
			if(count == 3)
				temp[i][j] = 1;
		}
	}
	//copies completed array back to main
	copy(temp, array);
}

//verifies an array by checking its similarity with its backup
bool compare(int array1[32][72], int array2[32][72]) {
	int count = 0;
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 72; j++) {
			if(array1[i][j] == array2[i][j])
				count++;
		}
	}

	//ends simulation if the simulation stabilizes
	//before the 100th generation
	if(count == 32*72)
		return true;
	else 
		return false;
}
