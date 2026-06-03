#include <iostream>
#include <sstream>
#include "Dog.h"
using namespace std;

Dog::Dog(size_t const w) : Animal{ w } //Konstruktor der Basisklasse aufrufen
{}

std::string Dog::ToString() const {
    ostringstream ost;
    ost << "ID: " << GetId() << "I'm a dog and " << Animal::ToString(); //Aufruf von ToString aus der Basisklasse
    return ost.str();
}

void Dog::GiveTongue() const {
    cout << "wauwau" << endl;
}

Animal* Dog::Clone() const {
    return new Dog(*this);
}
