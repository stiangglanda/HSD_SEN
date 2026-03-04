// --------------------
// Project Header Files
// --------------------
#include <iostream>

//Einbinden des Moduls fstream aus der Standardbibliothek
#include <fstream>

//Einbinden des Moduls pfc_scanner
#include "scanner.h"

//Der Namensraum des Scanners wird geoeffnet
using namespace pfc;

using namespace std;


int main() 
{
   string const fileName = "../Input.txt";

   //Anlegen einer bestehenden Input-Datei aus der gelesen wird
	ifstream file(fileName);

   //Pruefen der Datei
   if (!file.is_open())
   {
      cerr << "can't open file " << fileName << endl;
      return 1;
   }

   //der Scanner wirft im Fehlerfall eine Exception -> try-catch-block
   try
   {
      //Anlegen des Scanners mit gleichzeitigem Lesen des Eingabestromes in 
      //einen internen Puffer. Das erste Symbol wird gescannt.
      scanner scan(file);

      //Pruefe, ob der Scanner noch Symbole liefern kann.
      while (scan.has_symbol()) {

         //Holen des aktuellen Symbols
         symbol sym = scan.current_symbol();

         //Pruefen auf ein bestimmtes Symbol
         if (sym.is('=')) {
            cout << "Assign\n";
         }
         else if (sym.is(':')) {
            cout << "Colon\n";
         }
         else if (sym.is(',')) {
            cout << "Comma\n";
         }
         else if (sym.is('/')) {
            cout << "Division\n";
         }
         else if (sym.is('(')) {
            cout << "LPar\n";
         }
         else if (sym.is('-')) {
            cout << "Minus\n";
         }
         else if (sym.is('*')) {
            cout << "Multiply\n";
         }
         else if (sym.is('.')) {
            cout << "Period\n";
         }
         else if (sym.is('+')) {
            cout << "Plus\n";
         }
         else if (sym.is('^')) {
            cout << "Power\n";
         }
         else if (sym.is(')')) {
            cout << "RPar\n";
         }
         else if (sym.is(';')) {
            cout << "Semicolon\n";
         }
         else if (sym.is('&')) {
            cout << "And\n";
         }
         else if (sym.is('|')) {
            cout << "Or\n";
         }
         else if (sym.is('@')) {
            cout << "At\n";
         }
         //pruefen auf eine bestimmte Symbolklasse
         else if (sym.is_identifier()) {
            string const v = sym.get_identifier();
            cout << "Identifier(" << v << ")" << endl;
         }
         else if (sym.is_integer()) {
            int const v = sym.get_integer();
            cout << "Integer(" << v << ")" << endl;
         }
         else if (sym.is_real()) {
            double const v = sym.get_real();
            cout << "Real(" << v << ")" << endl;
         }
         else if (sym.is_string()) {
            string const v = sym.get_string();
            cout << "String(" << v << ")" << endl;
         }

         //Symbol in seiner internen Darstellung direkt auf den 
         //Ausgabestrom schreiben
         cout << sym << endl << endl;

         //Weiterschalten auf das naechste Symbol
         scan.next_symbol();
      }

   }
   //hier werden die Exceptions des Scanners gefangen und eine 
   //Fehlermeldung ausgegeben
   catch(exception const& ex)
   {
      cerr << "Error: " << ex.what() << endl;
      file.close();
      return 1;
   }

   //Schlieszen der geoeffneten Datei
   file.close();

   return 0;
}

