///////////////////////////////////////////////////////////////////////////
// Workfile : GenericFunctors.h
// Author : Leander Kieweg
// Date : 23.05.2026
// Description : GenericFunctors Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef GENERICFUNCTORS_H
#define GENERICFUNCTORS_H

template <typename T>
class IsMultipleOf {
public:
    explicit IsMultipleOf(T multiple) : mMultiple(multiple) {}

    bool operator() (T value) const {
        return (value % mMultiple) == 0;
    }
private:
    T mMultiple;
};

template <typename T>
class IsPartOf {
public:
    explicit IsPartOf(T part) : mPart(part) {}

    bool operator() (T value) const {
        if (value == 0) {
            return false;
        }
        return (mPart % value) == 0;
    }
private:
    T mPart;
};

#endif
