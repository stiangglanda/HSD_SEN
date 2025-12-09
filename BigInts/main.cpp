///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 08. 12. 2025
// Description : BigInts
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "BigInt.h"

using namespace std;


int main () {
    TNode* BigInt;
    BigInt = Read();
	Write(BigInt);


	cout << "Addition:" << endl;
	TNode* Result = Add(BigInt, BigInt);
	cout << "Addition2:" << endl;
	Write(Result);
	Delete(Result);
	cout << "Subtraction:" << endl;
	Result = Subtract(BigInt, BigInt);
	Write(Result);
	cout << "Deletion of Result:" << endl;
	Delete(Result);
	Delete(BigInt);

    return 0;
}
