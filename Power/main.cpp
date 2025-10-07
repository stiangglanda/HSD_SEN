#include <iostream>

using namespace std;

double power(int initalValue, int power)
{
    double p=1.0;

    if (initalValue == 0)
    {
        return 1;
    }

    int positive_exp = power > 0 ? power : -power;

    for (int i = 0; i < positive_exp; ++i)
    {
        p *= initalValue;
    }

    if (power<0) {
        p=1/p;
    }

    return p;
}


int main()
{
    int n=0;
    int k=0;

    cout << "Wert fuer n eingeben: ";
    cin >> n;
    cout << "Wert fuer k eingeben: ";
    cin >> k;

    cout << endl << n << " hoch " << k << " ergibt " << power(n,k) << endl;
    return 0;
}