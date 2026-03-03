///////////////////////////////////////////////////////////////////////////
// Workfile : LeetSpeakConverter.cpp
// Author : Leander Kieweg
// Date : 04. 12. 2025
// Description : converts text to Leet Speak
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include "LeetSpeakConverter.h"
#include <iostream>
#include <locale>

using namespace std;

const unsigned int LeetAlphabetSize = 26;

void ToLeet(std::string& str)
{
    string result="";
    static const std::string ConverterArray[LeetAlphabetSize]={"4", "8",
        "[", "|)", "3", "|=", "6", "|-|", "1", "_)",
        "|<", "|_", "//.", "/V","0", "|>", "9", "|2",
        "5", "+", "(_)", "V", "vv", "><", "Y", "2"};

    for (size_t i = 0; i < str.size(); i++) {
        char lowerChar = tolower(str[i]);
        if (lowerChar >= 'a' && lowerChar <= 'z') {
            result += ConverterArray[lowerChar - 'a'];
        }
        else {
            result += str[i];
        }
    }
    str = result;
}