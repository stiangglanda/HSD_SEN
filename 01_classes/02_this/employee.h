#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
	int age;
public:
	void setAge(int const &val) {
		std::cout << "set: " << dem(typeid(this).name()) << " = " << this << '\n';
		// set: Employee* = 0x...
		age = val;
	}

	int getAge() const {
		std::cout << "get: " << dem(typeid(this).name()) << " = " << this << '\n';
		// get: Employee const* = 0x...
		return age;
	}
};

#endif // EMPLOYEE_H

