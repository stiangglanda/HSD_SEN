#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
private:
	int age;		// Members
	int id;

public:
	// ctor
	Employee() : age{25}, id{1234} {
		std::cout << "Employee::Employee()" << '\n';
	}

	// another ctor, no initialization of age
	Employee(int a) : id{1234} {
		std::cout << "Employee::Employee(int)" << '\n';
		age = a;
	}

	// copy-ctor
	Employee(Employee const &e) {
		std::cout << "Employee::Employee(Employee const &)" << '\n';
		age = e.age;
		id = e.id;
	}

	// DTor
	~Employee() {
		std::cout << "Employee::~Employee()" << '\n';
	}

	// Member functions, getter & setter (=accessor methods)
	int  getAge() { return age; }
	void setAge (int const &val) { age = val; }
	int  getID() { return id; }
	void setID(int const &val) { id = val; }
};

#endif // EMPLOYEE_H

