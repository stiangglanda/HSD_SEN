#ifndef ANIMAL_H
#define ANIMAL_H
#include "Object.h"

//Abstrakte Basisklasse für 'Animal'
class Animal : public Object
{
public:
   //Zugriffsfunktionen
   size_t GetWeight() const;
   size_t GetId() const;
   
   //to do
   std::string ToString() const override;

   //pure virtual method: muss in abgeleiteten konkreten klassen implementiert werden
   // verhindert das Erzeugen eines Animal-Objektes -> Die Klasse ist abstrakt!
   virtual void GiveTongue() const = 0;

   //pure virtual method: muss in abgeleiteten konkreten klassen implementiert werden
   virtual Animal* Clone() const = 0;

protected:
   Animal(size_t const w);

private:
   //generiert eine fortlaufende Id
   static size_t msCounter;

   size_t mId;
   size_t mWeight;
};

#endif //ANIMAL_H
