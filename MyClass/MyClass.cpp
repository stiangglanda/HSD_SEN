#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vld.h>
using namespace std;

//Konstanten
static string const cFileName = "out.txt";
static string const cErrOpen = "error open file: ";

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
   void Print()
   {
      cout << "val: " << mValues << " size=" << sizeof(mValues) << endl;
      cout << "str: " << mStr << " size=" << sizeof(mStr) << endl; 
      cout << "Mit this-Pointer: " << this->mStr << endl;
      cout << "Groesze eines Objektes: " << sizeof(MyClass) << endl;
      cout << "Groesze eines Objektes (this): " << sizeof(this) << endl;
      cout << "Groesze eines Objektes (*this): " << sizeof(*this) << endl;
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
      myObj.Print();
   } //Zerstörung des am Stack angelegten Objektes -> DTor wird aufgerufen
   
   //1 Objekt dynamisch (am Heap) anlegen:
   MyClass* pMyObj = nullptr;
   pMyObj = new MyClass;
   
   pMyObj->Print();
   (*pMyObj).Print();

   //TO DO
   //Print mit verschiedenen Datenstroemen aufrufen

   //dynamisches Objekt (am Heap) freigeben
   delete pMyObj; pMyObj = nullptr;
   
   return 0;
}