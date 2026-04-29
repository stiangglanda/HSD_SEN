#include "Output.h"
using namespace std;

ostream& operator << (ostream& ost, TDeqCont const& cont)
{
   copy(cont.cbegin(), cont.cend(), ostream_iterator<TDeqCont::value_type>(ost, " "));
   return ost << endl;
}


ostream& operator << (ostream& ost, TVecCont const& cont)
{
   copy(cont.cbegin(), cont.cend(), ostream_iterator<TVecCont::value_type>(ost, " "));
   return ost << endl;
}

void PrintTestHeader(string const& header, std::ostream& ost)
{
   ost << "----------------------------------" << endl;
   ost << "//" << header << endl;
   ost << "----------------------------------" << endl;
}