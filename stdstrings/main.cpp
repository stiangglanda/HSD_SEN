#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
    //Einlesen und ausgeben
    string name;
    cout << "Name eingeben: ";
    cin >> name;
    string ausgabe="Hallo " + name + "!";
    cout << ausgabe<<endl;

    //Zusammenfügen: + +=
    //-------------------
    string str1, str2, str3, output;
    str1 = "Eine ";
    str2 = "kurze ";
    str3 = "Textzeile";

    output=str1+str2+str3;
    cout << output << endl;
    return 0;
}