///////////////////////////////////////////////////////////////////////////
// Workfile : CalcUpCopy.h
// Author : Leander Kieweg
// Date : 23.05.2026
// Description : CalcUpCopy Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef CALCUPCOPY_H
#define CALCUPCOPY_H

template <typename TIter, typename TIter2, typename TPred>
void CalcUp_copy(TIter begin, TIter end, TIter2 resultBegin, TPred pred) {
    while(begin != end)
    {
        --end;
        if (begin == end) {
            break;
        }
        *resultBegin++ = pred(*begin++, *end);
    }
}

#endif