///////////////////////////////////////////////////////////////////////////
// Workfile : NumberContainer.cpp
// Author : Leander Kieweg
// Date : 03.05.2026
// Description : NumberContainer Implementaion
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "NumberContainer.h"
#include <numeric>
#include <algorithm>
#include <random>
#include <stdexcept>

static const std::string cErrRandom = "start must be <= end";
static const std::string cErrContEmpty = "Container is empty";
static const std::string cErrBigFive = "NumberContainer doesn't have at least 5 numbers";

static const size_t cBiggestFiveCount = 5;

bool NumberContainer::operator<(NumberContainer const &container) const {
    int sum1 = std::accumulate(mNumbers.cbegin(), mNumbers.cend(), 0);
    int sum2 = std::accumulate(container.mNumbers.cbegin(), container.mNumbers.cend(), 0);
    return sum1 < sum2;
}

bool NumberContainer::operator==(NumberContainer const &container) const {
    int sum1 = std::accumulate(mNumbers.cbegin(), mNumbers.cend(), 0);
    int sum2 = std::accumulate(container.mNumbers.cbegin(), container.mNumbers.cend(), 0);
    return sum1 == sum2;
}

void NumberContainer::AddRandom(size_t const count, int const start, int const end) {
    if (start > end) {
        throw std::invalid_argument(cErrRandom);
    }

    static std::mt19937 engine{std::random_device{}()};
    std::uniform_int_distribution<int> dist(start, end);

    mNumbers.reserve(mNumbers.size() + count);
    std::generate_n(std::back_inserter(mNumbers), count, [&] {
        return dist(engine);
    });
}

int NumberContainer::GetMax() const {
    if (mNumbers.empty()) {
        throw std::logic_error(cErrContEmpty);
    }
    return *std::max_element(mNumbers.cbegin(), mNumbers.cend());
}

int NumberContainer::GetMin() const {
    if (mNumbers.empty()) {
        throw std::logic_error(cErrContEmpty);
    }
    return *std::min_element(mNumbers.cbegin(), mNumbers.cend());
}

std::vector<size_t> NumberContainer::GetPositions(int val) const {
    std::vector<size_t> result;
    auto it = mNumbers.cbegin();

    while ((it = std::find(it, mNumbers.cend(), val)) != mNumbers.cend()) {
        result.push_back(std::distance(mNumbers.cbegin(), it));
        ++it;
    }

    return result;
}

size_t NumberContainer::NegativeAmount() const {
    return std::count_if(mNumbers.cbegin(), mNumbers.cend(), [](int i) { return i < 0; });
}

std::vector<int> NumberContainer::GetBiggestFive() const {
    if (mNumbers.size() < cBiggestFiveCount ) {
        throw std::invalid_argument(cErrBigFive);
    }

    std::vector<int> result(cBiggestFiveCount);

    std::partial_sort_copy(mNumbers.cbegin(), mNumbers.cend(),
                           result.begin(), result.end(),
                           std::greater<int>());

    return result;
}
