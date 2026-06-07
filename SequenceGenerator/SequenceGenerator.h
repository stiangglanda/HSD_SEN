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
   // Constructs a sequence generator with a given start value and optional step size (default: 1)
   explicit SequenceGenerator(T start, T step = T{1}) : mStart{start}, mStep{step} {};

   // Returns the current value and advances the sequence by the step size
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