// Implementierung
#include "binom.h"

int Binomial(int n, int k) {
    int fn=Faculty(n);
    int fk=Faculty(k);
    int fnk=Faculty(n-k);

    int res=fn/(fk*fnk);
    return res;
}

int Faculty(int x) {
    int f=1;

    for (int i=2; i<=x; i++) {
        f *= i;
    }
    return f;
}