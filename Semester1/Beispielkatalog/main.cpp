///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 21. 01. 2026
// Description : Beispielkatalog
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int EindimensionalesFeld(int arr[], size_t n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == sum - arr[i]) {
			return arr[i];
		}
	}
	return 0;
}

void PrintValuesBetween(int arr[], size_t n, int min, int max)
{
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (arr[i] == arr[j]) {
				count++;
			}
		}
		if (count <= max && count >= min) {
			cout << arr[i] << " ";
		}
		count = 0;
	}
}

int RemoveElement(int arr[], size_t n, int limit)
{
	int removedCnt = 0;
	for (int i = 0; i < n - removedCnt; ) {
		if (arr[i] < limit)
		{
			for (int j = i; j < n-1; j++) {
				arr[j] = arr[j + 1];
			}
			removedCnt++;
		}
		else
		{
			i++;
		}
	}
	return n - removedCnt;
}

int main () {

	cout << "Firstname classification Input: " << endl;


    return 0;
}
