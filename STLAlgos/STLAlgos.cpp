#include "STLAlgos.h"

//Testtreiber
int main()
{

   //STL-Algorithmen ohne Prädikat
   Test_Algos("Test algos without predicate");

   //STL-Algorithmen mit Prädikat
   Test_Algos_With_Pred("Test algos with predicate");

   //Adapter auf Prädikate (Funktionsobjekte)
   Test_Algos_With_Adapter("Test algos with adapters to predicates");

}