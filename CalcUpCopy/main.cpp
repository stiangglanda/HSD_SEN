///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 23.05.2026
// Description : CalcUpCopy Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <string>
#include "CalcUpCopy.h"

template<typename TCont, typename TPred>
void RunTestCase(const std::string& testName, const TCont& input, TPred op) {
    std::cout << testName << std::endl;
    std::cout << "Input: ";
    std::copy(input.cbegin(), input.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Output: ";
    CalcUp_copy(input.cbegin(), input.cend(), std::ostream_iterator<int>{std::cout, " "}, op);
    std::cout << std::endl;
}

int main()
{
    auto SquareDiff = [](int lhs, int rhs) {
        int result = lhs-rhs;
        return result*result;
    };

    RunTestCase("plus<int> (Expected: 9 7 7)", std::vector<int>{1, 2, 3, 4, 5, 8}, std::plus<int>{});
    RunTestCase("SquareDiff (Expected: 90000 10000)", std::vector<int>{100, 200, 300, 400}, SquareDiff);

    RunTestCase("minus<int>", std::vector<int>{10, 20, 5, 2}, std::minus<int>{});
    RunTestCase("multiplies<int>", std::vector<int>{2, 3, 4, 5}, std::multiplies<int>{});
    RunTestCase("divides<int>", std::vector<int>{100, 50, 10, 4}, std::divides<int>{});

    RunTestCase("Empty container", std::vector<int>{}, std::plus<int>{});
    RunTestCase("Container with 1 element", std::vector<int>{42}, std::plus<int>{});
    RunTestCase("Odd number of elements (5 elements)", std::vector<int>{1, 2, 3, 4, 5}, std::plus<int>{});

    return 0;
}
