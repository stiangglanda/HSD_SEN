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
	unsigned int resistanceValue=0;
	vector<unsigned int> resistanceDigitVec;

	cout << "Eingabe von einem Widerstandswert in Ohm zwischen: " << rangeMin << " und " << rangeMax << endl;
	cin >> resistanceValue;

	if (resistanceValue < rangeMin || resistanceValue > rangeMax) {
		cerr << "Resistence Value is out of bounds: Min: "<<rangeMin<<", Max: "<< rangeMax << endl;
		return 1;
	}

	while(resistanceValue>0) {
		resistanceDigitVec.insert(resistanceDigitVec.begin(),resistanceValue%10);//insert so you dont need invert
		resistanceValue/=10;
	}

	for (int i=0;i<resistanceDigitVec.size();i++) {
		if (i<ringCount) {//Ring
			cout << resistorColors[resistanceDigitVec[i]];
			if (i < ringCount - 1) {//so - is not printed if there is an error in the Multiplier
				cout << "-";
			}
		}
		else {//Multiplier
			if (resistanceDigitVec[i]==0) {
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
