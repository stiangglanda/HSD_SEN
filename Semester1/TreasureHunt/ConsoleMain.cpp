//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Workfile : ConsoleMain.h
// Author   : mb
// Date     : 11. 12. 2025
// Description : A simple example to show the usage of the console-functions
// Remarks  : -
// Revision : 0
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Console.h"

using namespace std;

int main() {

    // show some lines of text
    // -----------------------
    SetTitle("The new Title of the Console Window");

    SetTextColor(eFgLIGHTBLUE);
    GotoXY(2, 3);
    cout << "A single line of colored text at a given position." << endl;


    SetTextColor(eFgRED);
    WriteXY("Another line of colored text - Function WriteXY()", 4, 5, false);

    // delay the output for 2000ms ... then clear the screen.
    Sleep(2000);
    ClearScreen();

    // show a bouncing ball
    // --------------------

    int const m = 5;
    int const n = 12;
    char A[m][n] = {"+---------+",
                    "|         |",
                    "|         |",
                    "|         |",
                    "+---------+"};

    SetTextColor(eFgGREEN);
    int x = 2;
    int y = 2;
    int d = 1;
    int const cnt = 40;
    bool MakeBeep = false;

    for (int k = 0; k < cnt; ++k) {

        A[x][y] = 'o';          // place ball

        // print field
        for (int i = 0; i < m; ++i) {
            WriteXY(A[i], 0, i);
        }
        if (MakeBeep) {
            DoBeep(660, 100);
        }
        A[x][y] = ' ';          // remove ball

        y += d;
        MakeBeep = true;

        if (y == n-3) {         // rigth border
            d = -1;
        }
        else if (y == 1) {      // left border
            d = 1;
        }
        else {
            MakeBeep = false;
        }
        DoSleep(200);
    }

    GotoXY(0, 24);
    SetTextColor(eFgDARKGREY);

    return 0;
}