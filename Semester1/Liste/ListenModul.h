#ifndef LISTENMODUL_H
#define LISTENMODUL_H
#include <cstddef>//wegen size_t ist mit msvc nicht notwendig
// linear einfach verkettete Liste
// Schnittstelle

struct TNode {
    int data;       // Nutzdaten
    TNode *pNext;   // Kante zum Nachfolgeknoten
};

typedef TNode* TList;

// Prototypen
bool IsEmpty(TList pList);
size_t Length(TList pList);
void Prepend(TList& pList, int const data);
void Append(TList& pList, int const data);
void Print(TList pList);
void Flush(TList& pList);
void Delete(TList& pList, int const data);
double AvgElements(TList pList);

void PrintRecursive(TList const List);
size_t LengthRecursive(TList const List);
double AvgElementsRecursive(TList pList, int depth);

#endif