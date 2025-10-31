// Widerstandswerte.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	const unsigned int RingCount = 2;
	string ResistenceColors[] = {"schwarz", "braun",
		"rot","orange", "gelb", "grün",
		"blau", "violett", "grau", "weiß"};
	unsigned int ResistenceValue=0;
	vector<int> ResistorRingsVec;

	cout << "Enter the Resistence Value in Ohm:" << endl;
	cin >> ResistenceValue;

	while(ResistenceValue>0) {
		ResistorRingsVec.insert(ResistorRingsVec.begin(),ResistenceValue%10);//insert so you dont need invert
		ResistenceValue/=10;
	}

	for (int i=0;i<ResistorRingsVec.size();i++) {
		if (i<RingCount) {//Ring
			cout << ResistenceColors[ResistorRingsVec[i]]<<"-";
		}
		else {//Multiplikator
			cout << ResistenceColors[ResistorRingsVec.size()-RingCount];
			return 0;
		}
	}

	// if we havent reched the minimum rings
	for (int i=0;i<RingCount+1-ResistorRingsVec.size();i++) {//the plus 1 is the multiplikator
		cout << ResistenceColors[0];
		if (i<RingCount-ResistorRingsVec.size()) {
			cout << "-";
		}
	}

	return 0;
}
