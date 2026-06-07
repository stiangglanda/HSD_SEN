///////////////////////////////////////////////////////////////////////////
// Workfile : StringStatistic.h
// Author : Leander Kieweg
// Date : 06.06.2026
// Description : StringStatistic Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef STRINGSTATISTIC_H
#define STRINGSTATISTIC_H
#include <iomanip>
#include <limits>

class StringStatistic{
public:
   StringStatistic() = default;

   // Updates min, max, and accumulated length data based on the given string
   void operator() (std::string const& str) {
      if(str.size() < mStrMin) {
         mStrMin = str.size();
      }
      if(str.size() > mStrMax) {
         mStrMax = str.size();
      }
      mStrSizeSum += str.size();
      mStrCnt++;
   };

   // Prints the computed string statistics (min, max, avg length) to the given output stream
   void Print(std::ostream& ost = std::cout) const {
      ost << "string statistic:" << std::endl;
      if (mStrCnt == 0) {
         ost << "min: 0" << std::endl << "max: 0" << std::endl << "avg: 0.00" << std::endl;
         return;
      }

      ost << "min: " << mStrMin << std::endl
          << "max: " << mStrMax << std::endl
          << "avg: " << std::fixed << std::setprecision(mPrecision)
          << (static_cast<double>(mStrSizeSum) / mStrCnt) << std::endl;
   }
private:
   size_t mStrMin = std::numeric_limits<size_t>::max();
   size_t mStrMax = 0;
   size_t mStrCnt = 0;
   size_t mStrSizeSum = 0;
   const size_t mPrecision = 2;
};

std::ostream& operator<<(std::ostream& ost, StringStatistic const& stat) {
   stat.Print(ost);
   return ost;
}

#endif