///////////////////////////////////////////////////////////////////////////
// Workfile : Calendar.h
// Author : Leander Kieweg
// Date : 04.04.2026
// Description : Calendar Class Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef CALENDAR_H
#define CALENDAR_H
#include <string>
#include "Date.h"

class Calendar {
public:
    // Constructor: Initialize an empty calendar
    Calendar();
    // Copy constructor
    Calendar(Calendar const& cal);
    // Destructor: Free all memory associated with the calendar
    ~Calendar();

    // Assignment operator
    Calendar& operator =(Calendar const& cal);
    // Adds an entry to the calendar. If an entry for the given date already
    // exists, it is replaced.
    void AddEntry(Date const& date, std::string const& text);

    // Deletes all entries from the calendar
    void Clear();
    // Prints all entries, sorted by their date, either ascending or
    // descending, depending on the parameter
    void PrintAllEntries(bool const ascending=true) const;

private:
    // nested struct: Fully encapsulated within the private scope.
    // Belongs exclusively to Calendar and is invisible from outside.
    struct CalendarEntry {
        const Date date;
        std::string text;
        CalendarEntry* pLeft;
        CalendarEntry* pRight;
    };
    // member variables
    CalendarEntry* mRoot;
    // private helper methods

    // L-W-R
    void PrintInOrder(const CalendarEntry* const pRoot) const;

    // R-W-L
    void PrintReverseOrder(const CalendarEntry* const pRoot) const;

    static CalendarEntry* MakeNode(Date const& date, std::string const& text);

    void InsertSorted(CalendarEntry*& pRoot, Date const &date, std::string const &text);

    // Delete all nodes in the tree
    void Flush(CalendarEntry*& pRoot);

    void CopyPreOrder(const CalendarEntry* pRoot);
};

#endif