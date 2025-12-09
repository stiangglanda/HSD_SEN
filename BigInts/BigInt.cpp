///////////////////////////////////////////////////////////////////////////
// Workfile : BigInt.cpp
// Author : Leander Kieweg
// Date : 08. 12. 2025
// Description : BigInts Module Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

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
        delete temp;
	}
	pBigInt = nullptr;
}

TNode * Read () {
    std::string bigInt = "";   // Die lange Dezimalzahl.
    TNode* pBigInt = nullptr;  // Die neue Liste.

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
        }
    }

    return pBigInt;
}

static TNode* Subtract(TNode const* const pLHS, TNode const* const pRHS, int borrow)
{
    // Wenn Links zu Ende ist (vorausgesetzt LHS >= RHS)
    if (!pLHS)
    {
        return nullptr;
    }

    int digit1 = pLHS->digit;
    int digit2 = pRHS ? pRHS->digit : 0;

    int result = digit1 - digit2 - borrow;

    borrow = 0;
    if (result < 0) {
        result += 1000; // Borrow holen
        borrow = 1;     // Borrow weitergeben
    }

    TNode const* nextLHS = pLHS->pNext;
    TNode const* nextRHS = pRHS ? pRHS->pNext : nullptr;

    TNode* tailList = Subtract(nextLHS, nextRHS, borrow);

    // Führende Nullen entfernen also kein node erstellen
    if (tailList == nullptr && result == 0) {
        return nullptr;
    }

    // andernfalls Knoten erstellen
    TNode* currentNode = new TNode();
    currentNode->digit = result;
    currentNode->pNext = tailList;

    return currentNode;
}

TNode* Subtract(TNode const* const pLHS, TNode const* const pRHS)
{
    TNode* result = Subtract(pLHS, pRHS, 0);

    if (result == nullptr) {
        result = new TNode();
        result->digit = 0;
        result->pNext = nullptr;
    }
    return result;
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
