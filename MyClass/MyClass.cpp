#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#if defined(_WIN32) || defined(_WIN64)
#include <vld.h> // Visual Leak Detector (Windows only)
#endif
using namespace std;

//Konstanten
static string const cFileName = "out.txt";
static string const cErrOpen = "error open file: ";
static string const cErrOstream = "error in MyClass::Print(..) ";
static string const cErrWrite = "error in MyClass::Print(..) -> Write";

//Klasse wird direkt implementiert: keine Trennung in Header und Implementierung
class MyClass
{
public:
   //CTor
   MyClass()
   {
      cout << "ctor: objekt initialisieren." << endl;
      mValues = new int[cLEN];
      mStr = "hallo";
   }
   
   //DTor
   ~MyClass()
   {
      cout << "DTor: Objekt abbauen." << endl;
      delete []mValues;
   }

   
   //Ausgabe der Daten
   //TO DO: Umbau der Print-Funktion auf eine allgemeine Variante mit std::ostream
   void Print(std::ostream& ost)
   {
      if (!ost.good()) {
         cerr << cErrOstream << endl;
         return;
      }
      cout << "val: " << mValues << " size=" << sizeof(mValues) << endl;
      cout << "str: " << mStr << " size=" << sizeof(mStr) << endl; 
      cout << "Mit this-Pointer: " << this->mStr << endl;
      cout << "Groesze eines Objektes: " << sizeof(MyClass) << endl;
      cout << "Groesze eines Objektes (this): " << sizeof(this) << endl;
      cout << "Groesze eines Objektes (*this): " << sizeof(*this) << endl;

      if (ost.fail()) {
         cerr << cErrWrite << endl;
         return;
      }
   }

private:
   //Daten
   size_t const cLEN = 6;
   int* mValues;
   string mStr;
};


int main()
{
   //1 Objekt am Stack anlegen:
   {
      MyClass myObj; //CTor wird aufgerufen
      myObj.Print(std::cout);
   } //Zerst�rung des am Stack angelegten Objektes -> DTor wird aufgerufen
   
   //1 Objekt dynamisch (am Heap) anlegen:
   MyClass* pMyObj = nullptr;
   pMyObj = new MyClass;

   cout.setstate(ios::failbit);
   (*pMyObj).Print(std::cout);
   cout.clear();

   //TO DO
   //Print mit verschiedenen Datenstroemen aufrufen
   ofstream file{cFileName};
   if (file.is_open()) {
      pMyObj->Print(file);
      file.close();
   }
   else {
      cerr << cErrOpen << endl;
   }

   ostringstream strStream;
   pMyObj->Print(strStream);
   string const res = strStream.str();
   cout << endl << res << endl;

   //dynamisches Objekt (am Heap) freigeben
   delete pMyObj; pMyObj = nullptr;
   
   return 0;
}