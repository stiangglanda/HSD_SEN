///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 04.04.2026
// Description : Test Driver for Date and Calendar
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <chrono>
#include <iostream>

#include "Date.h"
#include "Calendar.h"

void testDate() {
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

void testCalendar() {
    std::cout << "Testing Calendar" << std::endl;
    Calendar cal;

    std::cout << "Adding entries" << std::endl;
    Date d1{15, 6, 2026};
    Date d2{1, 1, 2026};
    Date d3{31, 12, 2026};
    Date d4{15, 6, 2026}; // Duplicate date for replacement

    cal.AddEntry(d1, "Mid-year meeting");
    cal.AddEntry(d2, "New Year's Day");
    cal.AddEntry(d3, "New Year's Eve");

    std::cout << "Ascending Print:" << std::endl;
    cal.PrintAllEntries(true);
    // Expected:
    // 01.01.2026 New Year's Day
    // 15.06.2026 Mid-year meeting
    // 31.12.2026 New Year's Eve

    std::cout << "Descending Print:" << std::endl;
    cal.PrintAllEntries(false);
    // Expected:
    // 31.12.2026 New Year's Eve
    // 15.06.2026 Mid-year meeting
    // 01.01.2026 New Year's Day

    std::cout << "Replacing entry for 15.06.2026" << std::endl;
    cal.AddEntry(d4, "Important Project Deadline");
    cal.PrintAllEntries(true);

    std::cout << "Testing Copy Constructor (cal2 = cal)" << std::endl;
    Calendar cal2(cal);
    cal2.PrintAllEntries(true);

    std::cout << "Adding new entry to cal2, modifying original won't affect it." << std::endl;
    cal2.AddEntry(Date{10, 10, 2026}, "cal2 exclusive event");
    std::cout << "cal2 entries:" << std::endl;
    cal2.PrintAllEntries(true);
    std::cout << "Original cal entries:" << std::endl;
    cal.PrintAllEntries(true);

    std::cout << "Testing Assignment Operator (cal3 = cal2)" << std::endl;
    Calendar cal3;
    cal3.AddEntry(Date{5, 5, 2025}, "Old event in cal3");
    cal3 = cal2;
    cal3.PrintAllEntries(true);

    std::cout << "Testing Self-Assignment (cal = cal)" << std::endl;
    cal = cal;
    cal.PrintAllEntries(true);

    std::cout << "Testing Clear()" << std::endl;
    cal.Clear();
    std::cout << "Cal entries after Clear (Should be empty):" << std::endl;
    cal.PrintAllEntries(true);
}

int main() {
    testDate();
    testCalendar();
    return 0;
}
