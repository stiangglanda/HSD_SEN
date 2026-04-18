///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 04.04.2026
// Description : Test Driver for Date and Calendar
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "DivingComputer.h"

int main() {
    DivingComputer divingComputer;

    divingComputer.EmplaceBackDiveEntry(0,0.0);
    divingComputer.EmplaceBackDiveEntry(1,0.5);
    divingComputer.EmplaceBackDiveEntry(2,0.4);
    divingComputer.EmplaceBackDiveEntry(3,0.4);
    divingComputer.PrintDiveStats();
    return 0;
}
