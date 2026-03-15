///////////////////////////////////////////////////////////////////////////
// Workfile : parser.h
// Author : Leander Kieweg
// Date : 14.03.2026
// Description : Keyword Counter parser Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"
#include <cstddef>
#include <string>

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

// Extract keyword and identifier statistics from the provided scanner
Stat ExtractStatistics(pfc::scanner& scan);

// Print the collected keyword and identifier statistics to the standard output
void PrintStatistics(const Stat& stats);

#endif
