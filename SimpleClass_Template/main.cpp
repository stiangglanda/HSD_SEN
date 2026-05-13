#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <vld.h>
#include "Simple.h"
#include "Fraction.h"
using namespace std;

int main()
{
   try
   {
      //Objekte am Stack anlegen
      Simple<int> sObj;

      sObj.SetFirstVal(50);
      sObj.SetSecondVal(100);
      sObj.Print();

      cout << sObj.CalcSum() << endl;
      cout << sObj.CalcDiff() << endl;

      //Initialisierung mit Parameter
      Simple<int> sObj2{ 123, 123 };
      sObj2.Print();

      //Copy-CTor
      Simple<int> sObj3{ sObj };   //SObj3 ist eine Kopie von SObj
      Simple<int> sObj4 = sObj2;  //SObj4 ist eine Kopie von SObj2
      sObj4 = sObj3;  //Zuweisung -> kein Aufruf des Copy-CTor's

      //Objekt dynamisch anlegen
      Simple<int>* pSObj = new Simple<int>{ 200, 300 };
      pSObj->Print();

      //dynamisches Objekt freigeben
      delete pSObj;
      pSObj = 0;

      //Datencontainer
      Simple<int>* sVect[10];
      for (int i = 0; i < 10; i++)
      {
         sVect[i] = new Simple<int>{ i, i + 10 };
      }

      //indizierter Zugriff
      for (auto const elem : sVect)
      {
         elem->Print();
      }

      //Objekte freigeben
      for (auto elem : sVect)
      {
         delete elem;
         elem = nullptr;
      }

      //to do
      //...
   }
   catch (std::bad_alloc const& ex)
   {
      std::cerr << "memory allocation: " << ex.what() << std::endl;
      return 1;
   }
   catch (std::exception const& ex)
   {
      std::cerr << ex.what() << std::endl;
      return 1;
   }
   catch (...)
   {
      std::cerr << "unhandled exception..." << std::endl;
      return 1;
   }

}