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
    explicit IsMultipleOf(T const& multiple) : mMultiple(multiple) {}

    // Checks if the value is a multiple of the stored number
    bool operator() (T const& value) const {
        if (mMultiple == 0) {
            return value == 0;
        }
        return (value % mMultiple) == 0;
    }
private:
    T mMultiple;
};

template <typename T>
class IsPartOf {
public:
    explicit IsPartOf(T const& part) : mPart(part) {}

    // Checks if the value is a divisor of the stored number
    bool operator() (T const& value) const {
        if (value == 0) {
            return mPart == 0;
        }
        return (mPart % value) == 0;
    }
private:
    T mPart;
};

#endif
