///////////////////////////////////////////////////////////////////////////
// Workfile : Calendar.cpp
// Author : Leander Kieweg
// Date : 04.04.2026
// Description : Calendar Class Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "Calendar.h"
#include <cassert>

Calendar::CalendarEntry* Calendar::MakeNode(Date const& date, std::string const& text) {
    CalendarEntry* newNode = new (std::nothrow) CalendarEntry{date, text, nullptr, nullptr};
    assert(newNode != nullptr);
    return newNode;
}

void Calendar::InsertSorted(CalendarEntry*& pRoot, Date const &date, std::string const &text) {
    if (pRoot) {
        if (date.Compare(pRoot->date) == -1) {
            InsertSorted(pRoot->pLeft, date, text);
        } else if (date.Compare(pRoot->date) == 1) {
            InsertSorted(pRoot->pRight, date, text);
        } else { // value already exists
            pRoot->text = text;
        }
    } else {
        pRoot = MakeNode(date, text);
    }
}

void Calendar::Flush(CalendarEntry *&pRoot) {
    if (pRoot != nullptr) {
        Flush(pRoot->pLeft);
        Flush(pRoot->pRight);
        delete pRoot; pRoot = nullptr;
    }
}

void Calendar::CopyPreOrder(const CalendarEntry *pRoot) {
    if (pRoot != nullptr) {
        AddEntry(pRoot->date, pRoot->text);
        CopyPreOrder(pRoot->pLeft);
        CopyPreOrder(pRoot->pRight);
    }
}

Calendar::Calendar() : mRoot(nullptr) {
}

Calendar::Calendar(Calendar const &cal) : mRoot(nullptr) {
    CopyPreOrder(cal.mRoot);
}

Calendar::~Calendar() {
    Clear();
}

Calendar & Calendar::operator=(Calendar const &cal) {
    if (this != &cal) {
        Clear();
        CopyPreOrder(cal.mRoot);
    }
    return *this;
}

void Calendar::AddEntry(Date const &date, std::string const &text) {
    InsertSorted(mRoot, date, text);
}

void Calendar::Clear() {
    Flush(mRoot);
}

void Calendar::PrintAllEntries(bool const ascending) const {
    if (ascending) {
        PrintInOrder(mRoot);
    } else {
        PrintReverseOrder(mRoot);
    }
}

// L-W-R
void Calendar::PrintInOrder(const CalendarEntry* const pRoot) const {
    if (pRoot != nullptr) {
        PrintInOrder(pRoot->pLeft);
        std::cout << pRoot->date << " " << pRoot->text << std::endl;
        PrintInOrder(pRoot->pRight);
    }
}

// R-W-L
void Calendar::PrintReverseOrder(const CalendarEntry * const pRoot) const {
    if (pRoot != nullptr) {
        PrintReverseOrder(pRoot->pRight);
        std::cout << pRoot->date << " " << pRoot->text << std::endl;
        PrintReverseOrder(pRoot->pLeft);
    }
}
