///////////////////////////////////////////////////////////////////////////
// Workfile : Calendar.cpp
// Author : Leander Kieweg
// Date : 03.05.2026
// Description : Calendar Class Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "Calendar.h"
#include <iterator>
#include <algorithm>

void Calendar::AddEntry(Date const &date, std::string const &text) {
    mCalendar[date] = text;
}

void Calendar::Clear() {
    mCalendar.clear();
}

void Calendar::PrintAllEntries(bool const ascending) const {
    if (ascending) {
        for (auto it = mCalendar.cbegin(); it != mCalendar.cend(); ++it) {
            std::cout << it->first << " " << it->second << '\n';
        }
    } else {
        for (auto it = mCalendar.crbegin(); it != mCalendar.crend(); ++it) {
            std::cout << it->first << " " << it->second << '\n';
        }
    }
}

std::vector<Date> Calendar::FindByText(std::string const &searchText) const {
    std::vector<Date> result;

    std::string lowerSearchText = toLower(searchText);

    for (auto it = mCalendar.cbegin(); it != mCalendar.cend(); ++it) {
        if (toLower(it->second).find(lowerSearchText) != std::string::npos ) {
            result.push_back(it->first);
        }
    }
    return result;
}

std::string Calendar::toLower(std::string str) const {
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return str;
}
