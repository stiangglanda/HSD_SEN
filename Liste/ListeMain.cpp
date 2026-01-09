// Testtreiber
#include <iostream>
#include <curses.h>
#include "ListenModul.h"

using namespace std;

int main() {
    TList list=nullptr; // leere Liste
    Print(list);
    Prepend(list, 1);
    Prepend(list, 2);
    Prepend(list, 3);
    Prepend(list, 4);

    Print(list);

    Append(list, 1);
    Append(list, 2);
    Append(list, 3);
    Append(list, 4);

    Print(list);
    PrintRecursive(list);
    Delete(list, 4);

    Print(list);
    Flush(list);
    Print(list);

    //---------------------------
    cout << "Liste aufbauen... " << endl;
    for (int i = 0; i < 1000000; i++) {
        //Append(list, 17);
        Prepend(list, 17);
    }
    cout << "Fertig! Taste druecken fuer Loeschen der Liste." << endl;
    cin.get(); //_getch(); // warten auf Tastendrucke

    Flush(list);
    Print(list);

    PrintRecursive(list);
    return 0;
}