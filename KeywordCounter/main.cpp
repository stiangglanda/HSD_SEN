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

int main(int argc, char* argv[])
{

   std::string const fileName = "../Input.txt";
   std::ifstream file{fileName };

   //Fehlerbehandlung
   if (!file.is_open())
   {
      std::cerr << "can't open file " << fileName << std::endl;
      return 1;
   }

   try
   {
      pfc::scanner scan{};
      for (int i = 1; i < argc; ++i) {
         scan.register_keyword(argv[i]);
      }
      scan.set_istream(file);

      Stat stat=ExtractStatistics(scan);
      std::cout << "Ausgabe:" << std::endl;
      PrintStatistics(stat);


   }
   //hier werden die Exceptions des Scanners gefangen und eine Fehlermeldung ausgegeben
   catch (std::exception const& ex)
   {
      std::cerr << "Error: " << ex.what() << std::endl;
      file.close();
      return 1;  //exit with error code
   }

   file.close();
  
   return 0;
}