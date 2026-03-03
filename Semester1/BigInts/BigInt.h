///////////////////////////////////////////////////////////////////////////
// Workfile : BigInt.h
// Author : Leander Kieweg
// Date : 08. 12. 2025
// Description : BigInts Module Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#ifndef BIGINT_H
#define BIGINT_H

struct TNode {
    int digit; // Ziffer zur Basis 1000.
    TNode* pNext;
};

TNode* Add(TNode const * const pLHS, TNode const * const pRHS);
void Delete(TNode*& pBigInt);
TNode* Read();
TNode* Subtract(TNode const * const pLHS, TNode const * const pRHS);
void Write(TNode const * const pBigInt);

#endif