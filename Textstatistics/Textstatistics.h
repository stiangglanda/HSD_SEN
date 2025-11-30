///////////////////////////////////////////////////////////////////////////
// Workfile : Textstatistics.h
// Author : Leander Kieweg
// Date : 29. 11. 2025
// Description : calculates occurrences of characters in a text
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#ifndef TEXTSTATISTICS_H
#define TEXTSTATISTICS_H
#include <string>

const unsigned int NUM_CATEGORIES = 29;

struct AnalysisResult {
    unsigned int counts[NUM_CATEGORIES];
    size_t textLength;
    bool success;
};

AnalysisResult AnalyseText(std::string const& fileName);

#endif