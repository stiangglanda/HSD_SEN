#include <iostream>
#include "Circle.h"
using namespace std;

Circle::Circle() : GraphicObject{"CIRCLE"} {
}

Circle::~Circle() {
    cout << "Dtor of 'Circle' called: ";
}

void Circle::SetRadius(size_t const rad) {
    mRadius = rad;
}

void Circle::Draw() const {
    cout << "+++ draw circle: " << hex << this << dec << endl;
}
