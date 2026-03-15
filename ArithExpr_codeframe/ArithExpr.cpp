///////////////////////////////////////////////////////////////////////////
// Workfile : ArithExpr.cpp
// Author : Leander Kieweg
// Date : 07.03.2026
// Description : Arithmetic Expression Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include "parser.h"

using namespace std;
using namespace pfc;

int main()
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
      scanner scan{ file };
      //...scan expression
      int Result = ScanExpression(scan);
      if (!scan.is_eof()) {
         std::cerr << "error scan expression" << std::endl;
         throw std::runtime_error("error scan expression");
      }

      std::cout << Result << std::endl;
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