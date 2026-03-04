#include <fstream>
#include <iostream>
#include "scanner.h"

using namespace std;
using namespace pfc;


// --------------------
// Function Definitions
// --------------------

//Pr�fung auf terminalen Anfang f�r den Add-Operator(+,-)
static bool IsTBAddOp (scanner const& scan)
{
   return false;
}

//Pr�fung auf terminalen Anfang f�r den Mul-Operator(*,/)
static bool IsTBMulOp(scanner const& scan)
{
   return false;
}

//Pr�fung auf terminalen Anfang f�r einen Faktor
static bool IsTBFactor(scanner const& scan)
{
   return false;
}

//Pr�fung auf terminalen Anfang f�r einen Term
static bool IsTBTerm (scanner const& scan)
{
   return false;
}

//Pr�fung auf terminalen Anfang f�r eine Expression
static bool IsTBExpression(scanner const& scan)
{
   return false;
}


//Erkenne den Additionsoperator und liefer das Vorzeichen
static int ScanAddOp(scanner& scan)
{
   return 0;
}

//Vorw�rtsdeklaration (forward declaration)
static int ScanExpression(scanner& scan);

//Erkenne einen Faktor
static int ScanFactor(scanner& scan)
{
   return 0;
}

//Erkenne einen Term
static int ScanTerm(scanner& scan)
{
   return 0;
}

//Erkenne einen arithmetischen Ausdruck
static int ScanExpression (scanner& scan)
{
   return 0;
}

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