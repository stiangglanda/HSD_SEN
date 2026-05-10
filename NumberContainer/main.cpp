///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 03.05.2026
// Description : Test Driver for Date and Calendar
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <stdexcept>
#include "NumberContainer.h"

int main() {
    std::vector<int> const values = {
        1, -2, 3, -4, 5, 13, 15, 11, 12, 20,
        -36, -1, -76, -49, 86, 55, 67, 74, 36, -35
    };

    NumberContainer nc(values.cbegin(), values.cend());

    std::cout << "Container: ";
    for (int v : values) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    std::cout << "biggest five: ";
    for (int v : nc.GetBiggestFive()) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    std::cout << "negatives: " << nc.NegativeAmount() << std::endl;
    std::cout << "min: " << nc.GetMin() << std::endl;
    std::cout << "max: " << nc.GetMax() << std::endl;

    auto pos3 = nc.GetPositions(3);
    if (!pos3.empty()) {
        std::cout << "pos of 3: " << pos3.front() << std::endl;
    }

    auto pos11 = nc.GetPositions(11);
    if (!pos11.empty()) {
        std::cout << "pos of 11: " << pos11.front() << std::endl;
    }

    std::vector<int> const values2 = { 500, 500 };
    NumberContainer nc2(values2.cbegin(), values2.cend());

    std::cout << std::boolalpha;
    std::cout << "nc < nc2: " << (nc < nc2) << std::endl;
    std::cout << "nc == nc2: " << (nc == nc2) << std::endl;

    std::cout << "Fuege 5 Zufallszahlen zwischen 100 und 200 hinzu" << std::endl;
    nc.AddRandom(5, 100, 200);
    std::cout << "neues max (sollte >= 100 sein): " << nc.GetMax() << std::endl;

    std::cout << std::endl << "Exception Tests" << std::endl;

    std::cout << "Test GetBiggestFive() (nc2 hat nur 2 Elemente):" << std::endl;
    try {
        nc2.GetBiggestFive();
        std::cout << "ERROR: No exception thrown!" << std::endl;
    } catch (std::invalid_argument const& e) {
        std::cout << "Exception caught (as expected): " << e.what() << std::endl;
    }

    const std::vector<int> emptyValues{};
    NumberContainer ncEmpty(emptyValues.cbegin(), emptyValues.cend());

    std::cout << "Test GetMin() (leerer Container):" << std::endl;
    try {
        ncEmpty.GetMin();
        std::cout << "ERROR: No exception thrown!" << std::endl;
    } catch (std::logic_error const& e) {
        std::cout << "Exception caught (as expected): " << e.what() << std::endl;
    }

    std::cout << "Test GetMax() (leerer Container):" << std::endl;
    try {
        ncEmpty.GetMax();
        std::cout << "ERROR: No exception thrown!" << std::endl;
    } catch (std::logic_error const& e) {
        std::cout << "Exception caught (as expected): " << e.what() << std::endl;
    }

    return 0;
}
