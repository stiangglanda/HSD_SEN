//////////////////////////////////////////////////////////////////////////////////////
// BigInt: Fragment der Funktion Read() zum Einlesen eines BigIntegers via std::string
// HSD / FH-Hagenberg, 2025
//////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "BigInt.h"
#include <string>
#include <iomanip>

using namespace std;

static TNode* Add(TNode const* const pLHS, TNode const* const pRHS, int carry)
{
    if (!pLHS && !pRHS && carry == 0)
    {
        return nullptr;
    }

    int digit1 = pLHS ? pLHS->digit : 0;
    int digit2 = pRHS ? pRHS->digit : 0;

    int result = digit1 + digit2 + carry;

    carry = result / 1000;

    TNode* prepend = new TNode();
    prepend->digit = result % 1000;

    std::cout << prepend->digit << endl;

    TNode const* nextLHS = pLHS ? pLHS->pNext : nullptr;
    TNode const* nextRHS = pRHS ? pRHS->pNext : nullptr;

    prepend->pNext = Add(nextLHS, nextRHS, carry);
	return prepend;
}

TNode* Add(TNode const* const pLHS, TNode const* const pRHS)
{
    return Add(pLHS, pRHS, 0);
}

void Delete(TNode*& pBigInt)
{
    while (pBigInt)
    {
        TNode* temp = pBigInt;
        pBigInt = pBigInt->pNext;
        std::cout << temp->digit << " deleted " << endl;
        delete temp;
	}
}

TNode * Read () {
    std::string  bigInt = "";   // Die lange Dezimalzahl.
    TNode*     pBigInt = nullptr;    // Die neue Liste.

    // Eingabe einer langen Dezimalzahl.

    std::cout << "Bitte geben Sie eine Zahl >= 0 ein: ";
    std::cin  >> bigInt;

    size_t const stelZ = bigInt.size();   // Die Anzahl der eingegebenen Stellen (zur Basis 10).

    if (stelZ > 0) {
        size_t const stelT = (stelZ - 1) / 3;       // Wieviele 'ganze' Stellen gibt es (zur Basis 1000)?
        size_t const restZ = (stelZ - 1) % 3 + 1;   // Wieviele Stellen bleiben noch �brig (zur Basis 10)?
        size_t i = 0;

        // Zerlegung der gegebenen Zahl zur Basis 10 in Ziffern zur Basis 1000.

        for (size_t t = 0; t <= stelT; ++t) {   // Durchlaufe die Ziffern (zur Basis 1000).
            size_t ziffer = 0;

            for (size_t z = 0; z < ((t == 0) ? restZ : 3); ++z) {   // Durchlaufe die Ziffern (zur Basis 10).
                ziffer = ziffer * 10 + (bigInt[i++] - '0');
            }
			TNode* prepend = new TNode();
			prepend->digit = ziffer;
			prepend->pNext = pBigInt;
            pBigInt = prepend;
            std::cout << ziffer << " created" << endl;   // Hier muss 'ziffer' mit 'prepend' in die Liste 'pBigInt' eingef�gt werden.
        }
    }

    return pBigInt;
}

static TNode* Subtract(TNode const* const pLHS, TNode const* const pRHS, int borrow)
{
    if (!pLHS)
    {
        return nullptr;
    }

    int digit1 = pLHS->digit;
    int digit2 = pRHS ? pRHS->digit : 0;

    int result = digit1 - digit2 - borrow;

    borrow = 0;
    if (result < 0) {
        result += 1000; // Borrow 1000 for the current digit.
        borrow = 1;  // Pass a borrow of 1 to the next step.
    }

    TNode* prepend = new TNode();
    prepend->digit = result;

    std::cout << prepend->digit << endl;

    TNode const* nextLHS = pLHS->pNext;
    TNode const* nextRHS = pRHS ? pRHS->pNext : nullptr;

    prepend->pNext = Subtract(nextLHS, nextRHS, borrow);

    // This part is important to remove leading zeros from the result.
    // For example, 523 - 512 = 11, not 011.
    if (prepend->pNext == nullptr && prepend->digit == 0 && (nextLHS != nullptr || nextRHS != nullptr)) {
        delete prepend;
        return nullptr;
    }


    return prepend;
}

TNode* Subtract(TNode const* const pLHS, TNode const* const pRHS)
{
    return Subtract(pLHS, pRHS,0);
}

void Write(TNode const* const pBigInt)
{
    if (pBigInt)
    {
        if (pBigInt->pNext)
        {
            Write(pBigInt->pNext);
            std::cout << std::setfill('0') << std::setw(3) << pBigInt->digit;
        }
        else
        {
            std::cout << pBigInt->digit;
        }
    }
}
