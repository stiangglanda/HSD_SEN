///////////////////////////////////////////////////////////////////////////
// Workfile : parser.cpp
// Author : Leander Kieweg
// Date : 07.03.2026
// Description : parser for Arithmetic Expression
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "parser.h"

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
   return scan.is_integer() || scan.is('(');
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

//Erkenne einen Faktor
static int ScanFactor(scanner& scan)
{
   int val = 0;
   if (scan.is_integer()) {
      val = scan.get_integer();
      scan.next_symbol();
   } else if (scan.is('(')) {
      scan.next_symbol(); // öffnende Klammer konsumieren

      val = ScanExpression(scan);

      if (scan.is(')')) {
         scan.next_symbol(); // schließende Klammer konsumieren
      } else {
         std::cerr << "error scan factor" << std::endl;
         std::exit(1);
      }
   } else {
      std::cerr << "error scan factor" << std::endl;
      std::exit(1);
   }

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
      } else {
         scan.next_symbol(); // Division
         int divisor = ScanFactor(scan);

         if (divisor == 0) {
            std::cerr << "error: division by zero" << std::endl;
            std::exit(1);
         }
         val /= divisor;
      }
   }

   return val;
}

//Erkenne einen arithmetischen Ausdruck
int ScanExpression (scanner& scan)
{
   int sign = 1;
   int val = 0;


   if (IsTBAddOp(scan)) {
      sign = ScanAddOp(scan);
   }

   val = sign * ScanTerm(scan);

   while (IsTBAddOp(scan)) {
      if (scan.is('+')) {
         scan.next_symbol();
         val += ScanTerm(scan);
      } else {
         scan.next_symbol();
         val -= ScanTerm(scan);
      }
   }

   return val;
}