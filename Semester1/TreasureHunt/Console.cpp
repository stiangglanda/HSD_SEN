//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Workfile : Console.cpp
// Author   : mb
// Date     : 11. 12. 2025
// Description : Some simple functions for console output [Implementation]
// Remarks  : not portable (win32 specific)
// Revision : 0
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <conio.h>
#include "Console.h"

using namespace std;


// clear the console output window
void ClearScreen()
{
   COORD ScreenCoord  = { 0, 0 };
   DWORD CharsWritten = 0;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   // retrieve number of character cells to clear
   if(!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
       return;
   }
   DWORD ConSize = csbi.dwSize.X * csbi.dwSize.Y;

   // fill screen with blanks
   if(!FillConsoleOutputCharacter(hConsole, ' ', ConSize, ScreenCoord, & CharsWritten )) {
       return;
   }
   // get current text attribute
   if(!GetConsoleScreenBufferInfo(hConsole, &csbi )) {
       return;
   }
   // set buffer attributes
   if( !FillConsoleOutputAttribute(hConsole, csbi.wAttributes, ConSize, ScreenCoord, & CharsWritten )) {
       return;
   }
   // set cursor at its home coordinates
   GotoXY(ScreenCoord.X, ScreenCoord.Y);
}


// waits for a key to be pressesd and returns its ASCII-Code
// Special keys are indicated via param IsSpecial (true)
int GetKey(bool & IsSpecial)
{
	char Key = 0;
    IsSpecial = false;
	while (!_kbhit());         // wait until key is pressed

    Key = _getch();
	if (Key == 0)             // check for special key
	{
		IsSpecial = true;
		Key = _getch();
	}
    return Key;
}

// Set the cursor to the specified position x,y in the console output window
// Ranges:  x: 0 to 78 (column)
//          y: 1 to 23 (row)
void GotoXY(int const posX, int const posY)
{
    COORD CursorPosition = {posX, posY};

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, CursorPosition);
}


// Set the text color for the console output.
void SetTextColor(TextColor const col)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>(col));
}

// set the title of the console window
void SetTitle(std::string const & title)
{
	SetConsoleTitle(title.c_str());
	// NOTE: on compiler errors on the above line ("cannot convert to LPCWSTR") just change your project settings:
	//       project properties --> general --> character set: not set
}

// Write character ch at console coordinates posX, posY
void WriteXY(char const ch, int const posX, int const posY, bool const doBackStep)
{
	GotoXY(posX, posY);
    cout << ch << (doBackStep ? "\b" : "");
}

// Write string str at console coordinates posX, posY
void WriteXY(std::string const & str, int const posX, int const posY, bool const doBackStep)
{
	GotoXY(posX, posY);
	cout << str << (doBackStep ? "\b" : "");
}

// Write character array str at console coordinates posX, posY
void WriteXY(char const str[], int const posX, int const posY, bool const doBackStep)
{
	GotoXY(posX, posY);
	cout << str << (doBackStep ? "\b" : "");
}


// make a beep in the given frequency [HZ] for the specified duration [ms]
void DoBeep(size_t const frequency_hz, size_t const duration_ms) {
    Beep(static_cast<DWORD>(frequency_hz), static_cast<DWORD>(duration_ms));
}

// sleep for ms milliseconds
void DoSleep(int const ms)
{
    Sleep(ms);
}

