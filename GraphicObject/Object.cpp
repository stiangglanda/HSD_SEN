#include <iostream>
#include "Object.h"
using namespace std;

Object::~Object() {
    cout << "DTor of 'Object called'" << endl;
}

Object::Object() {
    cout << "CTor of 'Object' called ->";
}
