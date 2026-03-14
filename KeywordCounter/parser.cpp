///////////////////////////////////////////////////////////////////////////
// Workfile : parser.cpp
// Author : Leander Kieweg
// Date : 14.03.2026
// Description : parser for Arithmetic Expression
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "parser.h"

using namespace std;
using namespace pfc;

//Erkenne einen arithmetischen Ausdruck
int ScanExpression (scanner& scan)
{
   Stats stats;
   while (!scan.is_eof()) {
      if (scan.is_keyword()) {
         cout << "keyword " << scan.current_symbol().get_keyword() << endl;

         if (stats.contains(scan.current_symbol().get_keyword())) {
            stats[scan.current_symbol().get_keyword()].occurence++;
         } else {
            StatEntry entry{true, 1};
            stats[scan.current_symbol().get_keyword()]=entry;
         }
      } else if (scan.is_identifier()) {
         cout << "identifier " << scan.get_identifier() << endl;

         if (stats.contains(scan.get_identifier())) {
            stats[scan.get_identifier()].occurence++;
         } else {
            StatEntry entry{false, 1};
            stats[scan.get_identifier()]=entry;
         }
      }
      scan.next_symbol();
   }

   for(auto it = stats.cbegin(); it != stats.cend(); ++it)
   {
      std::cout << it->first << " " << it->second.occurence << " " << it->second.isKeyword << "\n";
   }
}