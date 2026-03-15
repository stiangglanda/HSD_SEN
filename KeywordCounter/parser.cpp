///////////////////////////////////////////////////////////////////////////
// Workfile : parser.cpp
// Author : Leander Kieweg
// Date : 14.03.2026
// Description : parser for Keyword Counter
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "parser.h"

using namespace std;
using namespace pfc;

static StatEntry* Find(StatEntry arr[], size_t n, const std::string& name) {
   for (size_t i=0; i<n; i++) {
      if (arr[i].name==name) {
         return &arr[i];
      }
   }
   return nullptr;
}

void PrintStatistics(const Stat& stats) {
   size_t totalKeywordOccurence=0;
   size_t totalIdentifierOccurence=0;

   for (size_t i =0; i<stats.keywordCnt; i++) {
      cout << "Keyword('" << stats.Keywords[i].name << "'): " << stats.Keywords[i].occurrence << endl;
      totalKeywordOccurence+=stats.Keywords[i].occurrence;
   }

   for (size_t i =0; i<stats.IdentifierCnt; i++) {
      cout << "Identifier('" << stats.Identifier[i].name << "'): " << stats.Identifier[i].occurrence << endl;
      totalIdentifierOccurence+=stats.Identifier[i].occurrence;
   }
   cout << endl;
   cout << "Keywords: " << stats.keywordCnt << " unterschiedlich, " << totalKeywordOccurence << " gesamt"  << endl;
   cout << "Identifiers: " << stats.IdentifierCnt << " unterschiedlich, " << totalIdentifierOccurence << " gesamt" << endl;
}

Stat ExtractStatistics (scanner& scan)
{
   Stat stats{};
   std::string CurrentName="";

   while (!scan.is_eof()) {
      if (scan.is_keyword()) {
         CurrentName = scan.current_symbol().get_keyword();

         StatEntry* foundEntry=Find(stats.Keywords,stats.keywordCnt,CurrentName);
         if (foundEntry) {
            foundEntry->occurrence++;
         } else if (stats.keywordCnt < MaxKeywords) {
            stats.Keywords[stats.keywordCnt++]=StatEntry{CurrentName,1};
         } else {
            std::cerr << "Out of bounds" << std::endl;
            return stats;
         }

      } else if (scan.is_identifier()) {
         CurrentName = scan.get_identifier();

         StatEntry* foundEntry = Find(stats.Identifier,stats.IdentifierCnt,CurrentName);
         if (foundEntry) {
            foundEntry->occurrence++;
         } else if (stats.IdentifierCnt < MaxIdentifier) {
            stats.Identifier[stats.IdentifierCnt++]=StatEntry{CurrentName,1};
         } else {
            std::cerr << "Out of bounds" << std::endl;
            return stats;
         }
      }
      scan.next_symbol();
   }

   return stats;
}