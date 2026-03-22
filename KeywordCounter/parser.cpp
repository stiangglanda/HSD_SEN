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
#include "scanner.h"

const size_t MaxKeywords=10;
const size_t MaxIdentifier=20;

struct StatEntry {
    std::string name;
    size_t occurrence;
};

struct Stat {
    StatEntry Keywords[MaxKeywords];
    StatEntry Identifier[MaxIdentifier];
    size_t keywordCnt=0;
    size_t IdentifierCnt=0;
};

static Stat stats;
static pfc::scanner scanner;

void RegisterKeyword(const std::string& keyword) {
    scanner.register_keyword(keyword);
}

static StatEntry* Find(StatEntry arr[], size_t n, const std::string& name) {
   for (size_t i=0; i<n; i++) {
      if (arr[i].name==name) {
         return &arr[i];
      }
   }
   return nullptr;
}

void PrintStatistics() {
   size_t totalKeywordOccurence=0;
   size_t totalIdentifierOccurence=0;

   for (size_t i =0; i<stats.keywordCnt; i++) {
      std::cout << "Keyword('" << stats.Keywords[i].name << "'): " << stats.Keywords[i].occurrence << std::endl;
      totalKeywordOccurence+=stats.Keywords[i].occurrence;
   }

   for (size_t i =0; i<stats.IdentifierCnt; i++) {
      std::cout << "Identifier('" << stats.Identifier[i].name << "'): " << stats.Identifier[i].occurrence << std::endl;
      totalIdentifierOccurence+=stats.Identifier[i].occurrence;
   }
   std::cout << std::endl;
   std::cout << "Keywords: " << stats.keywordCnt << " unterschiedlich, " << totalKeywordOccurence << " gesamt"  << std::endl;
   std::cout << "Identifiers: " << stats.IdentifierCnt << " unterschiedlich, " << totalIdentifierOccurence << " gesamt" << std::endl;
}

void ExtractStatistics (std::istream& file)
{
   scanner.set_istream(file);
   std::string CurrentName="";

   while (!scanner.is_eof()) {
      if (scanner.is_keyword()) {
         CurrentName = scanner.current_symbol().get_keyword();

         StatEntry* foundEntry=Find(stats.Keywords,stats.keywordCnt,CurrentName);
         if (foundEntry) {
            foundEntry->occurrence++;
         } else if (stats.keywordCnt < MaxKeywords) {
            stats.Keywords[stats.keywordCnt++]=StatEntry{CurrentName,1};
         } else {
            std::cerr << "Out of bounds" << std::endl;
            return;
         }

      } else if (scanner.is_identifier()) {
         CurrentName = scanner.get_identifier();

         StatEntry* foundEntry = Find(stats.Identifier,stats.IdentifierCnt,CurrentName);
         if (foundEntry) {
            foundEntry->occurrence++;
         } else if (stats.IdentifierCnt < MaxIdentifier) {
            stats.Identifier[stats.IdentifierCnt++]=StatEntry{CurrentName,1};
         } else {
            std::cerr << "Out of bounds" << std::endl;
            return;
         }
      }
      scanner.next_symbol();
   }
}