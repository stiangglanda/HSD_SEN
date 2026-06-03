#ifndef ZOO_H
#define ZOO_H
#include <vector>
#include "Animal.h"

//Klasse 'Zoo' zur Speicherung von allen 'Animal'-Objekten
class Zoo : public Object
{ 
public:

   ~Zoo(); // Gibt alle Animals Frei

   //to do
   void Add(Animal const* ani);

   std::string ToString() const override;

   //Zugriffsfunktionalitaet
   using TCAniItor = std::vector<Animal const*>::const_iterator;
   TCAniItor cbegin() const;
   TCAniItor cend() const;

private:
   //to do
   std::vector<Animal const*> mAnimals;
};



#endif //ZOO_H
