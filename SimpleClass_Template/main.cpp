#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
//#include <vld.h>
#include <cassert>
#include <iterator>

#include "Simple.h"
#include "Fraction.h"
using namespace std;

static ostream& operator<<(ostream& ost, Simple<Fraction> const& sF) {
   assert(ost.good());
   return ost << "First: " << sF.GetFirstVal() << " Second: " << sF.GetSecondVal() << endl;
}

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
      Simple<double> sdObj;
      sdObj.SetFirstVal(47.11);
      sdObj.SetSecondVal(47.11);
      sdObj.Print();
      cout << sdObj.CalcSum() << endl;
      cout << sdObj.CalcDiff() << endl;

      Simple<char> scObj{};
      scObj.SetFirstVal('a');
      scObj.SetSecondVal('x');
      scObj.Print();
      cout << scObj.CalcSum() << endl;
      cout << scObj.CalcDiff() << endl;

      Simple<string> strObj;
      strObj.SetFirstVal("Hr.Aigner");
      strObj.SetSecondVal("hello");
      strObj.Print();
      cout << strObj.CalcSum() << endl;
      //cout << strObj.CalcDiff() << endl; -> -Op wird von string nicht unterstuetzt

      Simple<Fraction> simFrac1{Fraction{ 1, 2 }, Fraction{ 1, 2 }};
      Simple<Fraction> simFrac2{{ 1, 4 }, { 1, 5 }};
      Simple<Fraction> simFrac3{ simFrac1.CalcSum(), simFrac2.CalcSum() };

      cout << simFrac1 << endl;

      simFrac1.SetFirstVal({1,3});
      simFrac1.SetSecondVal({1,4});
      simFrac1.Print();

      cout << simFrac1.CalcSum() << endl;
      //cout << simFrac1.CalcDiff() << endl; -> -Op wird von Fraction nicht unterstuetzt

      vector<Simple<Fraction>> vecSim{simFrac1, simFrac2, simFrac3};
      cout << "vector with Simple objects:" << endl;
      copy(vecSim.cbegin(), vecSim.cend(), ostream_iterator<Simple<Fraction>>(cout));

      cout << "ascending sorted vector by first val:" << endl;
      sort(vecSim.begin(), vecSim.end(),
         [](auto const& lhs, auto const& rhs) {
            return lhs.GetFirstVal() < rhs.GetFirstVal();
         });

      for_each(vecSim.cbegin(), vecSim.cend(),[](auto const& s) { cout << s; });

      cout << "extract all first values:" << endl;
      vector<Fraction> firstVals;
      transform(vecSim.cbegin(), vecSim.cend(), back_inserter(firstVals),
         [](auto const& s) { return s.GetFirstVal() * Fraction{ 2, 1 }; });

      copy(firstVals.cbegin(), firstVals.cend(), ostream_iterator<Fraction>(cout));

      cout << "remove all second elements < 1/3:" << endl;
      vecSim.erase(remove_if(vecSim.begin(), vecSim.end(),
                           [](auto const& s) { return s.GetSecondVal() < Fraction{1,3}; }),
                   vecSim.end());

      for_each(vecSim.cbegin(), vecSim.cend(),[](auto const& s) { cout << s; });
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