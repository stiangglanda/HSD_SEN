#ifndef DOG_H
#define DOG_H
#include "Animal.h"

//Konkrete Klasse 'Dog'
class Dog : public Animal
{
public:
   //CTor mit Default-Parameter
   Dog(size_t const w);

   //to do
   std::string ToString() const override;

   void GiveTongue() const override;

   Animal* Clone() const override;
};
#endif //DOG_H
