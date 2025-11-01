// Widerstandswerte.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	const unsigned int rangeMin = 10;
	const unsigned int rangeMax = 5000000;
	const unsigned int RingCount = 2;
	unsigned int multiplikatorZeroCount=0;
	string ResistenceColors[] = {"schwarz", "braun",
		"rot","orange", "gelb", "grün",
		"blau", "violett", "grau", "weiß"};
	unsigned int ResistenceValue=0;
	vector<int> ResistorRingsVec;

	cout << "Enter the Resistence Value in Ohm between Min: "<<rangeMin<<" and Max: "<<rangeMax << endl;
	cin >> ResistenceValue;

	if (ResistenceValue < rangeMin || ResistenceValue > rangeMax) {
		cout << "Resistence Value is out of bounds: Min: "<<rangeMin<<", Max: "<< rangeMax << endl;
		return 1;
	}

	while(ResistenceValue>0) {
		ResistorRingsVec.insert(ResistorRingsVec.begin(),ResistenceValue%10);//insert so you dont need invert
		ResistenceValue/=10;
	}

	for (int i=0;i<ResistorRingsVec.size();i++) {
		if (i<RingCount) {//Ring
			cout << ResistenceColors[ResistorRingsVec[i]];
			if (i < RingCount - 1) { // Nur nach dem ersten Ring einen Bindestrich setzen
				cout << "-";
			}
		}
		else {//Multiplikator
			if (ResistorRingsVec[i]==0) {
				multiplikatorZeroCount++;
			}
			else {
				cout << endl <<"ERROR Multiplikator is wrong"<<endl;
				return 1;
			}
		}
	}
	cout << "-" << ResistenceColors[multiplikatorZeroCount];

	return 0;
}
