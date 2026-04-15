#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <vector>
#include <iostream>

typedef std::vector <int> TCont;
typedef TCont::size_type  TContSize;

double Average (int const s, size_t const n);
double Average (TCont const & cont);
float  Median   (TCont Container);
void   Print         (TCont const & cont, std::ostream& ost = std::cout);
void   ReadNumbers   (TCont & cont);


#endif //EXCEPTIONS_H