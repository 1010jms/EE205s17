/* Homework Assignment 1 Task 2
 * Objective: Simulate John Conway's Game of Life
 *
 * File Name: life.h
 *
 * Team Name: North Shore Remembers
 * Team Members: Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 * Lab Section: 001
 *
 * Date Started: 2/1/17
 * Date Finished: 2/2/17
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copy(int array1[32][72], int array2[32][72]);

//determines the state of each cell(alive, dead)
void life(int array[32][72]);

//verifies the array, ends the simulation if it stablizes eary
bool compare(int array1[32][72], int array2[32][72]);
