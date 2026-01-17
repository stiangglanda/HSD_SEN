///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 16. 01. 2026
// Description : Recursiv square root
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>

double CalcRoot(size_t a, size_t n, double xi) {
    if (n == 0 || a == 0) {
        return 0.0;
    }
    if (xi <= 0) {
        xi = 1.0;
    }

    const double eps = 0.0001;

    double xiNext=(1.0/(n*1.0))*((n-1)*xi+(a/std::pow(xi,n-1)));

    if (std::abs(xiNext - xi)<eps) {
        return xiNext;
    }
    else {
        return CalcRoot(a,n,xiNext);
    }
}

int main() {
    std::cout << "CalcRoot: " << CalcRoot(16, 2,16.0) << std::endl;
    return 0;
}