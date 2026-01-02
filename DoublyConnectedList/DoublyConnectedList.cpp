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

static bool is_sorted (TList& list) {
    if (list.size < 2) {
        return true;
    } else {
        int data  = list.pHead->data;
        TNode* pNode = list.pHead->pNext;

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

    list.pHead = nullptr;
    list.pTail = nullptr;
    list.size = 0;
    list.isSorted = true; // empty list is sorted
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
            // Unlink from the previous node or update head
            if (current->pPrev != nullptr) {
                current->pPrev->pNext = current->pNext;
            } else {
                list.pHead = current->pNext;
            }

            // Unlink from the next node or update tail
            if (current->pNext != nullptr) {
                current->pNext->pPrev = current->pPrev;
            } else {
                list.pTail = current->pPrev;
            }

            delete current;
            list.size--;

            // Recompute sorted flag (fast-path for tiny lists)
            list.isSorted = (list.size < 2) ? true : is_sorted(list);

            return true;
        }
        current = current->pNext;
    }

    return false;
}

size_t erase_all(TList& list, int data) {
    size_t count = 0;
    TNode* current = list.pHead;

    while (current != nullptr) {
        TNode* nextNode = current->pNext; // Save next node before deletion

        if (current->data == data) {
            // Unlink from previous node or update head
            if (current->pPrev != nullptr) {
                current->pPrev->pNext = current->pNext;
            } else {
                list.pHead = current->pNext;
            }

            // Unlink from next node or update tail
            if (current->pNext != nullptr) {
                current->pNext->pPrev = current->pPrev;
            } else {
                list.pTail = current->pPrev;
            }

            delete current;
            list.size--;
            count++;
        }
        current = nextNode;
    }

    // Recompute sorted flag (fast-path for tiny lists)
    list.isSorted = (list.size < 2) ? true : is_sorted(list);

    return count;
}

void erase_lower(TList & list, int limit) {
    TNode* current = list.pHead;

    while (current != nullptr) {
        TNode* nextNode = current->pNext; // Save next node before potential deletion

        if (current->data < limit) {
            // Unlink from previous node or update head
            if (current->pPrev != nullptr) {
                current->pPrev->pNext = current->pNext;
            } else {
                list.pHead = current->pNext;
            }

            // Unlink from next node or update tail
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

    // Recompute sorted flag (fast-path for tiny lists)
    list.isSorted = (list.size < 2) ? true : is_sorted(list);
}

void init(TList& list) {
    list.pHead = nullptr;
    list.pTail = nullptr;
    list.size = 0;
    list.isSorted = true;
}

void insert_after(TList& list, int data, TNode* pNode) {
    if (!valid_node(list, pNode)) {
        return;
    }

    if (pNode == nullptr) {
        return;
    }

    TNode* newNode = make_node(data);

    newNode->pPrev = pNode;
    newNode->pNext = pNode->pNext;

    if (pNode->pNext != nullptr) {
        pNode->pNext->pPrev = newNode;
    } else {
        list.pTail = newNode;
    }
    pNode->pNext = newNode;

    list.size++;

    if (list.isSorted) {
        bool orderMaintained = (pNode->data <= data);
        if (newNode->pNext) {
            orderMaintained = orderMaintained && (data <= newNode->pNext->data);
        }

        if (!orderMaintained) list.isSorted = false;
    }
}

void insert_before(TList& list, int data, TNode* pNode) {
    if (pNode == nullptr) {
        return;
    }

    // Verify that pNode is actually in the list
    TNode* current = list.pHead;
    bool found = false;
    while (current != nullptr) {
        if (current == pNode) {
            found = true;
            break;
        }
        current = current->pNext;
    }

    if (!found) {
        return;
    }

    // Create new node
    TNode* newNode = new TNode;
    newNode->data = data;
    newNode->pNext = pNode;
    newNode->pPrev = pNode->pPrev;

    // Link new node into the list
    if (pNode->pPrev != nullptr) {
        pNode->pPrev->pNext = newNode;
    } else {
        // pNode was the head, so newNode becomes the new head
        list.pHead = newNode;
    }
    pNode->pPrev = newNode;

    list.size++;

    // Check if the list is still sorted
    list.isSorted = is_sorted(list);
}

TNode* insert_sorted(TList& list, int data) {
    TNode* newNode = new TNode;
    newNode->data = data;
    newNode->pNext = nullptr;
    newNode->pPrev = nullptr;

    if (list.pHead == nullptr) {
        // Case: List is empty
        list.pHead = newNode;
        list.pTail = newNode;
    } else if (data <= list.pHead->data) {
        // Case: Insert before head
        newNode->pNext = list.pHead;
        list.pHead->pPrev = newNode;
        list.pHead = newNode;
    } else {
        TNode* current = list.pHead;
        // Find the first node that is greater than or equal to data
        while (current != nullptr && current->data < data) {
            current = current->pNext;
        }

        if (current == nullptr) {
            // Case: Insert at tail (data is larger than all existing elements)
            newNode->pPrev = list.pTail;
            list.pTail->pNext = newNode;
            list.pTail = newNode;
        } else {
            // Case: Insert before current node
            // Since we handled the head case separately, current->pPrev is guaranteed to exist
            newNode->pNext = current;
            newNode->pPrev = current->pPrev;
            current->pPrev->pNext = newNode;
            current->pPrev = newNode;
        }
    }

    list.size++;
    list.isSorted = is_sorted(list);

    return newNode;
}

TNode* make_node(int data) {
    TNode* newNode = new TNode;
    newNode->data = data;
    newNode->pNext = nullptr;
    newNode->pPrev = nullptr;
    return newNode;
}

void print(TList& list, bool reverse) {
    cout << "<";
    TNode* current;

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
    TNode* newNode = new TNode;
    newNode->data = data;
    newNode->pNext = nullptr;
    newNode->pPrev = list.pTail;

    if (list.pTail != nullptr) {
        list.pTail->pNext = newNode;
    } else {
        // List was empty, so new node is also the head
        list.pHead = newNode;
    }

    list.pTail = newNode;
    list.size++;

    list.isSorted = is_sorted(list);
}

void push_front(TList& list, int data) {
    TNode* newNode = new TNode;
    newNode->data = data;
    newNode->pPrev = nullptr;
    newNode->pNext = list.pHead;

    if (list.pHead != nullptr) {
        list.pHead->pPrev = newNode;
    } else {
        // List was empty, so new node is also the tail
        list.pTail = newNode;
    }

    list.pHead = newNode;
    list.size++;

    list.isSorted = is_sorted(list);
}

void rotate_left(TList& list) {
    // Rotation is only possible/necessary if the list has at least 2 elements
    if (list.size < 2) {
        return;
    }

    TNode* firstNode = list.pHead;

    // The second node becomes the new head
    list.pHead = firstNode->pNext;
    list.pHead->pPrev = nullptr;

    // The original first node is attached to the end of the list
    list.pTail->pNext = firstNode;
    firstNode->pPrev = list.pTail;
    firstNode->pNext = nullptr;

    // The original first node becomes the new tail
    list.pTail = firstNode;

    // Rotating usually breaks the sort order, so we must re-check
    list.isSorted = is_sorted(list);
}

void rotate_right(TList& list) {
    // Rotation is only possible/necessary if the list has at least 2 elements
    if (list.size < 2) {
        return;
    }

    TNode* lastNode = list.pTail;

    // The second to last node becomes the new tail
    list.pTail = lastNode->pPrev;
    list.pTail->pNext = nullptr;

    // The original last node is attached to the beginning of the list
    lastNode->pNext = list.pHead;
    list.pHead->pPrev = lastNode;
    lastNode->pPrev = nullptr;

    // The original last node becomes the new head
    list.pHead = lastNode;

    // Rotating usually breaks the sort order, so we must re-check
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
    // If the list is already sorted or has fewer than 2 elements, no work is needed
    if (list.isSorted || list.size < 2) {
        return;
    }

    TList sortedList;
    init(sortedList);

    TNode* current = list.pHead;
    while (current != nullptr) {
        // Insert data into the helper list, which handles the sorting logic
        insert_sorted(sortedList, current->data);
        current = current->pNext;
    }

    // Clear the original list to release the old nodes
    clear(list);

    // Move the sorted nodes from the helper list to the original list
    list.pHead = sortedList.pHead;
    list.pTail = sortedList.pTail;
    list.size = sortedList.size;
    list.isSorted = true;
}

bool sorted(TList& list) {
    return list.isSorted;
}

bool valid_node(TList& list, TNode * pNode) {
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