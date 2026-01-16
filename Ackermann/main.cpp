#include <iostream>

unsigned int Ackermann(unsigned int m, unsigned int n) {
    if (m == 0) {
        return n+1;
    } else if (n == 0) {
        return Ackermann(m-1, 1);
    } else {
        return Ackermann(m-1, Ackermann(m, n-1));
    }
}

int main() {
    const unsigned int m=3;
    const unsigned int n=2;
    std::cout << "Ackermann(" << m << " , " << n << "): " << Ackermann(m,n) << std::endl;
    return 0;
}