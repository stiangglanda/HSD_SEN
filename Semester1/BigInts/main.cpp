///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 08. 12. 2025
// Description : BigInts Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "BigInt.h"

using namespace std;


int main () {
    TNode* BigInt1;
    BigInt1 = Read();
	Write(BigInt1);
	cout << endl;

	TNode* BigInt2;
	BigInt2 = Read();
	Write(BigInt2);
	cout << endl;

	cout << endl << "Addition:" << endl;
	TNode* AddResult = Add(BigInt1, BigInt2);
	Write(AddResult);
	Delete(AddResult);

	cout << endl << "Subtraction:" << endl;
	TNode* SubResult = Subtract(BigInt1, BigInt2);
	Write(SubResult);
	Delete(SubResult);
	Delete(BigInt1);
	Delete(BigInt2);

    return 0;
}
