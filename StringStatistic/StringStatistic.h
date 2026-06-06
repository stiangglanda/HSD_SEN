#include <limits>

class StringStatistic{
public:
   StringStatistic() {};

   void operator() (std::string str) {
      if(str.size() < mStrMin) {
         mStrMin = str.size();
      }
      if(str.size() > mStrMax) {
         mStrMax = str.size();
      }
      mStrSizeSum += str.size();
      mStrCnt++;
   };

   void Print() {
      std::cout << "string statistic:" << std::endl;
      std::cout << "min: " << mStrMin << std::endl;
      std::cout << "max: " << mStrMax << std::endl;
      std::cout << "avg: " << static_cast<double>(mStrSizeSum)/static_cast<double>(mStrCnt);
   }
private:
   size_t mStrMin = std::numeric_limits<size_t>::max();
   size_t mStrMax = 0;

   size_t mStrCnt = 0;
   size_t mStrSizeSum = 0;
};