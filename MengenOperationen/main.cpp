///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 16.05.2026
// Description : Test Driver for MengenOperationen
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include "MengenOperationen.h"

void printVector(const std::string& prefix, const std::vector<int>& vec) {
    std::cout << prefix << ": ";
    copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec1{ 8, 4, 3, 2, 3, 1, 8 };
    std::vector<int> vec2{ 3, 7, 1, 6, 5, 7 };

    printVector("Container 1", vec1);
    printVector("Container 2", vec2);
    std::cout << std::endl;

    const size_t Union_size = 8; // Exact size for Union
    const size_t Intersection_size = 2; // Exact size for Intersection
    const size_t Difference_size = 3; // Exact size for Difference

    // Pre-allocate exact required sizes since the functions return void
    std::vector<int> vec3(Union_size);
    std::vector<int> vec4(Intersection_size);
    std::vector<int> vec5(Difference_size);

    Union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
    printVector("Union", vec3);

    Intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec4.begin());
    printVector("Intersection", vec4);

    Difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec5.begin());
    printVector("Difference", vec5);

    return 0;
}
