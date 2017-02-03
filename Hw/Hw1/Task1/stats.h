/* Project Assignment 1 Task 1
 * Objective: Create a nXn grid that will calculate the temperatures of the inner squares of the grid.
 *
 * File Name: stats.h
 * 
 * Team Name: North Shore Remembers
 * Team Members: Jaymark Ganibi, Jared Shimabukuro, Brandon Wong
 * Lab Section: 001
 *
 * Date Started: 1/31/17
 * Date Finished:
 */

#include <iostream>
using namespace std;

int** MatrixGenerator(int n);
int** SetBorder(int** matrix, int n, int tempL, int tempR, int tempT, int tempB);
int** AverageTemp(int** matrix, int n);
