///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 16.05.2026
// Description : Test Driver for MengenOperationen
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ostream>
#include <vector>
#include "MengenOperationen.h"

int main() {
    std::vector<int> vec1{ 8, 4, 3, 2, 3, 1, 8 };
    std::vector<int> vec2{ 3, 7, 1, 6, 5, 7 };
    std::vector<int> vec3{};
    vec3.resize(vec1.size()+vec2.size());

    std::vector<int> vec4{};
    vec4.resize(vec3.size());

    std::vector<int> vec5{};
    vec5.resize(vec3.size());

    Union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
    copy(vec3.begin(), vec3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    Intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec4.begin());
    copy(vec4.begin(), vec4.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    Difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec5.begin());
    copy(vec5.begin(), vec5.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
