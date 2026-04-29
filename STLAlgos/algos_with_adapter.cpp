#include "STLAlgos.h"
#include "Output.h"
using namespace std;

//eine Liste mit Paaren aus int und float
typedef list<pair<int, float>> TLPairs;

//Ausgabeoperator für Liste mit Paaren
static ostream& operator << (ostream& ost, TLPairs::value_type const& p)
{
   return ost << "(" << p.first << "," << p.second << ")";
}

//Lambda zur Ausgabe von Listen-Paaren
static auto out = [](TLPairs const& l) 
{
   for (auto const& p : l) { 
      cout << p << " "; 
   } 
   cout << endl; 
};


void Test_Algos_With_Adapter(std::string const& header)
{
   auto oldState = cout.exceptions(); // vorherigen Zustand merken
   try
   {
      cout.exceptions(ios::failbit | ios::badbit);
      PrintTestHeader(header);
      //Testdaten
      TDeqCont cont{ 3, 1, 4, 5, 7, 0, 8, 2, 6 };
      TDeqCont cont2{ 1, 3, 4, 5, 6, 7 }, cont3 = cont2, cont4 = cont2;
      TLPairs lPairs{ {9,9.9f},{3,3.3f}, {1,1.2f}, {1,1.1f}, {9,9.8f}, {4,4.4f} };

      //to do
   }
   catch (std::bad_alloc const& ex)
   {
      std::cerr << "memory allocation: " << ex.what() << std::endl;
      return;
   }
   catch (std::ios_base::failure const& ex)
   {
      std::cerr << "I/O error: " << ex.what() << std::endl;
      cout.exceptions(oldState); // vorherigen Zustand wiederherstellen
      return;
   }
   catch (std::exception const& ex)
   {
      std::cerr << ex.what() << std::endl;
      return;
   }
   catch (...)
   {
      std::cerr << "unhandled exception..." << std::endl;
      return;
   }
}
