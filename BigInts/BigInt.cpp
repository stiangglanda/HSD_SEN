//////////////////////////////////////////////////////////////////////////////////////
// BigInt: Fragment der Funktion Read() zum Einlesen eines BigIntegers via std::string
// HSD / FH-Hagenberg, 2025
//////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>


struct TNode {
    int     digit;   // Ziffer zur Basis 1000.
    TNode * pNext;
};

TNode * Read () {
    std::string  bigInt = "";   // Die lange Dezimalzahl.
    TNode *     pBigInt = 0;    // Die neue Liste.

    // Eingabe einer langen Dezimalzahl.

    std::cout << "Bitte geben Sie eine Zahl >= 0 ein: ";
    std::cin  >> bigInt;

    size_t const stelZ = bigInt.size ();   // Die Anzahl der eingegebenen Stellen (zur Basis 10).

    if (stelZ > 0) {
        size_t const stelT = (stelZ - 1) / 3;       // Wieviele 'ganze' Stellen gibt es (zur Basis 1000)?
        size_t const restZ = (stelZ - 1) % 3 + 1;   // Wieviele Stellen bleiben noch �brig (zur Basis 10)?
        size_t       i     = 0;

        //    Zerlegung der gegebenen Zahl zur Basis 10 in Ziffern zur Basis 1000.

        for (size_t t = 0; t <= stelT; ++t) {   // Durchlaufe die Ziffern (zur Basis 1000).
            size_t ziffer = 0;

            for (size_t z = 0; z < ((t == 0) ? restZ : 3); ++z) {   // Durchlaufe die Ziffern (zur Basis 10).
                ziffer = ziffer * 10 + (bigInt[i++] - '0');
            }

            std::cout << ziffer << std::endl;   // Hier muss 'ziffer' mit 'prepend' in die Liste 'pBigInt' eingef�gt werden.
        }
    }

    return pBigInt;
}