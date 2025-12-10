///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 09. 12. 2025
// Description : Memory Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

struct TDataV2 {
	double d;
	float f;
	int i;
	short s1;
	short s2;
	char c;
	bool b1;
	bool b2;
};

struct TData{
	bool b1;
	int i;
	short s1;
	double d;
	char c;
	float f;
	bool b2;
	short s2;
};

size_t const n = 3;
typedef TData TElements[n];

TElements elems = { 
	{true, 1, 9, 1.1, 'a', 1.2f, true, 2},
	{false, 2, 8, 2.2, 'b', 2.3f, true, 3},
	{true, 2, 7, 3.3, 'c', 3.4f, true, 4}
};

int main () {
	TDataV2 data = { 1.1, 1.2f, 9, 2, 1, 'a', true, true};
	cout << "Memory: elems size: " << sizeof(elems) << " TData Size: " << sizeof(elems[0]) << " TDataV2 Size: " << sizeof(data) << endl;

    return 0;
}
