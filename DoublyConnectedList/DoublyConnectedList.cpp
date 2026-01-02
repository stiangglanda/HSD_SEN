///////////////////////////////////////////////////////////////////////////
// Workfile : DoublyConnectedList.cpp
// Author : Leander Kieweg
// Date : 01. 01. 2026
// Description : DoublyConnectedList Module Implementation
// Remarks :
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include "DoublyConnectedList.h"
#include <iostream>

using namespace std;

static bool is_sorted(TList& list) {
    if (list.size < 2) {
        return true;
    } else {
        int     data  = list.pHead->data;
        TNode * pNode = list.pHead->pNext;

        while ((pNode != nullptr) && (data <= pNode->data)) {
            data  = pNode->data;
            pNode = pNode->pNext;
        }

        return pNode == nullptr;
    }
}

TNode* make_node(int data) {
    TNode* newNode = new TNode;
    newNode->data = data;
    newNode->pNext = nullptr;
    newNode->pPrev = nullptr;
    return newNode;
}

bool valid_node(TList& list, TNode* pNode) {
    if (pNode == nullptr) {
        return true;
    }

    TNode* current = list.pHead;
    while (current != nullptr) {
        if (current == pNode) {
            return true;
        }
        current = current->pNext;
    }
    return false;
}

void init(TList& list) {
    list.pHead = nullptr;
    list.pTail = nullptr;
    list.size = 0;
    list.isSorted = true; // Leere Menge ist sortiert
}

void clear(TList& list) {
    TNode* current = list.pHead;
    while (current != nullptr) {
        TNode* nextNode = current->pNext;
        delete current;
        current = nextNode;
    }

    list.pHead = nullptr;
    list.pTail = nullptr;
    list.size = 0;
    list.isSorted = true;
}

bool consistent (TList& list) {
    if (list.size == 0) {
        return (list.pHead == nullptr) && (list.pTail == nullptr) && list.isSorted;
    } else {
        if (list.pHead->pPrev != nullptr) return false;
        if (list.pTail->pNext != nullptr) return false;

        if (list.size == 1) {
            return (list.pHead == list.pTail) && list.isSorted;
        } else {
            TNode * pNode = list.pHead;

            for (size_t i = 1; i < list.size; ++i) {   // don't trust the pointers
                if (pNode->pNext->pPrev != pNode) {
                    return false;
                }

                pNode = pNode->pNext;
            }

            return (pNode == list.pTail) && (list.isSorted == is_sorted (list));
        }
    }

    return false;
}

size_t count(TList& list, int data) {
    size_t counter = 0;
    TNode* current = list.pHead;
    while (current != nullptr) {
        if (current->data == data) {
            counter++;
        }
        current = current->pNext;
    }
    return counter;
}

bool empty(TList& list) {
    return list.size == 0;
}

bool erase(TList& list, int data) {
    TNode* current = list.pHead;

    while (current != nullptr) {
        if (current->data == data) {
            // Unlink
            if (current->pPrev != nullptr) {
                current->pPrev->pNext = current->pNext;
            } else {
                list.pHead = current->pNext;
            }

            if (current->pNext != nullptr) {
                current->pNext->pPrev = current->pPrev;
            } else {
                list.pTail = current->pPrev;
            }

            delete current;
            list.size--;

            // Optimierung: Wenn die Liste vorher sortiert war, ist sie es jetzt immer noch.
            // Nur wenn sie unsortiert war, prüfen wir neu (außer sie ist jetzt leer/einzeln).
            if (!list.isSorted) {
                list.isSorted = is_sorted(list);
            }
            // Ansonsten bleibt list.isSorted = true;

            return true;
        }
        current = current->pNext;
    }

    return false;
}

size_t erase_all(TList& list, int data) {
    size_t deletedCount = 0;
    TNode* current = list.pHead;

    while (current != nullptr) {
        TNode* nextNode = current->pNext;

        if (current->data == data) {
            // Unlink
            if (current->pPrev != nullptr) {
                current->pPrev->pNext = current->pNext;
            } else {
                list.pHead = current->pNext;
            }

            if (current->pNext != nullptr) {
                current->pNext->pPrev = current->pPrev;
            } else {
                list.pTail = current->pPrev;
            }

            delete current;
            list.size--;
            deletedCount++;
        }
        current = nextNode;
    }

    // Auch hier: Löschen zerstört die Sortierung nicht.
    if (!list.isSorted) {
        list.isSorted = is_sorted(list);
    }

    return deletedCount;
}

void erase_lower(TList& list, int limit) {
    TNode* current = list.pHead;

    while (current != nullptr) {
        TNode* nextNode = current->pNext;

        if (current->data < limit) {
            if (current->pPrev != nullptr) {
                current->pPrev->pNext = current->pNext;
            } else {
                list.pHead = current->pNext;
            }

            if (current->pNext != nullptr) {
                current->pNext->pPrev = current->pPrev;
            } else {
                list.pTail = current->pPrev;
            }

            delete current;
            list.size--;
        }
        current = nextNode;
    }

    if (!list.isSorted) {
        list.isSorted = is_sorted(list);
    }
}

void insert_after(TList& list, int data, TNode* pNode) {
    // 1. Validierung
    if (pNode == nullptr || !valid_node(list, pNode)) {
        return;
    }

    // 2. Erstellung (Reuse)
    TNode* newNode = make_node(data);

    // 3. Verlinkung
    newNode->pPrev = pNode;
    newNode->pNext = pNode->pNext;

    if (pNode->pNext != nullptr) {
        pNode->pNext->pPrev = newNode;
    } else {
        list.pTail = newNode; // War Tail
    }
    pNode->pNext = newNode;

    list.size++;

    // 4. Sortierung
    // Um sicher zu gehen (und Spaghetti-Code zu vermeiden), prüfen wir komplett.
    // Optimierung wäre möglich, aber fehleranfällig in der Kürze.
    list.isSorted = is_sorted(list);
}

void insert_before(TList& list, int data, TNode* pNode) {
    // 1. Validierung
    if (pNode == nullptr || !valid_node(list, pNode)) {
        return;
    }

    // 2. Erstellung (Reuse)
    TNode* newNode = make_node(data);

    // 3. Verlinkung
    newNode->pNext = pNode;
    newNode->pPrev = pNode->pPrev;

    if (pNode->pPrev != nullptr) {
        pNode->pPrev->pNext = newNode;
    } else {
        list.pHead = newNode; // War Head
    }
    pNode->pPrev = newNode;

    list.size++;

    // 4. Sortierung
    list.isSorted = is_sorted(list);
}

TNode* insert_sorted(TList& list, int data) {
    // Falls Liste leer ist oder am Anfang eingefügt werden muss
    if (list.pHead == nullptr || data <= list.pHead->data) {
        // Hier können wir push_front Logik nutzen, aber wir brauchen den Rückgabewert.
        // Also bauen wir es mit make_node sauber auf.
        TNode* newNode = make_node(data);
        newNode->pNext = list.pHead;

        if (list.pHead != nullptr) {
            list.pHead->pPrev = newNode;
        } else {
            list.pTail = newNode;
        }
        list.pHead = newNode;

        list.size++;
        list.isSorted = is_sorted(list);
        return newNode;
    }

    // Suche Einfügeposition
    TNode* current = list.pHead;
    while (current != nullptr && current->data < data) {
        current = current->pNext;
    }

    if (current == nullptr) {
        // Einfügen am Ende
        TNode* newNode = make_node(data);
        newNode->pPrev = list.pTail;
        if (list.pTail != nullptr) {
            list.pTail->pNext = newNode;
        }
        list.pTail = newNode;
        list.size++;
        list.isSorted = is_sorted(list);
        return newNode;
    } else {
        // Einfügen vor current
        // Da wir insert_before haben und current sicher valide ist:
        insert_before(list, data, current);
        // insert_before erhöht size und checkt sorted
        return current->pPrev; // Der neue Knoten ist jetzt vor current
    }
}

void print(TList& list, bool reverse) {
    cout << "<";
    TNode* current;

    if (!reverse) {
        current = list.pHead;
        while (current != nullptr) {
            cout << current->data;
            if (current->pNext != nullptr) cout << ", ";
            current = current->pNext;
        }
    } else {
        current = list.pTail;
        while (current != nullptr) {
            cout << current->data;
            if (current->pPrev != nullptr) cout << ", ";
            current = current->pPrev;
        }
    }
    cout << ">";
}

void push_back(TList& list, int data) {
    TNode* newNode = make_node(data);
    newNode->pPrev = list.pTail;

    if (list.pTail != nullptr) {
        list.pTail->pNext = newNode;
    } else {
        list.pHead = newNode;
    }
    list.pTail = newNode;
    list.size++;

    // Check sorted: Wenn sortiert UND data >= Vorgänger -> bleibt sortiert
    if (list.isSorted) {
        if (list.size > 1 && newNode->pPrev->data > data) {
            list.isSorted = false;
        }
        // Sonst bleibt true
    }
}

void push_front(TList& list, int data) {
    TNode* newNode = make_node(data);
    newNode->pNext = list.pHead;

    if (list.pHead != nullptr) {
        list.pHead->pPrev = newNode;
    } else {
        list.pTail = newNode;
    }
    list.pHead = newNode;
    list.size++;

    // Check sorted: Wenn sortiert UND data <= Nachfolger -> bleibt sortiert
    if (list.isSorted) {
        if (list.size > 1 && newNode->pNext->data < data) {
            list.isSorted = false;
        }
    }
}

void rotate_left(TList& list) {
    if (list.size < 2) return;

    TNode* firstNode = list.pHead;

    list.pHead = firstNode->pNext;
    list.pHead->pPrev = nullptr;

    list.pTail->pNext = firstNode;
    firstNode->pPrev = list.pTail;
    firstNode->pNext = nullptr;

    list.pTail = firstNode;

    list.isSorted = is_sorted(list);
}

void rotate_right(TList& list) {
    if (list.size < 2) return;

    TNode* lastNode = list.pTail;

    list.pTail = lastNode->pPrev;
    list.pTail->pNext = nullptr;

    lastNode->pNext = list.pHead;
    list.pHead->pPrev = lastNode;
    lastNode->pPrev = nullptr;

    list.pHead = lastNode;

    list.isSorted = is_sorted(list);
}

TNode* search_first(TList& list, int data) {
    TNode* current = list.pHead;
    while (current != nullptr) {
        if (current->data == data) return current;
        current = current->pNext;
    }
    return nullptr;
}

TNode* search_last(TList& list, int data) {
    TNode* current = list.pTail;
    while (current != nullptr) {
        if (current->data == data) return current;
        current = current->pPrev;
    }
    return nullptr;
}

size_t size(TList& list) {
    return list.size;
}

void sort(TList& list) {
    if (list.isSorted || list.size < 2) return;

    // Strategie: Elemente in Hilfsliste sortiert einfügen
    TList sortedList;
    init(sortedList);

    TNode* current = list.pHead;
    while (current != nullptr) {
        insert_sorted(sortedList, current->data);
        current = current->pNext;
    }

    // Alte Liste leeren (Memory freigeben für die alten Knoten)
    clear(list);

    // sortedList übernehmen
    list.pHead = sortedList.pHead;
    list.pTail = sortedList.pTail;
    list.size = sortedList.size;
    list.isSorted = true;

    // sortedList leeren (nur Init, da Pointer jetzt in list liegen)
    // Wir dürfen sortedList NICHT clearen, sonst sind die Daten weg!
    // Wir setzen sie nur zurück, damit der Destruktor (falls vorhanden) nichts macht.
    init(sortedList);
}

bool sorted(TList& list) {
    return list.isSorted;
}