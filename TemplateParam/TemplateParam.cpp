#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

#include "Fraction.h"
#include "ContainerWrapper.h"
using namespace std;


int main()
{
   try
   {
      // to do
      // ....
      ContainerWrapper<> cont;
      cont.Print();

      ContainerWrapper<float, deque<float>, 4> contF{47.11f};
      contF.Print(cout, "\n");

      using ContLong = ContainerWrapper<long, deque<long>>;
      ContLong contL{4711};
      contL.Add(4710);
      contL.Add(4709);
      sort(contL.begin(), contL.end());
      contL.Print();

      using TCharList = ContainerWrapper<char, list<char>>;
      TCharList contC{'x'};
      contC.Add('a');
      contC.Add('z');
      auto res = find(contC.begin(), contC.end(), 'a');

      using TFracDeq = ContainerWrapper<Fraction, deque<Fraction>, 3>;
      TFracDeq contFraq{{3,2}};
      contFraq.Add({4,5});
      contFraq.Add({3});
      contFraq.Add({1,2});
      contFraq.Print();

      auto end = unique(contFraq.begin(), contFraq.end());
      cout << "unique shorted sequence:" << endl;
      // Ausgabe via Lambda
      auto outFrac = [&](){copy(contFraq.begin(), end, ostream_iterator<TFracDeq::value_type>(cout, "\n")); };
      outFrac();

      cout << "ascending sorted shorted sequence:" << endl;
      sort(contFraq.begin(), end);
      outFrac();

      cout << "ascending sorted shorted sequence:" << endl;
      //sort(contFraq.begin(), end, greater/*<Fraction>*/{}); -> > Op fuer Fraction nicht impl:
      //sort(contFraq.begin(), end, not_fn(less{}));  // -> >= ... ist nicht das richtige sortierkriterium, funkt ab und zu
      sort(contFraq.begin(), end, [](auto const &lhs, auto const &rhs) {return rhs < lhs; });
      outFrac();

      cout << "sum of Fractions: " << accumulate(contFraq.begin(), end, Fraction{0,1}) << endl;
      cout << "mul of Fractions: " << accumulate(contFraq.begin(), end, Fraction{1,1}, multiplies{}) << endl;
   }
   catch (std::bad_alloc const& ex)
   {
      std::cerr << "memory allocation: " << ex.what() << std::endl;
      return 1;
   }
   catch (std::exception const& ex)
   {
      std::cerr << ex.what() << std::endl;
      return 1;
   }
   catch (...)
   {
      std::cerr << "unhandled exception..." << std::endl;
      return 1;
   }
}