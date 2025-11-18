#include <iostream>
#include "binom.h"

int main() {
    int n=8;
    int k=3;

    int bin=Binomial(n, k);

    std::cout << "BinKoeff(n, k) = " << bin << std::endl;
    return 0;
}