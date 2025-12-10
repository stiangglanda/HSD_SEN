// Testtreiber
#include <iostream>
#include <curses.h>
#include "ListenModul.h"

using namespace std;

int main() {
    TList list; // leere Liste
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

    return 0;
}