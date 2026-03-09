#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

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

   //to do

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


   // Textdatei kopieren - Datei wird Zeichen fuer Zeichen gelesen
   // Die Datei wird geoeffnet und gelesen, indem ein Eingabe-Dateistrom erzeugt wird.
   ifstream infile(cFileNameText);
   ofstream outfile(cFileNameDupText);

   // to do
}
