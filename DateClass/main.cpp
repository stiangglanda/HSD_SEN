///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 21.03.2026
// Description : TestData Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <chrono>
#include <iostream>
#include <fstream>

#include "Date.h"

void testBsp1() {
    std::cout << "Testing valid dates" << std::endl;
    Date d1{3, 5, 2026};
    std::cout << "d1 (Expected: 03.05.2026): " << d1 << std::endl;

    Date d2{29, 2, 2024}; // Leap year
    std::cout << "d2 (Expected: 29.02.2024): " << d2 << std::endl;

    Date d3{31, 12, 1999};
    std::cout << "d3 (Expected: 31.12.1999): " << d3 << std::endl;

    std::cout << "Testing formatting" << std::endl;
    Date d4{1, 4, 2024};
    std::cout << "d4 (Expected: 01.04.2024): " << d4 << std::endl;

    std::cout << "Testing invalid dates" << std::endl;
    Date inv1{32, 12, 2023};
    std::cout << "32.12.2023 -> Expected: 01.01.1 | Actual: " << inv1 << std::endl;

    Date inv2{31, 4, 2024};
    std::cout << "31.04.2024 -> Expected: 01.01.1 | Actual: " << inv2 << std::endl;

    Date inv3{29, 2, 2023}; // Not a leap year
    std::cout << "29.02.2023 -> Expected: 01.01.1 | Actual: " << inv3 << std::endl;

    Date inv4{0, 5, 2024}; // Day 0
    std::cout << "0.5.2024   -> Expected: 01.01.1 | Actual: " << inv4 << std::endl;

    Date inv5{15, 13, 2024}; // Month 13
    std::cout << "15.13.2024 -> Expected: 01.01.1 | Actual: " << inv5 << std::endl;

    std::cout << "Testing comparisons" << std::endl;
    Date c1{10, 5, 2024};
    Date c2{10, 5, 2024};
    Date c3{11, 5, 2024};
    Date c4{10, 6, 2024};
    Date c5{10, 5, 2025};
    Date c6{9, 5, 2024};

    std::cout << c1 << " Compare " << c2 << " (Expected:  0) -> " << c1.Compare(c2) << std::endl;
    std::cout << c1 << " Compare " << c3 << " (Expected: -1) -> " << c1.Compare(c3) << std::endl;
    std::cout << c1 << " Compare " << c4 << " (Expected: -1) -> " << c1.Compare(c4) << std::endl;
    std::cout << c1 << " Compare " << c5 << " (Expected: -1) -> " << c1.Compare(c5) << std::endl;
    std::cout << c3 << " Compare " << c1 << " (Expected:  1) -> " << c3.Compare(c1) << std::endl;
    std::cout << c4 << " Compare " << c1 << " (Expected:  1) -> " << c4.Compare(c1) << std::endl;
    std::cout << c5 << " Compare " << c1 << " (Expected:  1) -> " << c5.Compare(c1) << std::endl;
    std::cout << c1 << " Compare " << c6 << " (Expected:  1) -> " << c1.Compare(c6) << std::endl;
}

int main() {
    //testBsp1();

    return 0;
}
