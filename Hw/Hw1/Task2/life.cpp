//A very simple C++ implementation of John Conway's Game of Life.
////This implementation uses several nested for loops as well as
//two-dimensional
////arrays to create a grid for the cells in the simulation to interact.
////The array that is displayed to the user is 50 x 100, but actual size
////of the array is 52 x 102.  The reason for this is to make the 
////calculations easier for the cells on the outermost "frame" of the grid.

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Copies one array to another.
void copy(int array1[52][102], int array2[52][102])
{
  for(int j = 0; j < 52; j++)
  {
        for(int i = 0; i < 102; i++)             
            array2[j][i] = array1[j][i]; 
    }
}

//The life function is the most important function in the program.
////It counts the number of cells surrounding the center cell, and 
////determines whether it lives, dies, or stays the same.
void life(int array[52][102], char choice)
{
	//Copies the main array to a temp array so changes can be entered
	//into a grid
	//without effecting the other cells and the calculations being
	//performed on them.
	 int temp[52][102];
  	 copy(array, temp);
    		 for(int j = 1; j < 51; j++)
     		 {
         		 for(int i = 1; i < 101; i++)             
        		 {    
            			 if(choice == 'm')
            			 {
					   //The Moore neighborhood
					   //checks all 8 cells
					   //surrounding the current
					   //cell in the array.
					int count = 0;
                			count = array[j-1][i] + 
                    			array[j-1][i-1] +
                    			array[j][i-1] +
                    			array[j+1][i-1] +
                    			array[j+1][i] +
                    			array[j+1][i+1] +
                    			array[j][i+1] +
                    			array[j-1][i+1];
                			//The cell dies.

					 if(count < 2 || count > 3)
                    				 temp[j][i] = 0;
                				 //The cell stays the same.
                			 
					 if(count == 2)
                    				temp[j][i] = array[j][i];
                				//The cell either stays alive, or is "born".
               
