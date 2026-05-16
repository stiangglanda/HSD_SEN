///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 16.05.2026
// Description : Test Driver for GenericSort
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <functional>
#include "GenericSort.h"

template <typename Container>
void PrintContainer(const Container& c) {
    std::cout << "Elements: [ ";
    copy(c.cbegin(), c.cend(), std::ostream_iterator<typename Container::value_type>(std::cout, " "));
    std::cout << "]" << std::endl;
}

template <typename Container, typename TPred = std::less<>>
void TestContainer(const std::string& name, Container& c, TPred pred = TPred{}) {
    std::cout << "--- Testing " << name << " ---" << std::endl;
    PrintContainer(c);

    // Test IsSorted
    std::cout << "IsSorted: " << IsSorted(c.begin(), c.end(), pred) << std::endl;

    // Test SortedUntil
    auto until = SortedUntil(c.begin(), c.end(), pred);
    if (until != c.end()) {
        std::cout << "SortedUntil stops at: " << *until << std::endl;
    } else {
        std::cout << "SortedUntil reached the end." << std::endl;
    }

    // Test SortedFrom
    auto from = SortedFrom(c.begin(), c.end(), pred);
    if (from != c.end()) {
        std::cout << "SortedFrom starts at: " << *from << std::endl;
    } else {
        std::cout << "SortedFrom reached the end." << std::endl;
    }
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> vec{5, 3, 5, 1, 4, 2};
    TestContainer("std::vector", vec);

    std::array<int, 6> arr{1, 2, 3, 5, 4, 2};
    TestContainer("std::array", arr);

    std::list<int> lst{1, 1, 2, 3, 4, 5};
    TestContainer("std::list", lst);

    std::forward_list<int> flst{};
    TestContainer("std::forward_list (leer)", flst);

    std::deque<int> deq{5, 4, 3, 2, 1};
    TestContainer("std::deque with custom predicate (std::greater)", deq, std::greater<>{});

    return 0;
}
