#include <fstream>
#include <iostream>
#include "scanner.h"

using namespace std;
using namespace pfc;


// --------------------
// Function Definitions
// --------------------

//Prüfung auf terminalen Anfang für den Add-Operator(+,-)
static bool IsTBAddOp (scanner const& scan)
{
   return scan.is('+') || scan.is('-');
}

//Prüfung auf terminalen Anfang für den Mul-Operator(*,/)
static bool IsTBMulOp(scanner const& scan)
{
   return scan.is('*') || scan.is('/');
}

//Prüfung auf terminalen Anfang für einen Faktor
static bool IsTBFactor(scanner const& scan)
{
   return scan.get_integer() || scan.is('(');
}

//Prüfung auf terminalen Anfang für einen Term
static bool IsTBTerm(scanner const& scan)
{
   return IsTBFactor(scan);
}

//Prüfung auf terminalen Anfang für eine Expression
static bool IsTBExpression(scanner const& scan)
{
   return IsTBAddOp(scan) || IsTBTerm(scan);
}


//Erkenne den Additionsoperator und liefer das Vorzeichen
static int ScanAddOp(scanner& scan)
{
   int sign = 0;
   if (scan.is('+')) {
      sign = +1; //positives vorzeichen
   }
   else if (scan.is('-')) {
      sign = -1; //negatives vorzeichen
   }

   scan.next_symbol(); //weiterschalten auf das nächste symbol
   return sign;
}

//Vorwärtsdeklaration (forward declaration)
static int ScanExpression(scanner& scan);

//Erkenne einen Faktor
static int ScanFactor(scanner& scan)
{
   int val = 0;
   if (scan.is_integer()) {
      val = scan.get_integer();
      scan.next_symbol();
   }
   //TODO geklammerter ausdruck

   return val;
}

//Erkenne einen Term
static int ScanTerm(scanner& scan)
{
   int val = ScanFactor(scan);

   while (IsTBMulOp(scan)) {
      if (scan.is('*')) {
         scan.next_symbol(); // weiterlesen
         val *= ScanFactor(scan); // -> multiplizieren
      }
      //TODO Division
   }

   return val;
}

//Erkenne einen arithmetischen Ausdruck
static int ScanExpression (scanner& scan)
{
   int sign = 1;
   int val = 0;

   if (IsTBAddOp(scan)) {
      sign = ScanAddOp(scan);

   }
   val = sign * ScanTerm(scan);

   // TODO add loop for multiple terms
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