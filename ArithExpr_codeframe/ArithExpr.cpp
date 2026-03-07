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
      std::cout << ScanExpression(scan) << std::endl;
      if (!scan.is_eof()) {
         std::cerr << "error scan expression" << std::endl;
      }
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