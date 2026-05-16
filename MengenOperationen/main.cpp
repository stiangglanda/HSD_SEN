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

void runTestCase(const std::string& name, const std::vector<int>& vec1, const std::vector<int>& vec2, size_t u_size, size_t i_size, size_t d_size) {
    std::cout << "--- " << name << " ---\n";
    printVector("Container 1", vec1);
    printVector("Container 2", vec2);

    std::vector<int> u(u_size);
    std::vector<int> i(i_size);
    std::vector<int> d(d_size);

    Union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), u.begin());
    Intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), i.begin());
    Difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), d.begin());

    printVector("Union", u);
    printVector("Intersection", i);
    printVector("Difference", d);
    std::cout << std::endl;
}

int main() {
    std::vector<int> baseVec1{ 8, 4, 3, 2, 3, 1, 8 };
    std::vector<int> baseVec2{ 3, 7, 1, 6, 5, 7 };
    const size_t base_u = 8;
    const size_t base_i = 2;
    const size_t base_d = 3;
    runTestCase("Base Case", baseVec1, baseVec2, base_u, base_i, base_d);

    std::vector<int> emptyVec1{};
    std::vector<int> emptyVec2{};
    const size_t empty_both_u = 0;
    const size_t empty_both_i = 0;
    const size_t empty_both_d = 0;
    runTestCase("Beide Mengen Empty", emptyVec1, emptyVec2, empty_both_u, empty_both_i, empty_both_d);

    std::vector<int> partialVec1{ 1, 2, 3 };
    std::vector<int> partialVec2{};
    const size_t partial_u = 3;
    const size_t partial_i = 0;
    const size_t partial_d = 3;
    runTestCase("Eine Menge Empty", partialVec1, partialVec2, partial_u, partial_i, partial_d);

    std::vector<int> idVec1{ 1, 2, 3 };
    std::vector<int> idVec2{ 1, 2, 3 };
    const size_t id_u = 3;
    const size_t id_i = 3;
    const size_t id_d = 0;
    runTestCase("Identische Mengen", idVec1, idVec2, id_u, id_i, id_d);

    std::vector<int> disVec1{ 1, 2, 3 };
    std::vector<int> disVec2{ 4, 5, 6 };
    const size_t dis_u = 6;
    const size_t dis_i = 0;
    const size_t dis_d = 3;
    runTestCase("Verschiedene Mengen", disVec1, disVec2, dis_u, dis_i, dis_d);

    return 0;
}
