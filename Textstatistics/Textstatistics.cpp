///////////////////////////////////////////////////////////////////////////
// Workfile : Textstatistics.cpp
// Author : Leander Kieweg
// Date : 29. 11. 2025
// Description : calculates occurrences of characters in a text
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include "Textstatistics.h"
#include "FileOps.h"
#include <iostream>
#include <locale>

using namespace std;

const unsigned int TEXT_SIZE = 10000;

bool ReadFile(const std::string& fileName, char text[], size_t& textLen);

AnalysisResult AnalyseText(std::string const& fileName)
{
    AnalysisResult result = {};
    char text[TEXT_SIZE];

    if (!ReadFile(fileName, text, result.textLength)) {
        result.success = false;
        return result;
    }

    result.success = true;

    for (size_t i = 0; i < result.textLength; i++)
    {
        char original = text[i];
        char upper = toupper(original);

        if (upper >= 'A' && upper <= 'Z')
        {
            result.counts[upper - 'A']++;
        }
        else
        {
            switch (original)
            {
                case ' ':
                    result.counts[26]++;
                    break;
                case '.':
                case ',':
                case ';':
                case ':':
                case '?':
                case '!':
                    result.counts[27]++;
                    break;
                default:
                    result.counts[28]++;
                    break;
            }
        }
    }

    return result;
}

bool ReadFile(const std::string& fileName, char text[], size_t& textLen)
{
    if (!ReadData(fileName, text, TEXT_SIZE, textLen))
    {
        return false;
    }
    return true;
}