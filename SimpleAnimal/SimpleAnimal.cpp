#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
//#include <vld.h>
#include "Cat.h"
#include "Dog.h"
#include "Zoo.h"

using namespace std;

int main()
{
   Cat Minka{ 2 };
   Dog Rolfi{ 7 };
   
   Cat* pCat = &Minka;
   Dog* pDog = &Rolfi;
   Animal* pAnimal = nullptr;
   pAnimal = &Minka;
   
   //es werden die beiden Zeiger verglichen
   if (pAnimal == pCat)
   {
      cout << "equal" << endl;
   }

   //ein Zeiger auf Animal kann alle Animals (Cat,Dog,...) annehmen
   pAnimal = &Rolfi;
  
   //Anwendung der Klasse Zoo
   try
   {
     //to do
      Zoo z;
      z.Add(new Dog{35});
      z.Add(new Cat{11});
      z.Add(new Dog{Rolfi});
      for_each(z.cbegin(), z.cend(), [](auto ani){ ani->GiveTongue(); });

      cout << z.ToString() << endl;

      Zoo z2 = z;
      cout << z2.ToString() << endl;

      Zoo z3;
      z3 = z2;
      cout << z3.ToString() << endl;

      z3 = z3;
   }
   catch (invalid_argument const& ex)
   {
      cerr << ex.what() << endl;
      return 1;
   }
   catch (bad_alloc const& ex)
   {
      cerr << ex.what() << endl;
      return 1;
   }
   catch (...)
   {
      cerr << "unhandled exception" << endl;
      return 1;
   }

   return 0;
}