#include "STLAlgos.h"
#include "Output.h"
using namespace std;

static auto lower = [](auto c) { return tolower(c); };
static auto upper = [](auto c) { return toupper(c); };

//unary function als Lambda-Funktion -> Rueckgabetyp -> void, Parametertyp -> string
static std::function<void(string)> /*auto*/ capOutput = [](string str) {
   transform(str.cbegin(), str.cend(), str.begin(), lower);
   if (!str.empty()) {
      str.at(0)=std::toupper(str.at(0));
   }
   cout << str << " ";
};

void Test_Algos_With_Pred(string const& header)
{
   auto oldState = cout.exceptions(); // vorherigen Zustand merken
   try
   {
      cout.exceptions(ios::failbit | ios::badbit);
      PrintTestHeader(header);

      //Initialisierung der Daten
      string str = "salZbuRgEr NoCkerL";
      TStrArr sarr = { "alpha", "BRAVO", "charley", "ECHO", "delta" };
      TDeqCont cont{ 1, -2, 3, -4, 5, -6 };

      //to do
      //mit accumulate multiplizieren, statt addieren
      auto const cInit = 1;
      cout << "product: " << accumulate(cont.cbegin(), cont.cend(), cInit, multiplies<int>{}) << endl;

      cout << "Vorzeichen umdrehen: " << endl;
      transform(cont.cbegin(), cont.cend(), cont.begin(), negate<int>{});
      cout << cont;

      TVecCont vec;
      transform(cont.cbegin(), cont.cend(), back_inserter(vec), negate<int>{});
      cout << vec;

      TDeqCont deq;
      transform(cont.cbegin(), cont.cend(), front_inserter(deq), negate<int>{});
      cout << deq;

      cout << "2 Sequenzen multiplizieren:" << endl;
      transform(cont.cbegin(), cont.cend(), vec.cbegin(), back_inserter(cont), multiplies<int>{});
      cout << cont;

      // oder
      transform(deq.cbegin(), deq.cend(), vec.cbegin(), ostream_iterator<int>{cout, "\n"}, multiplies<int>{});

      cout << "bitwise operieren:" << endl;
      TDeqCont cont2{ 0b1100, 0b0101, 0b1010 };
      TDeqCont cont3{ 0b1001, 0b0100, 0b1111 };
      transform(cont2.cbegin(), cont2.cend(), cont3.cbegin(), back_inserter(vec), bit_and<int>{});
      cout << vec;

      cout << "auf/absteigend sortieren:" << endl;
      sort(cont.begin(), cont.end());
      cout << cont;
      sort(cont.begin(), cont.end(), greater<int>{});
      cout << cont;

      cout << "Umwandlung Gross/Kleinbuchstaben:" << endl;
      //transform(str.cbegin(), str.cend(), str.begin(), std::tolower/*{}*/); // -> ist eine funktion, kein Objekt
      transform(str.cbegin(), str.cend(), str.begin(), lower);
      cout << str << endl;

      transform(str.cbegin(), str.cend(), str.begin(), upper);
      cout << str << endl;

      for_each(sarr.cbegin(), sarr.cend(), capOutput);
      cout << endl;

      for_each(sarr.cbegin(), sarr.cend(), capOutput)("That's ALL");
      cout << endl;
   }
   catch (std::bad_alloc const& ex)
   {
      std::cerr << "memory allocation: " << ex.what() << std::endl;
      return;
   }
   catch (std::ios_base::failure const& ex)
   {
      std::cerr << "I/O error: " << ex.what() << std::endl;
      cout.exceptions(oldState); // vorherigen Zustand wiederherstellen
      return;
   }
   catch (std::exception const& ex)
   {
      std::cerr << ex.what() << std::endl;
      return;
   }
   catch (...)
   {
      std::cerr << "unhandled exception..." << std::endl;
      return;
   }
}