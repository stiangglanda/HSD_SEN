#include <iostream>
#include <typeinfo>
#include <cassert>
#include "demangle.h"

#include "employee.h"

int main() {
	Employee e1, e2;
	
	e1.setAge(20);
	e1.getAge();

	e2.setAge(20);
	e2.getAge();

	return 0;
}
