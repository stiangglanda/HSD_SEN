#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() : GraphicObject{"RECTANGLE"} { // CTor der Basisklasse explizit aufrufen mit Parameter
}

Rectangle::~Rectangle() {
    cout << "Dtor of 'Rectangle' called: ";
}

void Rectangle::Draw() const {
    cout << "+++ draw Rectangle: " << hex << this << dec << endl;
}