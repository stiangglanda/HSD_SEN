#include "Object.h"
#include <sstream>
#include <iostream>
#include "Object.h"

using namespace std;

std::string Object::ToString() const {
    ostringstream ost;
    ost << "object of class 'Object': " << hex << this << dec << endl;
    return ost.str();
}
