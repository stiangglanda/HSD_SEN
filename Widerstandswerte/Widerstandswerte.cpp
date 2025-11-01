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
	const unsigned int ringCount = 2;
	const string resistorColors[] = {"schwarz", "braun",
	"rot","orange", "gelb", "grün",
	"blau", "violett", "grau", "weiß"};
	unsigned int multiplierZeroCount=0;
	unsigned int resistenceValue=0;
	vector<unsigned int> resistenceDigitVec;

	cout << "Eingabe von einem Wiederstandswert in Ohm zwischen: " << rangeMin << " und " << rangeMax << endl;
	cin >> resistenceValue;

	if (resistenceValue < rangeMin || resistenceValue > rangeMax) {
		cerr << "Resistence Value is out of bounds: Min: "<<rangeMin<<", Max: "<< rangeMax << endl;
		return 1;
	}

	while(resistenceValue>0) {
		resistenceDigitVec.insert(resistenceDigitVec.begin(),resistenceValue%10);//insert so you dont need invert
		resistenceValue/=10;
	}

	for (int i=0;i<resistenceDigitVec.size();i++) {
		if (i<ringCount) {//Ring
			cout << resistorColors[resistenceDigitVec[i]];
			if (i < ringCount - 1) {
				cout << "-";
			}
		}
		else {//Multiplier
			if (resistenceDigitVec[i]==0) {
				multiplierZeroCount++;
			}
			else {
				cerr << endl <<"ERROR Multiplikator ist Falsch"<<endl;
				return 1;
			}
		}
	}
	cout << "-" << resistorColors[multiplierZeroCount];

	return 0;
}
