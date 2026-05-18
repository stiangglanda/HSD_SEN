#include "Fraction.h"
using namespace std;

std::ostream& operator << (std::ostream& out, Fraction const& f)
{
   out << std::endl << " " << f.GetNumerator() << std::endl
      << "----" << std::endl
      << " " << f.GetDenominator() << std::endl << std::endl;
   return out;
}

// CTor mit Parameter (Defaultparameter)
// Wird beim Aufruf kein Parameter angegeben -> Defaultwert fuer n wird verwendet
// Ein Defaultwert kann nur am Ende einer Parameterliste stehen!
Fraction::Fraction(int numerator, int denominator) :
   mNumerator(numerator), mDenominator(denominator)
{
   if (denominator == 0)
   {
      throw std::invalid_argument("Nenner darf nicht 0 sein!");
   }

   // Vorzeichenregel: Nenner sollte immer positiv sein
   if (mDenominator < 0)
   {
      mNumerator = -mNumerator;
      mDenominator = -mDenominator;
   }

   // Automatisches Kürzen
   //Reduced reduced = Reduce(mNumerator, mDenominator);
   //mNumerator = reduced.num;
   //mDenominator = reduced.denom;
}

// Copy-CTor: wird in dieser Form auch automatisch erzeugt, da nur die
// Attribute kopiert werden!
Fraction::Fraction(Fraction const& b) :
   mNumerator(b.mNumerator), mDenominator(b.mDenominator)
{
}

Fraction::~Fraction()
{
}

// Ueberladen des Multiplikationsoperators als Memberfunktion
Fraction Fraction::operator * (Fraction const& f) const
{
   Reduced redFrac = Reduce(mNumerator * f.mNumerator, mDenominator * f.mDenominator);
   return Fraction{ redFrac.num, redFrac.denom };
}

// Ueberladen des Additionsoperators als Memberfunktion
Fraction Fraction::operator + (Fraction const& f) const
{
   Reduced redFrac = Reduce(mNumerator * f.mDenominator + mDenominator * f.mNumerator,
      mDenominator * f.mDenominator);
   return Fraction{ redFrac.num,redFrac.denom };
}

// Ueberladen des Zuweisungsoperators mit Rueckgabewert -> Verkettung moeglich!  
// Rueckgabewert ist eine const-Referenz, da sonst der Aufruf (a=b) = c moeglich waere
Fraction& Fraction::operator = (Fraction const& f)
{
   if (&f != this) // Selbstzuweisung (self assignment)
   {
      mNumerator = f.mNumerator;
      mDenominator = f.mDenominator;
   }
   return *this;
}

// Ueberladen des <-Operators
bool Fraction::operator < (Fraction const& f) const
{
   // Vergleichen des Kreuzproduktes
   return (long long)mNumerator * f.mDenominator < (long long)mDenominator * f.mNumerator;
}

// Ueberladen des Vergleichsoperators (equal operator) ==
bool Fraction::operator == (Fraction const& f) const
{
   return !(*this < f) && !(f < *this);
}

int Fraction::GetNumerator() const
{
   return mNumerator;
}

int Fraction::GetDenominator() const
{
   return mDenominator;
}

unsigned int Fraction::GreatestCommonDivisor(int numerator, int denominator) const
{
   if (numerator == 0) return abs(denominator);
   if (denominator == 0) return abs(numerator);

   do {
      int h = numerator % denominator;
      numerator = denominator;
      denominator = h;
   } while (denominator != 0);

   return abs(numerator);
}

Fraction::Reduced Fraction::Reduce(int numerator, int denominator) const
{
   unsigned int const gcd = GreatestCommonDivisor(numerator, denominator);
   return Reduced{ numerator /= gcd, denominator /= gcd };
}
