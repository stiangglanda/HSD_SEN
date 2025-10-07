#include <iostream>

using namespace std;

int power(int initalValue, int power)
{
    int p=1;

    for (int i = 1; i <= power; i++)
    {
        p*=initalValue;
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