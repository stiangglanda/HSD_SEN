///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 21.03.2026
// Description : TestData Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "TestData.h"

int main() {
    const std::string filePath{"TestData.txt"};
    const int TestDataAmount=10;

    std::ofstream out(filePath);
    if (!out) {
        std::cerr << "Error: Could not create file" << std::endl;
        return 1;
    }
    GenerateTestData(TestDataAmount, out);
    out.close();

    std::ifstream in(filePath);
    if (!in) {
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }

    std::cout << "File contents:" << std::endl;
    PrintTestData(in);
    std::cout << std::endl;

    // Reset stream
    in.clear();
    in.seekg(0);

    int count = 0;
    Point3D* points = ScanTestData(in, count);
    in.close();

    if (points != nullptr) {
        PrintMatchingPoints(points, count);
        delete[] points;
    }

    return 0;
}