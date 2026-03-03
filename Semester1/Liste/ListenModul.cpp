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
    cout << "Liste der laenge Recursive " << LengthRecursive(pList) << endl;
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

// gesamte Liste loeschen
void Flush(TList &pList) {
    TNode* pNode = nullptr;
    while (pList != nullptr) {
        pNode = pList;
        pList = pList->pNext; // Ausketten
        delete pNode; pNode = nullptr;
    }
}

// Knoten in der Liste suchen
TNode* Search(TList pList, int const data) {
    TNode* pNode = pList;

    while (pNode != nullptr && pNode->data != data) { // kurzschluss auswertung
        pNode = pNode->pNext;
    }
    return pNode;
}

TNode* Predecessor(TList pList, TNode* pFound) {
    TNode* pPrev = pList;
    while (pPrev != nullptr && pPrev->pNext != pFound) {
        pPrev = pPrev->pNext;
    }
    return pPrev;
}

// Knoten mit Wert 'data' aus der Liste entfernen (erstes Auftreten ab pList)
void Delete(TList& pList, int const data) {
    TNode* pFound = Search(pList, data);
    if (pFound != nullptr) {
        if (pFound == pList) {  // 1. Knoten
            pList = pFound->pNext;
        }
        else {
            Predecessor(pList, pFound)->pNext = pList->pNext;
        }
        delete pFound; pFound = nullptr;
    }
}

double AvgElements(TList pList) {

}

void PrintRecursive(TList const List) {
    TNode* pNode = List;
    // Abbruchbedingung
    if (pNode == 0) {
        cout << "Ende der Liste erreicht" << endl;
        return;
    }

    //einwickeln
    //cout << "Element: " << pNode->data << endl; // von vorne

    PrintRecursive(pNode->pNext);
    // auswickeln

    cout << "Element: " << pNode->data << endl; // von hinten
}

size_t LengthRecursive(TList const List) {
    size_t len = 0;
    TNode* pNode = List;

    if (pNode == 0) {
        return 0;
    }

    //einwickeln
    len = 1 + LengthRecursive(pNode->pNext);
    // auswickeln
    return len;
}

double AvgElementsRecursive(TList pList, int depth) {
    TNode* pNode = pList;
    static int sum = 0;
    static int cnt = 0;

    if (pNode == 0) {
        return 0.0;
    }

    sum += pNode->data;
    cnt++;
    depth++; // Rekursionstiefe mitführen, damit man letzten Rückruf erkennt

    AvgElementsRecursive(pNode->pNext, depth);

    depth--;
    if (depth == 0) { // letzter Rückruf: Jetzt Durchschnitt bilden
        double avg = sum*1.0 / cnt;
        sum = 0;
        cnt = 0;// static vars zurücksetzen für nächsten Aufruf
        return avg;
    }
    else {
        return 0.0;
    }
}
