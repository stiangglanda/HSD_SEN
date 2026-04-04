//
// Created by stiangglanda on 2026-04-04.
//

#include "Calendar.h"

#include <cassert>

Calendar::CalendarEntry* Calendar::MakeNode(Date const& date, std::string const& text) {
    CalendarEntry* newNode = new (std::nothrow) CalendarEntry;
    if (newNode != nullptr) {
        newNode->date = date;
        newNode->text = text;
        newNode->pLeft = nullptr;
        newNode->pRight = nullptr;
    }
    assert(newNode != nullptr);
    return newNode;
}

void Calendar::AddEntry(Date const &date, std::string const &text) {
    if (mRoot) {
        if (Data < mRoot->Data) {
            InsertSorted(pRoot->pLeft, Data);
        } else if (Data > pRoot->Data) {
            InsertSorted(pRoot->pRight, Data);
        } else { // value already exists
            return;
        }
    } else {
        pRoot = MakeNode(Data);
    }
}

void Calendar::PrintAllEntries(bool const ascending) const {
    if (ascending) {
        PrintInOrder(mRoot);
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