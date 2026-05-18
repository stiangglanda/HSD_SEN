#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>
#include <fstream>

using namespace std;


// Die Klasse 'Data' ermöglicht keinen Zugriff auf ihre Member, da alles 
// 'private' ist, dh es ist nicht möglich ein Objekt der Klasse anzulegen.
class Data {
  // Die Klasse 'Control' ist eine Freund-Klasse der Klasse 'Data' und hat
  // somit direkten Zugriff auf die privaten Member der Klasse 'Data'.
  // Da 'befreundete' Klassen (oder Funktionen) keine Member sind, gibt es
  // keinen Unterschied ob man sie im 'public' oder 'private' Teil deklariert.
  // Per Konvention schreibt man sie an den Klassenanfang!
	friend class Control;		

   // Die gesammte Schnittstelle der Klasse Data ist private!
	// construction & destruction
   Data()  = default;
   ~Data() = default;

	// Methoden
	void Insert(int const val) { v.push_back(val); }
	void Print(ostream& stream) const {
      assert(stream.good()); //private Funktion -> assert ausreichend!

		copy (v.begin(), v.end(), ostream_iterator<int>(stream, " "));
		stream << endl;
	}
	// Member
	std::vector<int> v;
};


class Control {
   //friend function
   friend ostream& operator << (ostream& stream, Control const& ctrl);

public:

	void Append(int const val) {
		d.Insert(val);     //Zugriff auf die private Member-Funktion in der Klasse Data
	}	

   size_t const GetSize() const
   {
      return d.v.size();
   }

private:
  //Objekt der Klasse 'Data' kann angelegt werden, da 'Control' eine Freund-Klasse
  //von 'Data' ist.
	Data d;

  //private Print-Funktion
  void Print(ostream& stream) const 
  {
     d.Print(stream);
  }
};


ostream& operator << (ostream& stream, Control const& ctrl)
{
  if (!stream.good()) { throw std::invalid_argument{"stream error"}; }
  ctrl.Print(stream);      //Zugriff auf private Print-Funktion in der Klasse 'Control'.
  return stream << endl;
}


int main () {
	//Data d;  //Erzeugen eines 'Data'-Objektes ist nicht erlaubt (alles ist 'private')
	Control c;

	c.Append(1);
	c.Append(3);
	c.Append(7);
	c.Append(-9);

   //zur Wiederholung -> mit exception handling !!!
   try {
      cout << c;

      //bewirkt exception, da die Datei nicht existiert
      fstream file{ "data.dat", ios::in };
      file << c;
   }
   catch (invalid_argument const& ex)
   {
      cerr << "invalid argument exception: " << ex.what() << endl;
      return 1;
   }
   catch (exception const& ex)
   {
      cerr << ex.what() << endl;
      return 1;
   }
   catch(...)
   {
      cerr << "unknown exception" << endl;
      return 1;
   }

	return 0;
}