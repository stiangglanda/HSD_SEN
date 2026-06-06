
template <typename T>
class SequenceGenerator{
public:
   SequenceGenerator(T start, T step = 1) : mStart{start}, mStep{step} {};
    
   T operator() () {
      T tmp = mStart;
      mStart = mStart + mStep;
      return tmp;
   };
private:
   T mStart;
   T mStep;
};