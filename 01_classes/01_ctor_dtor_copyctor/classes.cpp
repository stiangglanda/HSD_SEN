#include "employee.h"

Employee modify(Employee e) {
	e.setAge(e.getAge()+1);
	return e;
}

int main() {
	Employee e1;
	Employee e2{30};
	Employee *pe3;

	pe3 = new Employee;
	e1.setAge(26);
	e1.setID(4321);

	e1 = modify(e1);

	e1 = e2;

	delete pe3;
	return 0;
}
