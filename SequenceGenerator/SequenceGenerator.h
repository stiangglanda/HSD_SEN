///////////////////////////////////////////////////////////////////////////
// Workfile : SequenceGenerator.h
// Author : Leander Kieweg
// Date : 06.06.2026
// Description : SequenceGenerator Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef SEQUENCEGENERATOR_H
#define SEQUENCEGENERATOR_H

template <typename T>
class SequenceGenerator{
public:
   SequenceGenerator(T start, T step = T{1}) : mStart{start}, mStep{step} {};
    
   T operator() () {
      T tmp = mStart;
      mStart = mStart + mStep;
      return tmp;
   };
private:
   T mStart;
   T mStep;
};

#endif