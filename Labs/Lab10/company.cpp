/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: company.cpp
 *
 * Date Started: 3/21/17
 * Date Finished:
 */
#include <iostream>
#include "employee.h"
#include "technical.h"
#include "management.h"
using namespace std;

int main(){
	float salary = 0;
	float bonus = 0;
	char employee;

	Technical te;
	Management me;

	while(employee != 'q') {
		cout << "Types of Employees:" << endl;
		cout << "\tt = Technical" << endl;
		cout << "\tm = Management" << endl;
		cout << "\ta = Administrative" << endl;
		cout << "\tf = Factory" << endl;
		cout << "\ts = Sales" << endl << endl;

		cout <<"Please Enter Type of Employee (enter 'q' to quit): ";
		cin >> employee;

		if(employee == 't') {
			cout << "Please Enter Value of Salary: ";
			cin >> salary;
		
			te.setSalary(salary);

			char ba;
			cout <<"Will the employee receive a bonus?(y)es or(n)o: ";
			cin >> ba;
			if(ba == 'y') {
				te.setBonusAvailability(1);
				cout << "Enter Value of Bonus:";
				cin >> bonus;
				te.setBonus(bonus);
			}
			else{ 
				te.setBonusAvailability(0);
			}

			cout <<"Employee's Monthly Salary is " << te.monthlySalary() << endl << endl;
		}

		else if(employee == 'm') {
			 cout << "Please Enter Value of Salary: ";
                        cin >> salary;

                        me.setSalary(salary);

                        cout << "Enter Value of Bonus:";
                        cin >> bonus;
                        me.setBonus(bonus);

                        cout <<"Employee's Monthly Salary is " << me.monthlySalary() << endl << endl;
		}

	}
}
