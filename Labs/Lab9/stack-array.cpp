/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: stack-array.cpp
 * Objective: Implement a stack using an array
 *
 * Date Started: 7 March 2017
 * Date Finished: 14 March 2017 
 */

#include "stack.h"

Stack::Stack(){ }

int Stack::push_array(int val, int array[], int size){
	int count = 0;

	for(int i = 0; i < size; i++){
		count++;
	}
	array[count] = val;
	return *array;
}

int Stack::pop_array(int array[], int size){
	int count = 0;

	for(int i = 0; i < size; i++){
		count++;
	}
	array[count] = 0;
	count--;
	return *array;
}

void Stack::prettyprint_array(int array[], int size){

	for(int i = 0; i < size; i++){
		cout << array[i] << " " << endl;
	}
	cout << endl;
} 
