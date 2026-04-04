///////////////////////////////////////////////////////////////////////////
// Workfile : Date.h
// Author : Leander Kieweg
// Date : 04.04.2026
// Description : Date Class Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef DATE_H
#define DATE_H
#include <cstddef>
#include <iostream>

class Date {
public:
    // Constructor
    Date(size_t const day, size_t const month, size_t const year);

    // Accessor functions getDay, getMonth, getYear
    size_t getDay() const;
    size_t getMonth() const;
    size_t getYear() const;

    // Comparison function
    // returns -1 if current date (this) is before d, +1 if it is after d, 0 if it is equal
    int Compare(Date const& d) const;

    // Write date to an output stream
    void Print(std::ostream& out) const;

private:
    size_t mDay;
    size_t mMonth;
    size_t mYear;

    bool CheckDate() const;
};

// Output operator
std::ostream &operator<<(std::ostream& out, Date const& date);

#endif
