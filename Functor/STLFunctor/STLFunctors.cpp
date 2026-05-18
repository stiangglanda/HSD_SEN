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
   //to do
};


//Funktor Equal_to: hier als struct definiert, da keine Daten gespeichert werden
template<typename T>
struct Equal_to 
{
   //to do
};


//Funktor zur Ermittlung und Speicherung einer Summe aller geraden Elemente
template<typename T>
class SumEven
{
 //to do
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