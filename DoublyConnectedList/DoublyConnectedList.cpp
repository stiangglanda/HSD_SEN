///////////////////////////////////////////////////////////////////////////
// Workfile : DoublyConnectedList.cpp
// Author : Leander Kieweg
// Date : 01. 01. 2026
// Description : DoublyConnectedList Module Implementation
// Remarks : -
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

void clear(TList& list) {
    TNode* current = list.pHead;
    while (current != nullptr) {
        TNode* nextNode = current->pNext;
        delete current;
        current = nextNode;
    }

    init(list);
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

            // if list was sorted, it still is
            if (!list.isSorted) {
                list.isSorted = is_sorted(list);
            }

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
        TNode* nextNode = current->pNext; // save pNext pointer

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

    // if list was sorted, it still is
    if (!list.isSorted) {
        list.isSorted = is_sorted(list);
    }

    return deletedCount;
}

void erase_lower(TList& list, int limit) {
    TNode* current = list.pHead;

    while (current != nullptr) {
        TNode* nextNode = current->pNext; // save pNext pointer

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

    // if list was sorted, it still is
    if (!list.isSorted) {
        list.isSorted = is_sorted(list);
    }
}

void init(TList& list) {
    list.pHead = nullptr;
    list.pTail = nullptr;
    list.size = 0;
    list.isSorted = true;
}

void insert_after(TList& list, int data, TNode* pNode) {
    if (pNode == nullptr || !valid_node(list, pNode)) {
        return;
    }

    TNode* newNode = make_node(data);
    newNode->pPrev = pNode;
    newNode->pNext = pNode->pNext;

    if (pNode->pNext != nullptr) {
        pNode->pNext->pPrev = newNode;
    } else {
        list.pTail = newNode; // was Tail
    }
    pNode->pNext = newNode;

    list.size++;
    list.isSorted = is_sorted(list);
}

void insert_before(TList& list, int data, TNode* pNode) {
    if (pNode == nullptr || !valid_node(list, pNode)) {
        return;
    }

    TNode* newNode = make_node(data);
    newNode->pNext = pNode;
    newNode->pPrev = pNode->pPrev;

    if (pNode->pPrev != nullptr) {
        pNode->pPrev->pNext = newNode;
    } else {
        list.pHead = newNode; // was Head
    }
    pNode->pPrev = newNode;

    list.size++;
    list.isSorted = is_sorted(list);
}

TNode* insert_sorted(TList& list, int data) {
    if (list.pHead == nullptr || data <= list.pHead->data) {
        // is new Head
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

    // search for position
    TNode* current = list.pHead;
    while (current != nullptr && current->data < data) {
        current = current->pNext;
    }

    if (current == nullptr) { // is new Tail
        TNode* newNode = make_node(data);
        newNode->pPrev = list.pTail;

        if (list.pTail != nullptr) {
            list.pTail->pNext = newNode;
        }
        list.pTail = newNode;
        list.size++;
        list.isSorted = is_sorted(list);
        return newNode;
    }
    else {
        insert_before(list, data, current);
        return current->pPrev;
    }
}

TNode* make_node(int data) {
    TNode* newNode = new TNode;
    newNode->data = data;
    newNode->pNext = nullptr;
    newNode->pPrev = nullptr;
    return newNode;
}

void print(TList& list, bool reverse) {
    TNode* current;

    cout << "<";
    if (!reverse) {
        current = list.pHead;
        while (current != nullptr) {
            cout << current->data;

            if (current->pNext != nullptr) {
                cout << ", ";
            }
            current = current->pNext;
        }
    } else {
        current = list.pTail;
        while (current != nullptr) {
            cout << current->data;

            if (current->pPrev != nullptr) {
                cout << ", ";
            }
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
        list.pHead = newNode; // list is empty
    }
    list.pTail = newNode;
    list.size++;

    // if sorted and data >= prev->data it is still sorted
    if (list.isSorted) {
        if (list.size > 1 && newNode->pPrev->data > data) {
            list.isSorted = false;
        }
    }
}

void push_front(TList& list, int data) {
    TNode* newNode = make_node(data);
    newNode->pNext = list.pHead;

    if (list.pHead != nullptr) {
        list.pHead->pPrev = newNode;
    } else {
        list.pTail = newNode; // list is empty
    }
    list.pHead = newNode;
    list.size++;

    // if sorted and data <= next->data it is still sorted
    if (list.isSorted) {
        if (list.size > 1 && newNode->pNext->data < data) {
            list.isSorted = false;
        }
    }
}

void rotate_left(TList& list) {
    if (list.size < 2) {
        return;
    }

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
    if (list.size < 2) {
        return;
    }

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
        if (current->data == data) {
            return current;
        }
        current = current->pNext;
    }

    return nullptr;
}

TNode* search_last(TList& list, int data) {
    TNode* current = list.pTail;

    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->pPrev;
    }

    return nullptr;
}

size_t size(TList& list) {
    return list.size;
}

void sort(TList& list) {
    if (list.isSorted || list.size < 2) {
        return;
    }

    TList sortedList;
    init(sortedList);

    TNode* current = list.pHead;
    while (current != nullptr) {
        insert_sorted(sortedList, current->data);
        current = current->pNext;
    }

    clear(list);

    list.pHead = sortedList.pHead;
    list.pTail = sortedList.pTail;
    list.size = sortedList.size;
    list.isSorted = true;

    init(sortedList);
}

bool sorted(TList& list) {
    return list.isSorted;
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