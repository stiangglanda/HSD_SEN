#ifndef STLALGOS_H
#define STLALGOS_H

#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <string>
#include <functional>

//Typdefinitionen für verwendete Container
using TDeqCont = std::deque<int>;
using TVecCont = std::vector<int>;
using TStrArr = std::array<std::string, 5> ;

//STL-Algorithmen ohne Praedikat
void Test_Algos(std::string const& header);

//STL-Algorithmen mit Prädikat
void Test_Algos_With_Pred(std::string const& header);
  
//Adapter auf Praedikate (Funktionsobjekte)
void Test_Algos_With_Adapter(std::string const& header);

#endif