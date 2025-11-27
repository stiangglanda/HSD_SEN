///////////////////////////////////////////////////////////////////////////
// Workfile : Matrix.h
// Author : Leander Kieweg
// Date : 21. 11. 2025
// Description : Matrix module with general matrix utility functions
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <string>
#ifndef TEXTSTATISTICS_H
#define TEXTSTATISTICS_H

void analyse(std::string const& fileName);

void ReadFile(const std::string& fileName, char  text[100], size_t& textLen, bool& retFlag);

void PrintAnalyticsResult(unsigned int  charOcorencyCounter[29]);

#endif