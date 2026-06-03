#include <iostream>
#include <sstream>
#include "Cat.h"
using namespace std;

Cat::Cat(size_t const w) : Animal{ w }  //Konstruktor der Basisklasse aufrufen
{}

std::string Cat::ToString() const {
    ostringstream ost;
    ost << "ID: " << GetId() << "I'm a cat and " << Animal::ToString(); //Aufruf von ToString aus der Basisklasse
    return ost.str();
}

void Cat::GiveTongue() const {
    cout << "miaoooow" << endl;
}

Animal * Cat::Clone() const {
    return new Cat(*this);
}
