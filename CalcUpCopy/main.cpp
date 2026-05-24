///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 23.05.2026
// Description : RingBuffer Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename TIter, typename TIter2, typename TPred>
void CalcUp_copy(TIter begin, TIter end, TIter2 resultBegin, TPred pred) {
    end--;
    while(std::distance(begin, end) >= 1)
    {
        *resultBegin++ = pred(*begin++, *end--);
    }
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 8};
    std::vector<int> vec2{ 100, 200, 300, 400 };
    std::vector<int> vecRes(3);
    std::vector<int> vecRes2(2);
    CalcUp_copy(vec.cbegin(), vec.cend(), vecRes.begin(), std::plus<int>{});
    CalcUp_copy(vec2.cbegin(), vec2.cend(), vecRes2.begin(), [](int lhs, int rhs) {
        int result = lhs-rhs;
        return result*result;
    });

    std::copy(vecRes.cbegin(), vecRes.cend(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << std::endl;
    std::copy(vecRes2.cbegin(), vecRes2.cend(), std::ostream_iterator<int>{std::cout, " "});
}