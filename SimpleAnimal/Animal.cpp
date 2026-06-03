#include <sstream>
#include "Animal.h"
using namespace std;

//initialisiert die statische Variable: muss auﬂerhalb der Klasse erfolgen 
//(in der Implementierungsdatei cpp)
size_t Animal::msCounter = 0; // !!

size_t Animal::GetWeight() const
{
   return mWeight;
}

size_t Animal::GetId() const
{
   return mId;
}

std::string Animal::ToString() const {
   ostringstream ost;
   ost << "my weight is " << mWeight << endl;
   return ost.str();
}


Animal::Animal(size_t const w) : mWeight{ w }, mId{ msCounter++ }
{}
