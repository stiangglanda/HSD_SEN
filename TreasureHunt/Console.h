//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Workfile : Console.h
// Author   : mb
// Date     : 11. 12. 2025
// Description : Some simple functions for console output [Interface]
// Remarks  : not portable (win32 specific)
// Revision : 0
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CONSOLE_INCLUDED
#define CONSOLE_INCLUDED

#include <windows.h>
#include <string>

// Color Constants
// ---------------

enum TextColor
{
    eFgBLACK        = 0,
    eFgDARKRED      = FOREGROUND_RED,
    eFgDARKGREEN    = FOREGROUND_GREEN,
    eFgDARKBLUE     = FOREGROUND_BLUE,
    eFgOCHER        = FOREGROUND_RED | FOREGROUND_GREEN,
    eFgVIOLET       = FOREGROUND_RED | FOREGROUND_BLUE,
    eFgTURQUOISE    = FOREGROUND_GREEN | FOREGROUND_BLUE,
    eFgGREY         = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

    eFgDARKGREY     = FOREGROUND_INTENSITY,
    eFgRED          = FOREGROUND_INTENSITY | FOREGROUND_RED,
    eFgGREEN        = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    eFgBLUE         = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    eFgYELLOW       = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    eFgPINK         = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    eFgLIGHTBLUE    = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    eFgWHITE        = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
};


// Screen and IO-related Functions
// -------------------------------

// clear the console
void ClearScreen();

// wait for a key to be pressesd and returns its ASCII-Code
// Special keys are indicated via param IsSpecial (true)
int GetKey (bool & IsSpecial);

// Set the cursor to the specified position x,y in the console output window
// Ranges:  x: 0 to 78 (column)
//          y: 1 to 23 (row)
void GotoXY (int const posX, int const posY);

// Set the text color for the console output.
void SetTextColor (TextColor const col);

// set the title of the console window
void SetTitle (std::string const & title);

// Write character ch at console coordinates posX, posY
void WriteXY (char const ch, int const posX, int const posY, bool const doBackStep = false);

// Write string str at console coordinates posX, posY
void WriteXY (std::string const & str, int const posX, int const posY, bool const doBackStep = false);

// Write character array str at console coordinates posX, posY
void WriteXY (char const str[], int const posX, int const posY, bool const doBackStep = false);

// Additional Functions
// --------------------

// make a beep in the given frequency [HZ] for the specified duration [ms]
void DoBeep (size_t const frequency_hz, size_t const duration_ms);

// sleep for ms milliseconds
void DoSleep (int const ms);


#endif