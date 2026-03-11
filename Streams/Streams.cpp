#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <format>

using namespace std;

// Konstanten fuer Fehlermeldungen
static string const cErrOpenFile = "error open file";
static string const cErrReadFile = "error read file";
static string const cErrWriteFile = "error write file";
static string const cErrBinCopy = "error binary copy";
static string const cErrTextCopy = "error text copy";

// Konstanten fuer Dateinamen
static string const cFilenameBinIn = "../ErgaenzungEBNF.pdf";
static string const cFilenameBinOut = "dup_ErgaenzungEBNF.pdf";
static string const cFileNameText = "../File.txt";
static string const cFileNameDupText = "Duplicate.txt";


// Prueft, ob die Dateistreame korrekt sind
static bool CheckFiles(ifstream const& inFile, ofstream const& outFile, string const& errorText)
{
   // Prueft, ob der Eingabe- und Ausgabedatenstrom in einem gueltigen Zustand sind
   if (!inFile.good() || !outFile.good())
   {
      cerr << errorText << endl;
      return false;
   }
   return true;
}

// Prueft einen Ausgabedatenstrom auf Schreibfehler
static bool CheckOutFile(ofstream& outfile)
{
   // Prueft, ob der Ausgabedatenstrom einen Fehler hat (write error)
   if (outfile.fail())
   {
      cerr << cErrWriteFile << endl;
      outfile.close();
      return false;
   }
   return true;
}

// Prueft einen Eingabedatenstrom auf Lesefehler
static bool CheckInFile(ifstream& infile)
{
   // Prueft, ob die Datei nicht Dateiende ist, aber einen Fehler hat (read error)
   if (!infile.eof() && infile.fail())
   {
      cerr << cErrReadFile << endl;
      infile.close();
      return false;
   }
   return true;
}


//herkoemmliche einfache Konvertierung mit stringstreams
//Konvertierungen auch mit stoi, stol, stod, ... oder mit string_to(...) moeglich
static void ConvertWithStreams()
{
   stringstream converter; //oder auch ostringstream bzw. istringstream
   string line;

   cout << endl << endl << "enter double value: ";
   getline(cin,line); // liest eine Zeile direkt von der Eingabe

   converter << line << endl;
   double d = 0.0;
   converter >> d;
   d *= 2;
   cout << "Double: " << d << endl;

   //back to string -> stringstream leeren
   //variante 1
   converter.str("");
   converter.clear(); //EOF-Flag loeschen
   converter << d;
   string res = converter.str(); // liefert wieder einen string
   cout << res << endl;

   // variante 2
   stringstream{}.swap(converter);
   converter << "complicated string" << 4711 << ": " << d << ", "
   << "float: " << 47.11f;
   cout << converter.str();
}

//formatieren mit std::format aus C++20
static void Format() {
   string const name = "John Wick";
   int const age = 25;

   //{} ist ein Platzhalter fuer eine Variable
   string res = format("Name: {}, Alter: {}\n", name, age);
   cout << res;

   float const val = 3.1415f;
   cout << format("float -> {:.3f}\n", val);

   //Fuellzeichen
   cout << format("float -> {:*<20.2f}\n", val);
   cout << format("float -> {:*>20.2f}\n", val);
   cout << format("float -> {:*^20.2f}\n", val);

   cout << format("binaer: {1:b}, {0:b}\n", 255, 1024); //{index:binaer}
   cout << format("hex: {1:x}, {0:x}\n", 255, 1024);
   cout << format("okt: {1:o}, {0:o}\n", 255, 1024);
   cout << format("okt: {1:d}, {0:d}\n", 255, 1024);
   cout << format("exp: {1:e}, {0:E}\n", 255.255, 1024.1024);
}

int main()
{
   // Binaere Datei kopieren: "binaer" bedeutet, dass keine Umwandlung von 
   // verschiedenen Zeilenenden vorgenommen wird!
   // Dieser Modus ist notwendig, um den Inhalt einer binaeren Datei genau zu erhalten.
   // Die Dateistreame werden mit rdbuf() fuer eine effiziente Kopie genutzt.
   ifstream binIn(cFilenameBinIn, ios::binary);   // Oeffnet die Eingabedatei im binaeren Modus
   ofstream binOut(cFilenameBinOut, ios::binary); // Oeffnet die Ausgabedatei im binaeren Modus

   // to do

   if (CheckFiles(binIn, binOut, cErrBinCopy)) {
      binOut << binIn.rdbuf(); // kopiert die Daten direkt aus dem Datenpuffer und schreibt diese auf binOut

      if (!CheckInFile(binIn)) {
         binOut.close();
         return 1;
      }

      string const cBuffer = "********END OF FILE*********";
      //binOut.seekp(100);

      //Variante 1
      //binOut.seekp(0);
      //Variante 2
      //binOut.seekp(-10, ios::beg);
      //Variante 3
      binOut.seekp(100,ios::end);
      // schreiben mit der write-Funktion
      binOut.write(cBuffer.c_str(), cBuffer.size());

      if (!CheckOutFile(binOut)) {
         binIn.close();
         return 1;
      }

      //Dateigroesse bestimmen
      binOut.seekp(0,ios::end); //->Dateiende
      cout << "Groesse: " << binOut.tellp() << " Bytes" << endl;
      binIn.seekg(0,ios::end); //->Dateiende
      cout << "Groesse: " << binIn.tellg() << " Bytes" << endl;

      binIn.close();
      binOut.close();
   }

   // Textdatei kopieren - Datei wird Zeichen fuer Zeichen gelesen
   // Die Datei wird geoeffnet und gelesen, indem ein Eingabe-Dateistrom erzeugt wird.
   ifstream infile(cFileNameText);
   ofstream outfile(cFileNameDupText);

   // to do
   if (CheckFiles(infile, outfile, cErrTextCopy)) {
      char ch = -1;
      while (outfile.good() && infile.get(ch)) {
         cout << ch;
         outfile.put(ch);
         outfile << '_';
      }

      //Lesefehler pruefen
      if (!CheckInFile(infile)) {
         outfile.close();
         return 1;
      }

      //Schreibfehler pruefen
      if (!CheckOutFile(outfile)) {
         infile.close();
         return 1;
      }

      outfile.close();
      infile.close();
   }

   outfile.open(cFileNameDupText, ios::app);
   if (outfile.is_open()) {
      outfile.seekp(0,ios::beg);
      outfile << "hansi" << endl;

      outfile.seekp(10,ios::beg);
      outfile << "erich" << endl;

      //Schreibfehler pruefen
      if (!CheckOutFile(outfile)) {
         return 1;
      }
      outfile.close();
      cout << endl;
   }
   else {
      cerr << cErrOpenFile << endl;
   }

   infile.open(cFileNameDupText);

   if (infile.is_open()) {
      string inStr;
      while (infile >> inStr) { //Leerzeichen werden uebersprungen
         cout << inStr << endl;
      }
      if (!CheckInFile(infile)) {
         return 1;
      }
      infile.close();
      cout << endl;
   } else {
      cerr << cErrOpenFile << endl;
   }

   ConvertWithStreams();
   Format();
}
