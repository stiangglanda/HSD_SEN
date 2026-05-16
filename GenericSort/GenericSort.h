///////////////////////////////////////////////////////////////////////////
// Workfile : GenericSort.h
// Author : Leander Kieweg
// Date : 16.05.2026
// Description : GenericSort Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef GENERICSORT_H
#define GENERICSORT_H
#include <iterator>

// Returns an iterator to the first element that is not sorted according to the given predicate
template <typename TIter, typename TPred>
TIter SortedUntil(TIter begin, TIter end, TPred pred) {
    TIter prev = begin;
    TIter curr = begin;

    if (curr == end) {
        return curr;
    }

    ++curr;

    while (curr != end) {
        if (!pred(*curr, *prev)) {
            prev = curr;
            ++curr;
        } else {
            return curr;
        }
    }
    return curr;
}

// Returns an iterator to the first element that is not sorted in ascending order
template <typename TIter>
TIter SortedUntil(TIter begin, TIter end) {
    return SortedUntil(begin, end,
        std::less<typename std::iterator_traits<TIter>::value_type>{});
}

// Checks if the entire range is sorted according to the given predicate
template <typename TIter, typename TPred>
bool IsSorted(TIter begin, TIter end, TPred pred) {
    return SortedUntil(begin, end, pred) == end;
}

// Checks if the entire range is sorted in ascending order
template <typename TIter>
bool IsSorted(TIter begin, TIter end) {
    return IsSorted(begin, end,
        std::less<typename std::iterator_traits<TIter>::value_type>{});
}

// Returns an iterator indicating from where the rest of the range is sorted according to the predicate
template <typename TIter, typename TPred>
TIter SortedFrom(TIter begin, TIter end, TPred pred) {
    TIter res = begin;
    begin = SortedUntil(begin, end, pred);
    while (begin != end) {
        res = begin;
        begin = SortedUntil(begin, end, pred);
    }
    return res;
}

// Returns an iterator indicating from where the rest of the range is sorted in ascending order
template <typename TIter>
TIter SortedFrom(TIter begin, TIter end) {
    return SortedFrom(begin, end,
        std::less<typename std::iterator_traits<TIter>::value_type>{});
}

#endif
