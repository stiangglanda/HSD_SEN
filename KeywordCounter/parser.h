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

#include <iosfwd>
#include <string>

// Register a keyword with the internal scanner
void RegisterKeyword(const std::string& keyword);

// Extract keyword and identifier statistics from the provided input stream
void ExtractStatistics(std::istream& file);

// Print the collected keyword and identifier statistics to the standard output
void PrintStatistics();

#endif
