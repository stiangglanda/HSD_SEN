#include <iomanip>
#include <limits>

class StringStatistic{
public:
   StringStatistic() = default;

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

   void Print(std::ostream& ost = std::cout) const {
      ost << "string statistic:" << std::endl;
      if (mStrCnt == 0) {
         ost << "min: 0" << std::endl << "max: 0" << std::endl << "avg: 0.00" << std::endl;
         return;
      }

      ost << "min: " << mStrMin << std::endl
          << "max: " << mStrMax << std::endl
          << "avg: " << std::fixed << std::setprecision(2)
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