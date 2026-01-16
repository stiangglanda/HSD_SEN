#include <iostream>
#include <cmath>

double CalcRoot(double a, size_t n, double xi) {
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
    std::cout << "CalcRoot: " << CalcRoot(16,2,16.0) << std::endl;
    return 0;
}