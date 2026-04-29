#include "STLAlgos.h"
#include "Output.h"
using namespace std;


void Test_Algos(string const& header)
{
   auto oldState = cout.exceptions(); // vorherigen Zustand merken
   try
   {
      cout.exceptions(ios::failbit | ios::badbit);
      PrintTestHeader(header);

      TDeqCont cont(5);  //Container mit Speicher für 5 Elemente
   
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