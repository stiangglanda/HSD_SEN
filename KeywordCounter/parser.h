///////////////////////////////////////////////////////////////////////////
// Workfile : parser.h
// Author : Leander Kieweg
// Date : 07.03.2026
// Description : parser for Arithmetic Expression Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef PARSER_H
#define PARSER_H

#include <map>

#include "scanner.h"

struct StatEntry {
    bool isKeyword;
    size_t occurence;
};

using Stats = std::map<std::string, StatEntry>;

int ScanExpression(pfc::scanner& scan);

#endif
