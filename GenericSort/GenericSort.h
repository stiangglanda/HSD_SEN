///////////////////////////////////////////////////////////////////////////
// Workfile : GenericSort.h
// Author : Leander Kieweg
// Date : 03.05.2026
// Description : GenericSort Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef GENERICSORT_H
#define GENERICSORT_H
#include <iterator>

template <typename TIter, typename TPred>
TIter SortedUntil(TIter begin, TIter end, TPred pred) {
    TIter prev = begin;
    TIter curr = begin;

    if (curr == end) {
        return curr;
    }

    ++curr;

    while (curr != end) {
        if (pred(*prev, *curr)) {
            prev = curr;
            ++curr;
        } else {
            return curr;
        }
    }
    return curr;
}

template <typename TIter>
TIter SortedUntil(TIter begin, TIter end) {
    return SortedUntil(begin, end,
        std::less<typename std::iterator_traits<TIter>::value_type>{});
}

template <typename TIter, typename TPred>
bool isSorted(TIter begin, TIter end, TPred pred) {
    return SortedUntil(begin, end, pred) == end;
}

template <typename TIter>
bool isSorted(TIter begin, TIter end) {
    return isSorted(begin, end,
        std::less<typename std::iterator_traits<TIter>::value_type>{});
}

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

template <typename TIter>
TIter SortedFrom(TIter begin, TIter end) {
    return SortedFrom(begin, end,
        std::less<typename std::iterator_traits<TIter>::value_type>{});
}


#endif
