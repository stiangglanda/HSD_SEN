#include <iostream>

int FindMin(int const F[], size_t const n, int i) {
    if (n==0) {
        return -1;
    }
    static int min = F[0];

    if (i<n) {
        if (F[i]<min) {
            min = F[i];
        }
    } else {
        return min;
    }

    return FindMin(F,n, i+1);
}

int FindMin(int const F[], size_t const n) {
    return FindMin(F,n,0);
}

int FindMin2(const int F[], size_t n, size_t i) {
    if (i == n - 1) {
        return F[i];
    }

    int minRest = FindMin2(F, n, i + 1);
    return (F[i] < minRest) ? F[i] : minRest;
}

int main() {
    const int n=5;
    int F[n]={2,3,5,8,9};
    std::cout << FindMin(F,n) << std::endl;
    std::cout << FindMin2(F,n,0) << std::endl;
    return 0;
}