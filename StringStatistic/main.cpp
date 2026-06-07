///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 06.06.2026
// Description : StringStatistic Testdriver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "StringStatistic.h"

void run_test(const std::vector<std::string>& vec, const std::string& test_name) {
   std::cout << test_name << std::endl;
   std::cout << "Input strings: ";
   if (vec.empty()) {
      std::cout << "(empty)";
   } else {
      std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<std::string>(std::cout, " "));
   }
   std::cout << std::endl << std::for_each(vec.cbegin(), vec.cend(), StringStatistic{}) << std::endl;
}

int main()
{
   std::vector<std::string> val{"abc", "x", "abcdefgh", "aa"};
   run_test(val, "Standard");

   std::vector<std::string> empty_val{};
   run_test(empty_val, "Empty vector");

   std::vector<std::string> empty_strings{"", "", ""};
   run_test(empty_strings, "Only empty strings");

   std::vector<std::string> single_string{"hello"};
   run_test(single_string, "Only one string");

   std::vector<std::string> same_length{"123", "456", "789"};
   run_test(same_length, "Strings of equal length");

   std::vector<std::string> special_chars{"a b", "   ", "!?"};
   run_test(special_chars, "Strings with spaces and special characters");

   return 0;
}