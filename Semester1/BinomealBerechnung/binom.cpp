// Implementierung
#include "binom.h"
#include "faculty.h"

int Binomial(int n, int k) {
    int fn=Faculty(n);
    int fk=Faculty(k);
    int fnk=Faculty(n-k);

    int res=fn/(fk*fnk);
    return res;
}