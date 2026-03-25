#include "Fraction.h"
using namespace std;

//Fehlertext
static string const cErrOut = "error in <<-operator()";
static string const cErrDenomZero = "error in ctor -> denominator cannot be zero!";

Fraction::Fraction(int const numerator, int const denominator) :
   mNumerator(numerator),
   mDenominator(denominator != 0 ? denominator : 1)
{
   if (denominator == 0) {
      cerr << cErrDenomZero << endl;
      mNumerator = 0;
   }
   //Testausgabe
   cout << "param ctor fraction: " << this << endl;
}

Fraction Fraction::operator*(Fraction const &f) const {
   //Fraction tmp;
   //tmp.mNumerator = mNumerator * f.mNumerator;
   //tmp.mDenominator = mDenominator * f.mDenominator;

   // besser:
   Reduced redFrac = Reduce(mNumerator * f.mNumerator, mDenominator * f.mDenominator);
   return Fraction{redFrac.num, redFrac.denom};
}

Fraction Fraction::operator + (Fraction const &f) const {
   Reduced redFrac = Reduce(mNumerator * f.mDenominator + mDenominator * f.mNumerator,
                              mDenominator * f.mDenominator);
   return Fraction{redFrac.num, redFrac.denom};
}

bool Fraction::operator<(Fraction const &f) const {
   //Ueberlauf durch long long cast vermeiden
   return static_cast<long long>(mNumerator * f.mDenominator) < static_cast<long long>(mDenominator * f.mNumerator);
}

bool Fraction::operator==(Fraction const &f) const {
   return static_cast<long long>(mNumerator * f.mDenominator) == static_cast<long long>(mDenominator * f.mNumerator);
   //oder andere Formulierung
   //return !(*this<f) && !(*this==f);
}

int Fraction::GetNumerator() const {
   return mNumerator;
}

int Fraction::GetDenominator() const {
   return mDenominator;
}

//berechne den groeszten gemeinsamen Teiler
unsigned int Fraction::GreatestCommonDivisor(int numerator, int denominator) const
{
   //Euklidischer Algorithmus
   while (denominator != 0) {
      int temp = denominator;
      denominator = numerator % denominator;
      numerator = temp;
   }
   return numerator;

  
}


//Bruch kuerzen
Fraction::Reduced Fraction::Reduce(int numerator, int denominator) const
{
   unsigned int const gcd = GreatestCommonDivisor(numerator, denominator);
   return Reduced{ numerator /= gcd, denominator /= gcd };
}

std::ostream & operator<<(std::ostream &ost, Fraction const &f) {
   if (!ost.good()) {
      cerr << cErrOut;
      return ost;
   }
   ost << endl << " " << f.GetNumerator() << endl << "----" << endl << " " << f.GetDenominator() << endl;
   return ost;
}



  