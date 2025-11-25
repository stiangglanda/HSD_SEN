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

    output=output+" von ";
    output+="Maxi.";
    cout << output << endl;

    // Laenge einer Zeichenkette
    // -------------------------
    size_t len = output.size();// = length()
    cout << "Stringlaenge: " << len << endl;

    // String leeren
    // -------------

    output.erase(); // oder: output = "";
    len = output.size();// = length()
    cout << "Stringlaenge: " << len << endl;

    // Vergleich (case sensitive)
    // --------------------------
    if (str3=="Textzeile") {        //analog mit Operator !=
        cout << "identisch" << endl;
    }
    else {
        cout << "Verschieden" << endl;
    }

    // Initialisierung
    // ---------------
    string str=""; //Leerstring
    string fiveStars(5,'*'); //Initialisierung mit 5 Sternen
    cout << fiveStars << endl;

    // indizierter Zugriff mit []
    // --------------------------
    str = "Hallo";
    len = str.size();

    //Range: str[0]..str[len-1]     .. wie bei Feldern
    char ch = str[0]; // ch='H'
    for (size_t i = 0; i < len; i++) { // kompletten string zeichenweise ausgeben
        cout << str[i];
    }
    cout << endl;
    str[0]='R';
    str[1]='o';
    cout << str << endl; // "Rollo"

    // Hinweis: Mit dem Indizierungsoperator [] lassen sich keine zusaetzlichen Zeichen
    //          hinten am String anfuegen! Dafuer ist insert, + oder += zu verwenden!

    // Teilstring ermitteln
    // --------------------
    string s="A Test String.";
    string sub=s.substr(2,4); // substr(Position, Anzahl Zeichen)
    cout << "Substring: " << sub << endl; // "Test"

    // Ersetzen eines Teilbereichs im String
    // -------------------------------------
    s.replace(2,4,"simple");    // replace(Position, Anzahl Zeichen, neuer String)
    cout << s << endl;

    // Einfuegen
    // ---------
    s.insert(9,"C++"); // insert(Position, string)
    cout << s << endl;

    // Suchen im String
    // ----------------
    size_t pos = s.find("C++", 0);  //find(substring, Startposition)

    if (pos==s.npos) {
        cout << "nicht enthalten" << endl;
    }
    else {
        cout << "Gefunden an Index " << pos << endl;
    }

    // rueckwerts suchen
    // -----------------
    pos = s.rfind("C++", s.npos);   // rfind(substring, Startposition von hinten)
    cout << "Gefunden an Index " << pos << endl;

    // Zahl in Zeichenketten konvertieren (inkl. Vorzeichen)
    // -----------------------------------------------------
    int ival=-123;
    string si=to_string(ival); // "-123" als Zeichenkette
    cout << si << endl;

    double dval = 3.1415927;    // "3.141593" gerundet!
    string sd=to_string(dval);
    cout << sd << endl;

    // todo next week


    return 0;
}