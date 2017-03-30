/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: management.h
 * Objective: Salary for technical employee
 *
 * Date Started: 3/21/17
 * Date Finished: 3/21/17
 */

//#include "employee.h"

class Management : public Employee {
public:
	Management() {}

	float getSalary(){
		return salary;
	}

	float getBonus() {
		return bonus;
	}

	void setSalary(float s) {
		salary = s;
	}

	void setBonus(float b) {
		bonus = b;
	}

	float monthlySalary() {
		return (salary + bonus);
	}

private:
	float salary;
	float bonus;
};
