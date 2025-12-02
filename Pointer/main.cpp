#include <iostream>

using namespace std;

int main() {
    // Adresse und Wert
    int val=4711;
    int* pval = &val;

    std::cout << "Pointer (Adresse): " << pval << std::endl;
    cout << "Inhalt (Wert) : " << *pval << endl;

    (*pval)++;

    std::cout << "Pointer (Adresse): " << pval << std::endl;
    cout << "Inhalt (Wert) : " << *pval << endl;

    pval++;

    std::cout << "Pointer (Adresse): " << pval << std::endl;
    cout << "Inhalt (Wert) : " << *pval << endl;

    *pval=7;

    std::cout << "Pointer (Adresse): " << pval << std::endl;
    cout << "Inhalt (Wert) : " << *pval << endl;

    int* ptr=nullptr;
    (*ptr)++;

    std::cout << "Pointer (Adresse): " << pval << std::endl;
    cout << "Inhalt (Wert) : " << *pval << endl;

    return 0;
}