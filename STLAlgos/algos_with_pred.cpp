#include "STLAlgos.h"
#include "Output.h"
using namespace std;


void Test_Algos_With_Pred(string const& header)
{
   auto oldState = cout.exceptions(); // vorherigen Zustand merken
   try
   {
      cout.exceptions(ios::failbit | ios::badbit);
      PrintTestHeader(header);

      //Initialisierung der Daten
      string str = "salZbuRgEr NoCkerL";
      TStrArr sarr = { "alpha", "BRAVO", "charley", "ECHO", "delta" };
      TDeqCont cont{ 1, -2, 3, -4, 5, -6 };

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