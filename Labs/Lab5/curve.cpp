/* Lab 3 Task 1
 * Objective: Create a cpp file for grade-curve function
 *
 * Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Lab Section: 001
 *
 * Date Started: 2/7/17
 * Date Finished: 
 */

#include "curve.h"

float mean(vector<int> grades, int count){
	int sum = 0;
	for(int i = 0; i < count; i++){
		sum += grades[i];
	}

	return sum/count;
}

float stdev(vector<int> grades, float mean, int count){
	int sum = 0;
	for(int i = 0; i < count; i++){
		sum += ((grades[i] - mean)*(grades[i] - mean));
	}

	return sqrt(sum/count);
} 
