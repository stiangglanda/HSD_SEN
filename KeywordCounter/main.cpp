///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 14.03.2026
// Description : Keyword Counter Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include "parser.h"

using namespace std;
using namespace pfc;

int main(int argc, char* argv[])
{

   string const fileName = "../Input.txt";
   std::ifstream file{fileName };

   //Fehlerbehandlung
   if (!file.is_open())
   {
      cerr << "can't open file " << fileName << endl;
      return 1;
   }

   try
   {
      scanner scan{};
      for (int i = 1; i < argc; ++i) {
         scan.register_keyword(argv[i]);
      }
      scan.set_istream(file);

      Stat stat=ExtractStatistics(scan);
      cout << "Ausgabe:" << endl;
      PrintStatistics(stat);


   }
   //hier werden die Exceptions des Scanners gefangen und eine Fehlermeldung ausgegeben
   catch (exception const& ex)
   {
      cerr << "Error: " << ex.what() << endl;
      file.close();
      return 1;  //exit with error code
   }

   file.close();
  
   return 0;
}