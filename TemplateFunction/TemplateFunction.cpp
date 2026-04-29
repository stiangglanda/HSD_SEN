#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <array>
#include <cassert>
using namespace std;

short const cLEN = 5;

//Typdefinitionen
using TList = list<int>;
using TVect = vector<int> ;
using TArr  = array<int, cLEN> ;


int main()
{
   try
   {
      int arr[cLEN] = { 1, 2, 3, 4, 5 };
      TList l{ arr, arr + cLEN };
      TVect v{ l.cbegin(), l.cend() };
      TArr stdArr{ 1, 2, 3, 4, 5 };

      // TO DO
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