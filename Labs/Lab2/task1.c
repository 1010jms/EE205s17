/* Lab 2 Task 1
 * Task: Display sizes of primitive functions
 *
 * Name: Jared Shimabukuro
 * Date: 17 January 2017
 */

#include <iostream>

int main(){
	std::cout << "Size of signed int: " << sizeof(signed int) << std::endl;
	std::cout << "Size of unsigned int: " << sizeof(unsigned int) << std::endl;
	std::cout << "Size of int*: " << sizeof(int*) << std::endl;
	std::cout << "Size of long double: " << sizeof(long double) << std::endl;
	std::cout << "Size of char[10]: " << sizeof(char[10]) << std::endl;
}
