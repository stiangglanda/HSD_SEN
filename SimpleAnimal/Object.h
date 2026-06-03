#ifndef OBJECT_H
#define OBJECT_H
#include <string>

//Basis aller Basisklassen
class Object
{
public:
   virtual ~Object() = default;

   //to do
   
protected:
   //Default-CTor: Benutzer kann kein Object erzeugen
   Object() = default;

};

#endif // OBJECT_H