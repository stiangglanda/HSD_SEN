///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 16. 01. 2026
// Description : BinarySearch
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>

int BinSearch(int F[], size_t n, int x) {
    int first = 0;
    int last = n - 1;
    int m=0;

   while (first <= last) {
       m = (first + last) / 2;
       if (x == F[m]) {
           return m;
       }
       else if (x < F[m]) {
           last = m - 1;
       }
       else {
           first = m + 1;
       }
   }

    return -1;
}

int main() {
    const unsigned int n=10;
    int F[n]={0,1,2,3,4,5,6,7,8,9};
    std::cout << "BinSearch: " << BinSearch(F, n, 9) << std::endl;
    return 0;
}