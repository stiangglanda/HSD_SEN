///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 23.05.2026
// Description : GenericFunctors Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "GenericFunctors.h"

void printContainer(const std::vector<int>& vec) {
    std::cout << "Container = {";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i < vec.size() - 1 ? "," : "");
    }
    std::cout << "}" << std::endl;
}

template<typename Predicate>
void executeAlgorithmTest(const std::vector<int>& vec, int target, Predicate pred) {
    printContainer(vec);
    std::cout << "bestimmte Zahl = " << target << std::endl << "Ausgabe: ";
    std::copy_if(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "), pred);
    std::cout << std::endl << std::endl;
}

void testBaseCases() {
    std::cout << "Base Cases" << std::endl;
    std::vector<int> vec{2, 3, 4, 5, 2, 5, 9, 6};

    const int targetMultiples = 3;
    executeAlgorithmTest(vec, targetMultiples, IsMultipleOf<int>{targetMultiples});

    const int targetParts = 12;
    executeAlgorithmTest(vec, targetParts, IsPartOf<int>{targetParts});
}

void testEdgeCases() {
    std::cout << "Edge Cases Testing Zero handling" << std::endl;

    // Container contains 0
    std::vector<int> vecZero{0, 2, 3, 4, 12};
    const int targetPartsZeroContainer = 12;
    executeAlgorithmTest(vecZero, targetPartsZeroContainer, IsPartOf<int>{targetPartsZeroContainer});

    // Target number is 0 IsPartOf
    const int targetZeroPart = 0;
    executeAlgorithmTest(vecZero, targetZeroPart, IsPartOf<int>{targetZeroPart});

    // Target number is 0 IsMultipleOf
    const int targetZeroMultiple = 0;
    executeAlgorithmTest(vecZero, targetZeroMultiple, IsMultipleOf<int>{targetZeroMultiple});
}

int main()
{
    testBaseCases();
    testEdgeCases();

    return 0;
}
