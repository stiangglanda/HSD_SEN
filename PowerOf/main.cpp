#include <iostream>

bool IsPowerOf(int const x, int const n) {
    if (n == 0 || x == 0) {
        return false;
    } else if (n == 1) {
        return x == 1;
    } else if (x == 1 || x == -1) {
        return true;
    } else if (x%n != 0) {
        return false;
    }

    return IsPowerOf(x/n, n);
}

int main() {
    int const x = 128;
    int const n = 2;
    std::cout << "IsPowerOf(" << x<< "," << n << "): " << std::boolalpha << IsPowerOf(x,n) << std::endl;
    return 0;
}