///////////////////////////////////////////////////////////////////////////
// Workfile : Calendar.h
// Author : Leander Kieweg
// Date : 03.05.2026
// Description : Calendar Class Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef CALENDAR_H
#define CALENDAR_H
#include <map>
#include <string>
#include <vector>
#include "Date.h"

class Calendar {
public:
    // Adds an entry to the calendar. If an entry for the given date already
    // exists, it is replaced.
    void AddEntry(Date const& date, std::string const& text);

    // Deletes all entries from the calendar
    void Clear();
    // Prints all entries, sorted by their date, either ascending or
    // descending, depending on the parameter
    void PrintAllEntries(bool const ascending=true) const;

    // NEW: Searches for all events that contain the search text (case-insensitive)
    std::vector<Date> FindByText(std::string const& searchText) const;

private:
    std::map<Date, std::string> mCalendar;

    std::string toLower(std::string str) const;
};

#endif