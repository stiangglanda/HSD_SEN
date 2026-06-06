#include <iostream>
#include <algorithm>
#include <iterator>
#include "SequenceGenerator.h"

using namespace std;

int main()
{
   // Numbers from 1 to 10
   generate_n(ostream_iterator<int>{cout, " "}, 10, SequenceGenerator<int>{1});
   cout << endl;
   // Numbers from 10 to 1 (descending order)
   generate_n(ostream_iterator<int>{cout, " "}, 10, SequenceGenerator<int>{10, -1});
   cout << endl;
   // Numbers from 0 to 5 (increment 0.5)
   generate_n(ostream_iterator<double>{cout, " "}, 11, SequenceGenerator<double>{0, 0.5});
   cout << endl;
   // Letters from A to Z
   generate_n(ostream_iterator<char>{cout, ""}, 26, SequenceGenerator<char>{'A'});
   cout << endl;
}