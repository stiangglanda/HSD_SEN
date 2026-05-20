#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <vector>
#include <fstream>
#include <iterator>
#include <cassert>
#include "Fraction.h"

using namespace std;

//Arithmetische Operation
//Genersicher Funktor Plus -> STL-like

//Ist ident mit std::plus<T> aus der STL
template<typename T>
class Plus         
{
public:
   T operator()(T a, T b) const {
      return a + b;
   }
   //to do
};


//Funktor Equal_to: hier als struct definiert, da keine Daten gespeichert werden
template<typename T>
struct Equal_to 
{
   //to do
   bool operator()(T const& x, T const& y) const {
      return x == y;
   }
};


//Funktor zur Ermittlung und Speicherung einer Summe aller geraden Elemente
template<typename T>
class SumEven {
public:
   SumEven(T const& startVal = T{}) : mSum{startVal}
   {}

   void operator()(T const& val) {
      if (val % 2 == 0) {
         mSum = mSum + val;
      }
   }

   T GetSum() const { return mSum; }
private:
   T mSum;
};


//STL-Funktor der das größere zweier Elemente in einem Container sammelt
template<typename T>
class CollectGreater
{
   //to do
};


//Generischer Algorithmus der gleichzeitig zwei Sequenzen durchläuft und eine
//binäre Funktion auf zwei Elemente anwendet

//to do


int main()
{
   try
   {
      //AAA -> Almost Always Auto: Best Practice fuer die Deklaration
      auto dInt = deque<int>{ 5,4,3,2,1,6,7 };
      auto vInt = vector<int>{ 1,2,3,4,5 };

      //TO DO
      //nur zur Demo, wie ein Funktor funktioniert
      Plus<int> ownPlus;
      cout << boolalpha << (ownPlus(1,2) == std::plus<int>{}(1,2) )<< endl;
      cout  << (Plus<string>{}("a", "bc") == std::plus<string>{}("a","b") )<< endl;

      Equal_to<int> cmpInt;
      cout << cmpInt(1,3) << endl;
      cout << Equal_to<Fraction>{}(Fraction{1,2},Fraction{1,3}) << endl;

      //Funktor mit STL-Algo verwenden
      cout << "sum: " << accumulate(vInt.cbegin(), vInt.cend(), int{}, Plus<int>{}) << endl;
      cout << "sum: " << accumulate(vInt.cbegin(), vInt.cend(), int{}) << endl;

      //Equal_to in transform mit 2 Quellen und ostream als Ziel
      transform(vInt.cbegin(), vInt.cend(), dInt.cbegin(), ostream_iterator<int>(cout<<endl, " "), Equal_to<int>{});

      //Anwendung SumEven
      SumEven<int> sum1{4711};
      for_each(vInt.cbegin(), vInt.cend(), sum1);
      cout << endl << sum1.GetSum() << endl;

      //besser
      sum1 = for_each(vInt.cbegin(), vInt.cend(), SumEven<int>{});
      cout << endl << sum1.GetSum() << endl;

      //noch kompakter
      cout << "sum: " << for_each(vInt.cbegin(), vInt.cend(), SumEven<int>{4711}).GetSum() << endl;
   }
   catch (bad_alloc const& exc)
   {
      cerr << "bad memory allocation: " << exc.what() << endl;
      return 1;
   }
   catch (runtime_error const& exc)
   {
      cerr << "runtime error exception: " << exc.what() << endl;
      return 1;
   }
   catch (exception const& exc)
   {
      cerr << "standard exception: " << exc.what() << endl;
      return 1;
   }
   catch (...)
   {
      cerr << "unhandled exception...debug it" << endl;
      return 1;
   }
   
}