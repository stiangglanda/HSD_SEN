#ifndef SimpleClass_H
#define SimpleClass_H

class Simple
{
public:
   Simple(); // Default CTor
   Simple(int const val1, int const val2); //CTor mit Parameter
   Simple(Simple const& s); //CopyCTor
   ~Simple(); //DTor

   //Daten aus der Klasse auslesen
   int GetFirstVal() const;
   int GetSecondVal() const;

   //Daten in der Klasse ablegen
   void SetFirstVal(int const val);
   void SetSecondVal(int const val);

   //Daten formatiert ausgeben
   void Print(std::ostream& ost) const;
   void PrintFormated(std::ostream& ost) const;

   //einfache operationen
   int CalcSum() const;
   int CalcDiff() const;

   //public member
   int mPublicMember; //schlecht, dient hier nur zur Demo

private:
   //private Methode
   void OutputActStreamValues(std::ostream& ost) const;

   //private Daten
   int mFirstVal;
   int mSecondVal;
};



#endif //SimpleClass_H