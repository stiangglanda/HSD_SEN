#ifndef CAT_H
#define CAT_H
#include "Animal.h"

class Cat : public Animal    //Konkrete Klasse 'Cat'
{
public:
   //CTor mit Default-Parameter
   Cat(size_t const w);

   //to do
   std::string ToString() const override;

   void GiveTongue() const override;

   Animal* Clone() const override;
};
#endif //CAT_H


