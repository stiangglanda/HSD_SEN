//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Workfile : FileOps.cpp
// Author   : mb
// Date     : 03. 11. 2025
// Description : Function(s) to process files. [Implementation]
// Remarks  : -
// Revision : 0
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include "FileOps.h"

using namespace std;


// -------------------------------------------------------------------------------------------------------
// Reads data from a file into a char array. If the file contains more chars than the array can hold,
// the remaining part of the file is silently ignored. Memory has to be allocated by the caller.
// Params:
//   fileName  ...  name of the file to process, eg: "MyFile.txt"
//   text      ...  array of char containing the text
//   maxLen    ...  max number of bytes the array can hold
//   textLen   ...  number of characters written into the character array (without terminating 0)
// Return value:
//   true, if data could be copied; false otherwise
// -------------------------------------------------------------------------------------------------------
bool ReadData(std::string const& fileName, char text[], size_t const maxLen, size_t& textLen) {

    if (maxLen == 0) { return false; }

    ifstream in(fileName.c_str());
    if (!in) {
        textLen = 0;
        text[0] = 0;
        return false;
    }

    size_t  i = 0;
    char    ch = 0;

    while (in.get(ch)) {
        text[i] = ch;
        if (i == maxLen - 1) {
            break;
        }
        i++;
    }
    in.close();
    textLen = i;
    text[textLen] = 0;
    return true;
}