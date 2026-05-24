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

template <typename T>
class IsMultipleOf {
public:
    IsMultipleOf(T multiple) : mMultiple(multiple) {}

    bool operator() (T value) {
        return (value % mMultiple) == 0;
    }
private:
    T mMultiple;
};

template <typename T>
class IsPartOf {
public:
    IsPartOf(T part) : mPart(part) {}

    bool operator() (T value) {
        return (mPart % value) == 0;
    }
private:
    T mPart;
};

int main()
{
    std::vector<int> vec{2,3,4,5,2,5,9,6};
    std::copy_if(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "), IsMultipleOf<int>{3});
    std::cout << std::endl;
    std::copy_if(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "), IsPartOf<int>{12});
    std::cout << std::endl;
}