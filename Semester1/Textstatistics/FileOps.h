//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Workfile : FileOps.h
// Author   : mb
// Date     : 03. 11. 2025
// Description : Function(s) to process files. [Interface]
// Remarks  : -
// Revision : 0
//////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FILEOPS_H
#define FILEOPS_H

#include <string>

// -------------------------------------------------------------------------------------------------------
// Reads data from a file into a char array. If the file contains more chars than the array can hold,
// the remaining part of the file is silently ignored. Memory has to be allocated by the caller.
// Params:
//   fileName  ...  name of the file to process
//   text      ...  array of char containg the text
//   maxLen    ...  max number of bytes the array can hold
//   textLen   ...  number of characters written into the character array (without terminating 0)
// Return value:
//   false, on invalid params or an error during file-io; true otherwise
// -------------------------------------------------------------------------------------------------------
bool ReadData(std::string const& fileName, char text[], size_t const maxLen, size_t& textLen);


#endif