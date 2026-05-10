///////////////////////////////////////////////////////////////////////////
// Workfile : Date.cpp
// Author : Leander Kieweg
// Date : 03.05.2026
// Description : Date Class Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "Date.h"
#include <iomanip>

static const std::string cErrDateValid = "Date not valid";
static const std::string cErrStream = "ostream not ok";

Date::Date(size_t const day, size_t const month, size_t const year) :
    mDay(day), mMonth(month), mYear(year) {
    if (!CheckDate()) {
        mDay = 1;
        mMonth = 1;
        std::cerr << cErrDateValid << std::endl;
    }
}

size_t Date::getDay() const {
    return mDay;
}

size_t Date::getMonth() const {
    return mMonth;
}

size_t Date::getYear() const {
    return mYear;
}

int Date::Compare(Date const &d) const {
    if (mYear != d.getYear()) {
        return mYear < d.getYear() ? -1 : 1;
    }
    if (mMonth != d.getMonth()) {
        return mMonth < d.getMonth() ? -1 : 1;
    }
    if (mDay != d.getDay()) {
        return mDay < d.getDay() ? -1 : 1;
    }
    return 0;
}

bool Date::operator<(Date const &other) const {
    return this->Compare(other) == -1;
}

bool Date::CheckDate() const {
    if (mYear == 0 || mMonth == 0 || mMonth > 12 || mDay == 0) {
        return false;
    }

    size_t daysInMonth = 31;
    if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) {
        daysInMonth = 30;
    } else if (mMonth == 2) {
        const bool isLeapYear = (mYear % 4 == 0 && mYear % 100 != 0) || (mYear % 400 == 0);
        daysInMonth = isLeapYear ? 29 : 28;
    }

    return mDay <= daysInMonth;
}

void Date::Print(std::ostream &out) const {
    if (!out.good()) {
        throw std::invalid_argument(cErrStream);
    }

    out << std::setw(2) << std::setfill('0') << mDay << '.'
        << std::setw(2) << std::setfill('0') << mMonth << '.'
        << mYear;
}

std::ostream & operator<<(std::ostream &out, Date const &date) {
    date.Print(out);
    return out;
}
