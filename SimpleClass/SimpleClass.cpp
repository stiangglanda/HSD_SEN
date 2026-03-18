#include <iostream>
#include "SimpleClass.h"

using namespace std;

//Fehlermeldungen
static string const cErrOstream = "error in Simple::Print(...)";
static string const cErrOstreamForm = "error in Simple::PrintFormated(...)";
static string const cErrWrite = "write error in Simple::PrintFormated(...)";

//ausgeben von Stream-Attributen: aktuelle Genauigkeit, 
//Fuellzeichen, Feldbreite
void Simple::OutputActStreamValues(ostream& ost) const
{
   ost << endl;
   ost << "precision=" << ost.precision() << endl;
   ost << "fill=" << ost.fill() << endl;
   ost << "width=" << ost.width() << endl;

   //und noch weitere, wenn Zeit und Interesse
   ost << "eof=" << ost.eof() << endl;
   ost << "fail=" << ost.fail() << endl;
   ost << "good=" << ost.good() << endl;
   ost << "bad=" << ost.bad() << endl;
}

