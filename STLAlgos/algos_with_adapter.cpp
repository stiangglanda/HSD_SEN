#include "STLAlgos.h"
#include "Output.h"
using namespace std;

//eine Liste mit Paaren aus int und float
using TLPairs = list<pair<int, float>>;

//Ausgabeoperator für Liste mit Paaren
static ostream& operator << (ostream& ost, TLPairs::value_type const& p)
{
   return ost << "(" << p.first << "," << p.second << ")";
}

//Lambda zur Ausgabe von Listen-Paaren
static auto out = [](TLPairs const& l) 
{
   for (auto const& p : l) { 
      cout << p << " "; 
   } 
   cout << endl; 
};


void Test_Algos_With_Adapter(std::string const& header)
{
   auto oldState = cout.exceptions(); // vorherigen Zustand merken
   try
   {
      cout.exceptions(ios::failbit | ios::badbit);
      PrintTestHeader(header);
      //Testdaten
      TDeqCont cont{ 3, 1, 4, 5, 7, 0, 8, 2, 6 };
      TDeqCont cont2{ 1, 3, 4, 5, 6, 7 }, cont3 = cont2, cont4 = cont2;
      TLPairs lPairs{ {9,9.9f},{3,3.3f}, {1,1.2f}, {1,1.1f}, {9,9.8f}, {4,4.4f} };

      //to do
      auto less5 = [](auto const val){ return val < 5; };

      //oder mit bind ein neues Funktionsobjeckt (=Adapter) erzeugen
      using namespace placeholders;
      auto adaptLess5 = bind(less<int>{}, _1, 5);
      replace_if(cont.begin(), cont.end(), less5, 4711);
      cout << cont;

      // Lambda fuer Wertebereich
      int const cMin = 3;
      int const cMax = 7;
      function<bool(int)> isRange = [cMin, cMax](int const val) {
         return val > cMin && val < cMax;
      };

      //oder mit bind
      auto adaptRange = bind(logical_and{}, bind(greater<int>{}, _1, cMin), bind(less<int>{}, _1, cMax));
      auto newEnd = remove_if(cont2.begin(), cont2.end(), /*isRange*/ adaptRange);
      cont2.erase(newEnd, cont2.end());

      newEnd = remove_if(cont3.begin(), cont3.end(), /*isRange*/ not_fn(adaptRange));
      cont3.erase(newEnd, cont3.end());
      cout << cont3;

      TLPairs test1{ lPairs };
      test1.sort();
      out(test1);

      test1.sort(greater/*<TLPairs::value_type>*/{});
      out(test1);

      TLPairs test2{ lPairs };
      test2.sort([](auto const& l, auto const& r) { return l.first < r.first; });
      out(test2);

      auto isEvenFirst=[](auto const& p) { return p.first % 2 == 0; };
      cout << count_if(lPairs.cbegin(), lPairs.cend(), isEvenFirst) << endl;
      cout << count_if(lPairs.cbegin(), lPairs.cend(), not_fn(isEvenFirst)) << endl;

      string path{"D:/public/min.obj/aigner.obj/max.obj"};
      string ext{".obj"};
      auto found= find_end(path.cbegin(), path.cend(), ext.cbegin(), ext.cend());
      if (found != path.cend()) {
         cout << "extension found at: " << distance(path.cbegin(), found) << endl;
      }

      found= search(path.cbegin(), path.cend(), ext.cbegin(), ext.cend());
      if (found != path.cend()) {
         cout << "extension found at: " << distance(path.cbegin(), found) << endl;
      }

      //Pruefung auf Permutation
      string perm{ path };
      sort(perm.begin(), perm.end());
      cout << perm;
      cout << endl << is_permutation(perm.cbegin(), perm.cend(), path.cbegin()) << endl;
      path.at(5)='x';
      cout << endl << is_permutation(perm.cbegin(), perm.cend(), path.cbegin()) << endl;

      auto minmax = minmax_element(perm.cbegin(), perm.cend());
      cout << "min: " << *minmax.first << endl << "max: " << *minmax.second << endl;
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
