///////////////////////////////////////////////////////////////////////////
// Workfile : MengenOperationen.h
// Author : Leander Kieweg
// Date : 03.05.2026
// Description : MengenOperationen Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef MENGENOPERATIONEN_H
#define MENGENOPERATIONEN_H
#include <iterator>
#include <algorithm>

template <typename TItor1, typename TItor2, typename TItor3>
void Union(TItor1 begin1, TItor1 end1, TItor2 begin2, TItor2 end2, TItor3 begin3) {
    TItor3 end3 = begin3;
    for (auto it = begin1; it != end1; ++it) {
        if (std::find(begin3, end3, *it) == end3) {
            *end3++ = *it;
        }
    }

    for (auto it = begin2; it != end2; ++it) {
        if (std::find(begin3, end3, *it) == end3) {
            *end3++ = *it;
        }
    }
};

template <typename TItor1, typename TItor2, typename TItor3>
void Intersection(TItor1 begin1, TItor1 end1, TItor2 begin2, TItor2 end2, TItor3 begin3) {
    TItor3 end3 = begin3;
    for (auto it = begin1; it != end1; ++it) {
        if (std::find(begin2, end2, *it) != end2 && std::find(begin3, end3, *it) == end3) {
            *end3++ = *it;
        }
    }
};

template <typename TItor1, typename TItor2, typename TItor3>
void Difference(TItor1 begin1, TItor1 end1, TItor2 begin2, TItor2 end2, TItor3 begin3) {
    TItor3 end3 = begin3;
    for (auto it = begin1; it != end1; ++it) {
        if (std::find(begin2, end2, *it) == end2 && std::find(begin3, end3, *it) == end3) {
            *end3++ = *it;
        }
    }
};

#endif
