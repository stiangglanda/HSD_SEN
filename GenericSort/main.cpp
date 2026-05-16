///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 03.05.2026
// Description : Test Driver for GenericSort
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ostream>
#include <vector>

#include "GenericSort.h"

int main() {
    std::vector<int> vec1{2,4,1,5,3,5};
    auto res=SortedUntil(vec1.begin(), vec1.end());
    if (res != vec1.end()) {
        std::cout << *res << std::endl;
    }

    auto res1=SortedFrom(vec1.begin(), vec1.end());
    if (res1 != vec1.end()) {
        std::cout << *res1 << std::endl;
    }

    std::cout << "IsSorted: " << std::boolalpha << IsSorted(vec1.begin(), vec1.end()) << std::endl;

    return 0;
}
