// lineare einfach verkettete Liste
// Implementierung

#include <cassert>
#include <iostream>
#include "ListenModul.h"

using namespace std;

// Knoten erzeugen
TNode* MakeNode(int const data) {
    TNode* pNewNode = new (nothrow) TNode();
    assert(pNewNode != nullptr); // memory check
    if (pNewNode != nullptr) {
        pNewNode->data = data;
        pNewNode->pNext = nullptr;
    }
    return pNewNode;
}

// testen ob Liste Leer
bool IsEmpty(TList pList) {
    return pList == nullptr;
}

// Anzahl der Knoten in der Liste
size_t Length(TList pList) {
    size_t len = 0;
    TNode* pNode = pList; // Hilfszeiger

    while (pNode != nullptr) {
        len++;
        pNode = pNode->pNext;
    }

    return len;
}

// Liste ausgeben
void Print(TList pList) {
    TNode* pNode = pList;
    cout << "Liste der laenge " << Length(pList) << endl;
    cout << "Elemente: " << endl;

    while (pNode != nullptr) {
        cout << pNode->data << endl;
        pNode = pNode->pNext;
    }
}

// Knoten vorne in der Liste einfuegen
void Prepend(TList& pList, int const data) {
    TNode* pNewNode = MakeNode(data); // Knoten erzeugen

    pNewNode->pNext = pList;          // Kanten erzeugen
    pList = pNewNode;
}

void Append(TList& pList, int const data) {
    TNode* pNewNode = MakeNode(data);
    TNode* pPrev = pList;
    TNode* pNode = pList;

    if (pList == nullptr) { // leere Liste
        pList = pNode;
    }
    else {
        while (pNode != nullptr) { // Listenende suchen
            pPrev = pNode;
            pNode = pNode->pNext;
        }

        pPrev->pNext = pNewNode;
    }

}