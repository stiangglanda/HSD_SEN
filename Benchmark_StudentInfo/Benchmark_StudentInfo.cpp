#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <random>

using namespace std;

// Typen für Punkte-Vektor
using TPoints = vector<size_t>;
using TPointsSize = TPoints::size_type;
using TPointValue = TPoints::value_type;

struct StudentInfo {
   std::string name;
   TPoints     points;
};

// Gruppen als Vektor und Liste
using TGroup = vector<StudentInfo>;
using TListGroup = list<StudentInfo>;

using TGroupSize = TGroup::size_type;
using TStudent = TGroup::value_type;

TPointValue const cPointsMin = 500;

// Zufällige Testdaten erzeugen (für Vektor oder Liste)
template <typename TContainer>
TContainer GenerateTestData(size_t count, size_t pointsPerStudent) {
   TContainer group;

	//Mersenne-Primzahl 2^19937-1 Zufallszahlengenerator
   mt19937 gen{ 42 }; // Fester Seed (Startwert) für den Zufallszahlengenerator
   uniform_int_distribution<> dis{ 0, 100 };  //Verteilungsobjekt das Zufallszahlen zwischen 0 und 100 erzeugt.

   for (size_t i = 0; i < count; ++i) {
      StudentInfo s;
      s.name = "Student_" + to_string(i);
      for (size_t j = 0; j < pointsPerStudent; ++j)
			s.points.push_back(dis(gen));  //Zufallszahl zwischen 0 und 100 wird in den Punktevektor eingefuegt.
      group.push_back(s);
   }

   return group;
}

TPointValue SumUp(TPoints const& points) {
   TPointValue s = 0;
   for (auto const p : points)
      s += p;
   return s;
}

bool DoesFail(StudentInfo const& stud) {
   return SumUp(stud.points) < cPointsMin;
}

// ====== EXTRACT FUNKTIONEN FUER VECTOR ======

TGroup ExtractIndex(TGroup& group) {
   TGroup fail;
   TGroupSize i = 0;

   while (i != group.size()) {
      if (DoesFail(group.at(i))) {
         fail.emplace_back(group.at(i));
         group.erase(group.cbegin() + i);
      }
      else {
         ++i;
      }
   }
   return fail;
}

TGroup ExtractIter(TGroup& group) {
   TGroup fail;
   auto itor = group.cbegin();

   while (itor != group.cend()) {
      if (DoesFail(*itor)) {
         fail.emplace_back(*itor);
         itor = group.erase(itor);
      }
      else {
         ++itor;
      }
   }
   return fail;
}

TGroup ExtractSTL(TGroup& group) {
   TGroup fail;
   copy_if(group.cbegin(), group.cend(), back_inserter(fail), DoesFail);
   group.erase(remove_if(group.begin(), group.end(), DoesFail), group.end());
   return fail;
}

// ====== EXTRACT FUNKTIONEN FUER LISTE ======

TListGroup ExtractList(TListGroup& group) {
   TListGroup fail;
   auto it = group.begin();

   while (it != group.end()) {
      if (DoesFail(*it)) {
         fail.push_back(*it);
         it = group.erase(it);
      }
      else {
         ++it;
      }
   }
   return fail;
}

TListGroup ExtractListSTL(TListGroup& group) {
   TListGroup fail;
   copy_if(group.begin(), group.end(), back_inserter(fail), DoesFail);
   group.remove_if(DoesFail);
   return fail;
}

// ====== GENERISCHE BENCHMARK-FUNKTION ======

template <typename Func, typename Container>
long long Benchmark(Func extractFunc, string const& label, Container& data) {
	auto start = chrono::high_resolution_clock::now();  //Startzeitpunkt: aktueller Zeitstempel in Nanosekunden 
   auto result = extractFunc(data);
	auto end = chrono::high_resolution_clock::now();   //Ende der Messung: aktueller Zeitstempel in Nanosekunden
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();  //Dauer der Messung in Mikrosekunden
   cout << label << ": " << duration << " microseconds, extracted " << result.size() << " students" << endl;
   return duration;
}

// ====== MAIN ======

int main() {
   size_t const studentCount = 10000;
   size_t const pointsPerStudent = 10;
   
   // Vektorbasierte Daten
   TGroup dataVec = GenerateTestData<TGroup>(studentCount, pointsPerStudent);
   Benchmark(ExtractIndex, "Vector - Extract (index-based)", dataVec);

   dataVec = GenerateTestData<TGroup>(studentCount, pointsPerStudent);
   Benchmark(ExtractIter, "Vector - ExtractIter (iterator-based)", dataVec);

   dataVec = GenerateTestData<TGroup>(studentCount, pointsPerStudent);
   Benchmark(ExtractSTL, "Vector - ExtractSTL (STL-based)", dataVec);

   cout << "-----------------------------" << endl;

   // Listenbasierte Daten
   TListGroup dataList = GenerateTestData<TListGroup>(studentCount, pointsPerStudent);
   Benchmark(ExtractList, "List - ExtractList (iterator-based)", dataList);

   dataList = GenerateTestData<TListGroup>(studentCount, pointsPerStudent);
   Benchmark(ExtractListSTL, "List - ExtractListSTL (STL-based)", dataList);

}

//
//Ergebnis im Release-Modus:
// 
// Vector - Extract(index - based) : 88444 microseconds, extracted 4964 students
// Vector - ExtractIter(iterator - based) : 72406 microseconds, extracted 4964 students
// Vector - ExtractSTL(STL - based) : 866 microseconds, extracted 4964 students
// ---------------------------- -
// List - ExtractList(iterator - based) : 460 microseconds, extracted 4964 students
// List - ExtractListSTL(STL - based) : 986 microseconds, extracted 4964 students