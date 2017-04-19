/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: tree.h
 *
 * Date Started: 4 April 2017
 * Date Finished:
 */

class Tree {
public:
	Tree() { }
	int insert(int num);
	int find(int num);
	void print();

private:
	int value;
	int* left;
	int* right;
};

