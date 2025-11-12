///////////////////////////////////////////////////////////////////////////
// Workfile : RedundancyEliminatior.cpp
// Author : Leander Kieweg
// Date : 11. 11. 2025
// Description : Converts numbers from Decimal to binary
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

void RedundancyEliminatior(int Farray[], int n)
{
	int removalCount = 0;
	int i = 0;
	int j = 0;
	bool isDuplicate = false;

	while (i < n)
	{
		j = 0;
		isDuplicate = false;
		while (j < i)
		{
			if (Farray[j] == Farray[i])
			{
				removalCount = removalCount + 1;
				isDuplicate = true;
				break;
			}
			j = j + 1;
		}
		if (!isDuplicate)
		{
			cout << Farray[i] << " ";
		}
		i = i + 1;
	}
	
	cout << endl << "Elemente gesamt: " << n - removalCount << " Redundancy removed: " << removalCount << endl;
}

int main()
{
	int Farray[] = {2, 3, 0, 2, 1, 3, 4, 7, 2, 3, 9, 3};

	RedundancyEliminatior(Farray, 12);

    return 0;
}