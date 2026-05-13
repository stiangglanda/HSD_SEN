#pragma once
#include <iostream>

template<typename T>
class Simple
{
public:
   // Default-Konstruktor
   Simple();

   // Konstruktor mit Parametern
   Simple(T const& val1, T const& val2);

   // 1. Copy-Konstruktor (Zwingend noetig durch Zeigerverwaltung)
   Simple(Simple const& s);

   // 2. Zuweisungsoperator (Neu & Zwingend noetig durch Zeigerverwaltung)
   Simple& operator=(Simple const& rhs);

   // 3. Destruktor (Zwingend noetig, um Speicher freizugeben)
   ~Simple();

   // Daten aus der Klasse auslesen
   T GetFirstVal() const;
   T GetSecondVal() const;

   // Daten in der Klasse ablegen
   void SetFirstVal(T const& val);
   void SetSecondVal(T const& val);

   // Daten formatiert ausgeben
   void Print() const;

   // einfache Operationen
   T CalcSum() const;
   T CalcDiff() const;

private:
   void PrivateMethod();

   // Private Daten (jetzt als Zeiger fuer dynamische Speicherverwaltung!)
   T* mFirstVal;
   T* mSecondVal;
};


// --- Implementierungen ---

template<typename T>
Simple<T>::Simple() :
   // Speicher auf dem Heap allokieren und default-initialisieren
   mFirstVal{ new T{} }, 
   mSecondVal{ new T{} }
{
   std::cout << "+++ Default-CTor: Objekt mit Adresse " << std::hex << this
      << " erzeugt. (Speicher alloziert) +++" << std::dec << '\n';
}

template<typename T>
Simple<T>::Simple(T const& val1, T const& val2) : 
   // Speicher auf dem Heap allokieren und mit Werten fuellen
   mFirstVal{ new T{val1} }, 
   mSecondVal{ new T{val2} }
{
   std::cout << "+++ Param-CTor: Objekt mit Adresse " << std::hex << this
      << " erzeugt. (Speicher alloziert) +++" << std::dec << '\n';
}

// 1. IMPLEMENTIERUNG COPY-CONSTRUCTOR (Deep Copy)
template<typename T>
Simple<T>::Simple(Simple const& s) :
   // WICHTIG: Neuen Speicher allokieren und Werte vom anderen Objekt kopieren!
   // Nicht einfach nur die Adressen kopieren.
   mFirstVal{ new T{ *(s.mFirstVal) } },
   mSecondVal{ new T{ *(s.mSecondVal) } }
{
   std::cout << "+++ Copy-CTor: Objekt mit Adresse " << std::hex << this
      << " erzeugt. (Deep Copy) +++" << std::dec << '\n';
}

// 2. IMPLEMENTIERUNG ZUWEISUNGSOPERATOR (Deep Copy)
template<typename T>
Simple<T>& Simple<T>::operator=(Simple const& rhs)
{
   std::cout << "+++ Assignment Operator (Zuweisung) +++\n";

   // a) Selbstzuweisung ausschliessen (z.B. simpleA = simpleA;)
   if (this == &rhs) {
      return *this;
   }

   // b) Werte auf dem bereits allozierten Heap-Speicher ueberschreiben
   // Achtung: Wir weisen hier die Werte neu zu, die Zeigeradressen bleiben gleich.
   *mFirstVal = *(rhs.mFirstVal);
   *mSecondVal = *(rhs.mSecondVal);

   // c) Referenz auf sich selbst zurueckgeben (fuer Kettenzuweisungen a = b = c)
   return *this;
}

// 3. IMPLEMENTIERUNG DESTRUCTOR
template<typename T>
Simple<T>::~Simple()
{
   // WICHTIG: Angeforderten dynamischen Speicher wieder freigeben!
   delete mFirstVal;
   delete mSecondVal;

   std::cout << "+++ DTor: Objekt mit Adresse " << std::hex << this
      << " zerstoert. (Speicher freigegeben) +++" << std::dec << '\n';
}

template<typename T>
T Simple<T>::GetFirstVal() const
{
   return *mFirstVal; // Zeiger dereferenzieren, um den Wert zu bekommen
}

template<typename T>
T Simple<T>::GetSecondVal() const
{
   return *mSecondVal;
}

template<typename T>
void Simple<T>::SetFirstVal(T const& val)
{
   *mFirstVal = val;
}

template<typename T>
void Simple<T>::SetSecondVal(T const& val)
{
   *mSecondVal = val;
}

template<typename T>
void Simple<T>::Print() const
{
   std::cout << "First value: " << *mFirstVal << '\n';
   std::cout << "Second value: " << *mSecondVal << '\n';
   std::cout << "-----------------------------\n\n";
}

template<typename T>
T Simple<T>::CalcSum() const
{
   return (*mFirstVal) + (*mSecondVal);
}

template<typename T>
T Simple<T>::CalcDiff() const
{
   return (*mFirstVal) - (*mSecondVal);
}

template<typename T>
void Simple<T>::PrivateMethod()
{
   std::cout << "Try calling me :-)\n";
}
