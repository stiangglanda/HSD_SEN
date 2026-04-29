#ifndef OUTPUT_H
#define OUTPUT_H
#include <exception>
#include "STLAlgos.h"

//Hilfsfunktionalitaet
std::ostream& operator << (std::ostream& ost, TDeqCont const& cont);
std::ostream& operator << (std::ostream& ost, TVecCont const& cont);
void PrintTestHeader(std::string const& header, std::ostream& ost = std::cout);

#endif