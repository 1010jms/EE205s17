/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: driver.cpp
 * Objective: Create a Single and Double Linked List
 *
 * Date Started: 2/14/17
 * Date Finished: 
 */

#include "singlylinked.h"
#include "doublylinked.h"
#include <vector>
#include <string>
int main()
{
	SinglyLinkedList s;
	DoublyLinkedList d;

	DLink d1(0);
	DLink d2(1);
	DLink d3(2);
	DLink d4(3);

	SLink s1(9);
	SLink s2(8);
	SLink s3(7);
	SLink s4(6);



	cout << endl;
	cout << "*************************************" << endl;
	cout << "*********** Doubly Linked ***********" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	cout << "Appending Link Value " << d1.value << endl;
	d.append(&d1);

	cout << "Appending Link Value " << d2.value << endl;
	d.append(&d2);

	cout << "Appending Link Value " << d3.value << endl;
	d.append(&d3);

	cout << endl;
	d.print_all(d.getHead());
	cout << endl;

	cout << "Erasing Link Value " << d3.value << endl; 
	d.erase(&d3);

	cout << "Inserting Link Value " << d4.value << " Before Link Value " << d1.value << endl;
	d.insert(&d4, &d1);

	cout << endl;
	d.print_all(d.getHead());
	cout << endl;

	cout << "Adding Link Value " << d3.value << " After Link Value " << d2.value << endl;
	d.add(&d2, &d3);

	cout << endl;
	d.print_all(d.getHead());
	cout << endl;

	cout << "Searching for Link with Value 2" << endl;
	d.find(d.getHead(), 2);
	cout << endl;

	cout << "Searching for Link with value 5" << endl;
	d.find(d.getHead(), 5);
	cout << endl;

	cout << "Returning value of Link 2" << endl;
	d.advance(d.getHead(), 2);
	cout << endl;

	cout << "Returning value of Link 4" << endl;
	d.advance(d.getHead(), 4);
	cout << endl;

	cout << "Returning value of Link 5" << endl;
	d.advance(d.getHead(), 5);
	cout << endl;

	cout << "*************************************" << endl;
	cout << "*********** Singly Linked ***********" << endl;
	cout << "*************************************" << endl;
	cout << endl;

	cout << "Appending Link Value " << s1.value << endl;
	s.append(&s1);

	cout << "Appending Link Value " << s2.value << endl;
	s.append(&s2);

	cout << "Appending Link Value " << s3.value << endl;
	s.append(&s3);

	cout << endl;
	s.print_all(s.getHead());
	cout << endl;

	cout << "Erasing Link Value " << s2.value << endl;
	s.erase(&s2);

	cout << "Inserting Link Value " << s4.value << " Before Link Value " << s3.value << endl;
	s.insert(&s4, &s3);

	cout << endl;
	s.print_all(s.getHead());
	cout << endl;

	cout << "Adding Link Value " << s2.value << " After Link Value " << s3.value << endl;
	s.add(&s3, &s2);

	cout << endl;
	s.print_all(s.getHead());
	cout << endl;

	cout << "Searching for Link with Value 7" << endl;
	s.find(s.getHead(), 7);
	cout << endl;

	cout << "Searching for Link with Value 5" << endl;
	s.find(s.getHead(), 5);
	cout << endl;

	cout << "Returning Value of Link 2" << endl;
	s.advance(s.getHead(), 2);
	cout << endl;

	cout << "Returning Value of Link 4" << endl;
	SLink* sa = s.advance(s.getHead(), 4);
	if(sa == NULL) cout << "Link 4 Value Not Found" << endl;
	else cout << "Link 4 Value = " << sa->value << endl;
	cout << endl;

	cout << "Returning Value of Link 5" << endl;
	sa = s.advance(s.getHead(), 5);
	if(sa == NULL) cout << "Link 5 Value Not Found" << endl;
        else cout << "Link 5 Value = " << sa->value << endl;
	cout << endl;

	s.print_all(s.getHead());
    return 0;
}

