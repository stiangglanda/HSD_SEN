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

int main()
{
    std::vector<int> vec{2,3,4,5,2,5,9,6};
    std::copy_if(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "), IsMultipleOf<int>{3});
    std::cout << std::endl;
    std::copy_if(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "), IsPartOf<int>{12});
    std::cout << std::endl;
}