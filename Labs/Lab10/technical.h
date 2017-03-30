/* Name: Jared Shimabukuro
 * UH ID: 2257-2949
 * Section: 001
 *
 * File Name: technical.h
 * Objective: Salary for technical employee
 *
 * Date Started: 3/21/17
 * Date Finished: 3/21/17
 */

//#include "employee.h"

class Technical : public Employee {
public:
	Technical() {}

	float getSalary(){
		return salary;
	}
	int getBonusAvailability() {
		return bonusAvailable;
	}

	float getBonus() {
		return bonus;
	}

	void setSalary(float s) {
		salary = s;
	}

	void setBonusAvailability(int ba) {
		bonusAvailable = ba;
	}

	void setBonus(float b) {
		bonus = b;
	}

	float monthlySalary() {
		if(bonusAvailable == 1) return (salary + bonus);
		else 	return salary;
	}

private:
	float salary;
	float bonus;
	int bonusAvailable;
};
