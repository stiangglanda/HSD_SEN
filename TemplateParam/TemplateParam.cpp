#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <string>
#include <algorithm>
#include <functional>
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