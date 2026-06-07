///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 06.06.2026
// Description : SequenceGenerator Testdriver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include "SequenceGenerator.h"

using namespace std;

int main()
{
   cout << "Numbers from 1 to 10" << endl;
   generate_n(ostream_iterator<int>{cout, " "}, 10, SequenceGenerator<int>{1});
   cout << endl;

   cout << "Numbers from 10 to 1 (descending order)" << endl;
   generate_n(ostream_iterator<int>{cout, " "}, 10, SequenceGenerator<int>{10, -1});
   cout << endl;

   cout << "Numbers from 0 to 5 (increment 0.5)" << endl;
   generate_n(ostream_iterator<double>{cout, " "}, 11, SequenceGenerator<double>{0, 0.5});
   cout << endl;

   cout << "Letters from A to Z" << endl;
   generate_n(ostream_iterator<char>{cout, ""}, 26, SequenceGenerator<char>{'A'});
   cout << endl;

   cout << "Step size 0" << endl;
   generate_n(ostream_iterator<int>{cout, " "}, 5, SequenceGenerator<int>{42, 0});
   cout << endl;

   cout << "Generating 0 elements (Should not crash and output nothing)" << endl;
   generate_n(ostream_iterator<int>{cout, " "}, 0, SequenceGenerator<int>{1});
   cout << endl;

   cout << "Negative start value with a larger step" << endl;
   generate_n(ostream_iterator<int>{cout, " "}, 6, SequenceGenerator<int>{-10, 3});
   cout << endl;

   cout << "Non-numeric type (std::string)" << endl;
   generate_n(ostream_iterator<string>{cout, "\n"}, 5, SequenceGenerator<string>{"A", "A"});
   cout << endl;
}