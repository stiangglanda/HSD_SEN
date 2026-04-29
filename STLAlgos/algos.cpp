#include "STLAlgos.h"
#include "Output.h"
using namespace std;


void Test_Algos(string const& header)
{
   auto oldState = cout.exceptions(); // vorherigen Zustand merken
   try
   {
      cout.exceptions(ios::failbit | ios::badbit);
      PrintTestHeader(header);

      TDeqCont cont(5);  //Container mit Speicher für 5 Elemente
   
      //to do
      fill(cont.begin(), cont.end(), 1);
      cout << cont;

      fill_n(cont.end() - 2, 2, 4);
      cout << cont;

      cont.push_back(5);
      copy_backward(cont.cend()-2, cont.cend(), cont.begin()+2);
      cout << cont;

      reverse_copy(cont.cend()-2, cont.cend(), cont.begin());
      cout << cont;

      cout << "sum: " << accumulate(cont.cbegin(), cont.cend(), TDeqCont::value_type{} /*0*/ /*int{}*/) << endl;

      sort(cont.begin(), cont.end());
      cout << boolalpha << binary_search(cont.cbegin(), cont.cend(), 1) << endl;

      auto lb = lower_bound(cont.cbegin(), cont.cend(), 4);
      auto ub = upper_bound(cont.cbegin(), cont.cend(), 4);
      if (lb != cont.cend() && ub != cont.cend()) {
         cout << cont;
         cout << "lb at: " << distance(cont.cbegin(), lb) << endl;
         cout << "ub at: " << distance(cont.cbegin(), ub) << endl;
      }

      replace(cont.begin(), cont.end(), 4, 4711);
      cout << cont;

      auto end = remove(cont.begin(), cont.end(), 4711);
      cont.erase(end, cont.cend());
      cout << cont;

      end = unique(cont.begin(), cont.end());
      cont.erase(end, cont.cend());
      cout << cont;
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