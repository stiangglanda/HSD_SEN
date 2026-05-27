#include <iostream>
#include "GraphicObject.h"
using namespace std;

GraphicObject::GraphicObject(std::string const &text) : mText{text} {
    cout << " it's a " << mText << endl;
}

GraphicObject::~GraphicObject() {
    cout << mText << " is destroyed -> ";
}

void GraphicObject::MoveTo(int const xpos, int const ypos) {
    mXPos = xpos;
    mYPos = ypos;
}

void GraphicObject::RotateTo(double const orient) {
    mOrientation = orient;
}

void GraphicObject::Draw() const {
    cout << "Don't know how to draw a graphic object:" << hex << this << dec << endl;
}
