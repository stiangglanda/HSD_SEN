#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "StringStatistic.h"

using namespace std;

int main()
{
   vector<string> val{"abc", "x", "abcdefgh", "aa"};
   //Input strings: abc x abcdefgh aa
   //string statistic:
   //min: 1
   //max: 8
   //avg: 3.50
   StringStatistic strStat{};
   for_each(val.cbegin(), val.cend(), [&](string str) { strStat(str); } );

   strStat.Print();

   cout << endl;
}