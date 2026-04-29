#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <array>
#include <cassert>
#include <iterator>
using namespace std;

short const cLEN = 5;

//Typdefinitionen
using TList = list<int>;
using TVect = vector<int> ;
using TArr  = array<int, cLEN> ;
using TCVItor = TVect::const_iterator;

//Print mit typgebundenen Iteratoren
static void Print(TCVItor first, TCVItor last, string const& text, ostream& ost = cout) {
   assert(ost.good() && !text.empty());

   ost << endl << text << endl;
   copy(first, last, ostream_iterator<TCVItor::value_type>(ost, " "));
   ost << endl;
}

//Generisches Print mit Iteratoren als Parameter
template<typename TItor>
static void Print(TItor first, TItor last, string const& text, ostream& ost = cout) {
   assert(ost.good() && !text.empty());

   ost << endl << text << endl;
   //copy(first, last, ostream_iterator<typename TItor::value_type>(ost, " "));
   copy(first, last, ostream_iterator<typename iterator_traits<TItor>::value_type>(ost, " "));
   ost << endl;
}

//Einstelliges Predikat
static bool FindEq3(int const val) {
   return val == 3;
}

//Generischer Algorithmus -> aufgebaut wie ein STL-Algo
//flexible Suchfunktion fuer Container anhand eines Templates
template<typename TItor, typename Pred>
static TItor searchX(TItor first, TItor last, Pred p) {
   while (first != last && !p(*first)) {
      ++first;
   }

   return first;
}

//Generische Funktion zur Ausgabe
template<typename TItor>
static void PrintFound(TItor found, TItor end) {
   cout << "elem " << (found != end ? "found" : "not found") << endl;
}

//oder ab C++20 -> Abbreviated Function Template (verkuerztes Funktionstemplate)
//mit auto-Parameter wie bei einer Lambda7
//->ist nur syntactic sugar -> der Compiler erstellt automatisch ein Template
static void PrintFound(auto val, auto end) {
   cout << "elem " << (val != end ? "found" : "not found") << endl;
}

int main()
{
   try {
      int arr[cLEN] = { 1, 2, 3, 4, 5 };
      TList l{ arr, arr + cLEN };
      TVect v{ l.cbegin(), l.cend() };
      TArr stdArr{ 1, 2, 3, 4, 5 };

      // TO DO
      Print(v.begin(), v.end(), "Vektor");
      Print(l.begin(), l.end(), "Liste");
      //iterator_traits ist eine Hilfsklasse, dies ermoeglicht gewoehnliche Zeiger als Iterator
      // zu verwenden und auf eingebaute Datentypen zuzugreifen!
      Print(stdArr.begin(), stdArr.end(), "std::array"); //intresting error int*  TItor::value_type
      Print(arr, arr + cLEN, "C++ Arry");

      //generischer Algo -> search
      auto res = searchX(v.cbegin(), v.cend(), FindEq3);
      PrintFound(res, v.cend());

      //Lambda fuer andere Ausgabe in einer Variable gespeichert
      auto output = [](auto found, auto end) {
         cout << "lambda elem " << (found != end ? "found" : "not found") << endl;
      };

      auto lres = searchX(l.cbegin(), l.cend(), [](auto const val){ return val > 7; });
      PrintFound(lres, l.cend());
      output(lres, l.cend());

      auto equal4 = [](auto const val){ return val == 4; };
      auto ares = searchX(stdArr.cbegin(), stdArr.cend(), equal4);
      PrintFound(ares, stdArr.cend());
      output(ares, stdArr.cend());

      auto nres = searchX(arr, arr + cLEN, equal4);
      PrintFound(nres, arr + cLEN);
      output(nres, arr + cLEN);

      //auch mit string moeglich
      string str{"Hello SEN2"};
      auto sRes = searchX(str.cbegin(), str.cend(), [](auto const c){return c == 'o';});
      PrintFound(sRes, str.cend());
      output(sRes, str.cend());
   }
   catch (bad_alloc const& error)
   {
      cerr << "memory allocation: " << error.what() << endl;
      return 1;
   }
   catch (exception const& error)
   {
      cerr << "standard exception: " << error.what() << endl;
      return 1;
   }
   catch (...)
   {
      cerr << "unhandled exception -> catch it and try again..." << endl;
      return 1;
   }
}
