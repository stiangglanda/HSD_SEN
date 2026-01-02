///////////////////////////////////////////////////////////////////////////
// Workfile : DoublyConnectedList.h
// Author : Leander Kieweg
// Date : 01. 01. 2026
// Description : DoublyConnectedList Module Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#ifndef DOUBLYCONNECTEDLIST_H
#define DOUBLYCONNECTEDLIST_H

#include <cstddef>

struct TNode {
    int data; // Der gespeicherte Wert.
    TNode * pNext; // Zeiger auf den Nachfolger.
    TNode * pPrev; // Zeiger auf den Vorgänger.
};

struct TList {
    TNode * pHead; // Zeiger auf den ersten Knoten.
    TNode * pTail; // Zeiger auf den letzten Knoten.
    size_t size; // Die Anzahl der Knoten.
    bool isSorted; // Liste ist aufsteigend sortiert.
};

void clear (TList& list);
bool consistent (TList& list);
size_t count (TList& list, int data);
bool empty (TList& list);
bool erase (TList& list, int data);
size_t erase_all (TList& list, int data);
void erase_lower (TList& list, int limit);
void init (TList& list);
void insert_after (TList& list, int data, TNode* pNode);
void insert_before (TList& list, int data, TNode* pNode);
TNode * insert_sorted (TList& list, int data);
TNode * make_node (int data);
void print (TList& list, bool reverse);
void push_back (TList& list, int data);
void push_front (TList& list, int data);
void rotate_left (TList& list);
void rotate_right (TList& list);
TNode * search_first (TList& list, int data);
TNode * search_last (TList& list, int data);
size_t size (TList& list);
void sort (TList& list);
bool sorted (TList& list);
bool valid_node (TList& list, TNode* pNode);

#endif