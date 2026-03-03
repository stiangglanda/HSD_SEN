#include <iostream>

void Swap(int& a, int& b) {
    const int temp = a;
    a = b;
    b = temp;
}

void SortThreeDesc(int& a, int& b, int& c) {
    if (a < b) {
        Swap(a, b);
    }
    if (a < c) {
        Swap(a, c);
    }
    if (b < c) {
        Swap(b, c);
    }
}

void SortThreeAsc(int& a, int& b, int& c) {
    SortThreeDesc(a,b,c);
    Swap(a,c);
}

int main() {
    int a=1;
    int b=3;
    int c=2;
    //SortThreeDesc(a,b,c);
    SortThreeAsc(a,b,c);
    std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;

    float f=1.99;
    float g=0.000001;
    int maxIntValue=2147483647;

    std::cout << "f+g: " << f+g << " max int value: " << maxIntValue << " max int value+1: " << maxIntValue+1 << std::endl;


    return 0;
}