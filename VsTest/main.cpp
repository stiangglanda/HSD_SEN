#include <iostream>

using namespace std;

int main() {
    int a=8;
    // Struktur
    struct TData {
        char ch;
        int val;
        double d;
    };

    TData data={'A', 2, 3.14};

    //Feld
    int array[]={1, 2, 3, 4, 5};

    //Feld mit Struktur
    TData dataArray[]={'A', 1, 1.1, 'B', 2, 2.2};
    struct TCombined {
        TData dat[2];
        int arr[5];
    };

    TCombined c={
        'a', 1, 1.1,
        'b', 2, 2.2,
        1,2,3,4,5
    };

    cout << c.dat[0].ch << endl; // 'a'
    cout << c.dat[0].val << endl; // 1

    string str="Hello World!";

    return 0;
}