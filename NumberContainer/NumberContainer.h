///////////////////////////////////////////////////////////////////////////
// Workfile : NumberContainer.cpp
// Author : Leander Kieweg
// Date : 03.05.2026
// Description : NumberContainer Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef NUMBERCONTAINER_H
#define NUMBERCONTAINER_H
#include <vector>
#include <iterator>


class NumberContainer {
public:
    NumberContainer(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
    bool operator<(NumberContainer const& container) const;
    bool operator==(NumberContainer const& container) const;

    void AddRandom(size_t const count, int const start, int const end);
    int GetMax() const;
    int GetMin() const;
    std::vector<size_t> GetPositions(int val) const;
    size_t NegativeAmount() const;
    std::vector<int> GetBiggestFive() const;

private:
    std::vector<int> mNumbers;
};


#endif
