///////////////////////////////////////////////////////////////////////////
// Workfile : BinarySearchTree.cpp
// Author : Leander Kieweg
// Date : 07.03.2026
// Description : BinarySearchTree Implementaion
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "BinarySearchTree.h"
#include <new>
#include <iostream>
#include <cassert>

TTreeNode* MakeNode(int const Data) {
    TTreeNode* newNode = new (std::nothrow) TTreeNode;
    if (newNode != nullptr) {
        newNode->Data = Data;
        newNode->pLeft = nullptr;
        newNode->pRight = nullptr;
    }
    assert(newNode != nullptr);
    return newNode;
}

bool Contains(const TTreeNode* const pRoot, int const Data) {
    if (pRoot == nullptr) {
        return false;
    }

    if (Data == pRoot->Data) {
        return true;
    } else if (Data < pRoot->Data) {
        return Contains(pRoot->pLeft, Data);
    } else {
        return Contains(pRoot->pRight, Data);
    }
}

void Delete(TTreeNode*& pRoot, int const Data) {
    if (pRoot == nullptr) {
        return;
    }

    if (Data < pRoot->Data) {
        Delete(pRoot->pLeft, Data);
    } else if (Data > pRoot->Data) {
        Delete(pRoot->pRight, Data);
    } else { // found
        if (pRoot->pLeft == nullptr && pRoot->pRight == nullptr) { // No children
            delete pRoot;
            pRoot = nullptr;
        } else if (pRoot->pLeft == nullptr) { // Right child
            TTreeNode* temp = pRoot;
            pRoot = pRoot->pRight;
            delete temp;
        } else if (pRoot->pRight == nullptr) { // Left child
            TTreeNode* temp = pRoot;
            pRoot = pRoot->pLeft;
            delete temp;
        } else { // Two children
            TTreeNode* pNext = pRoot->pRight;
            while (pNext->pLeft != nullptr) { // minimum node in right subtree
                pNext = pNext->pLeft;
            }

            pRoot->Data = pNext->Data;
            Delete(pRoot->pRight, pNext->Data);
        }
    }
}

void Flush(TTreeNode*& pRoot) {
    if (pRoot != nullptr) {
        Flush(pRoot->pLeft);
        Flush(pRoot->pRight);
        delete pRoot; pRoot = nullptr;
    }
}

int Height(const TTreeNode* const pRoot) {
    if (pRoot == nullptr) {
        return 0;
    }

    int leftHeight = Height(pRoot->pLeft);
    int rightHeight = Height(pRoot->pRight);

    if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    } else {
        return 1 + rightHeight;
    }
}

int CountNodes(const TTreeNode* const pRoot) {
    if (pRoot != nullptr) {
        return 1 + CountNodes(pRoot->pLeft) + CountNodes(pRoot->pRight);
    } else {
        return 0;
    }
}

static void ExtractToArrayRec(const TTreeNode* const pRoot, int* const pArray, size_t const Size, size_t& i) {
    if (pRoot != nullptr && i < Size) {
        ExtractToArrayRec(pRoot->pLeft, pArray, Size, i);
        if (i<Size) {
            pArray[i] = pRoot->Data;
            i++;
        }
        ExtractToArrayRec(pRoot->pRight, pArray, Size, i);
    }
}

void ExtractToArray(const TTreeNode* const pRoot, int* const pArray, size_t const Size) {
    size_t i = 0;
    ExtractToArrayRec(pRoot, pArray, Size, i);
}

void InsertSorted(TTreeNode*& pRoot, int const Data) {
    if (pRoot) {
        if (Data < pRoot->Data) {
            InsertSorted(pRoot->pLeft, Data);
        } else if (Data > pRoot->Data) {
            InsertSorted(pRoot->pRight, Data);
        } else { // value already exists
            return;
        }
    } else {
        pRoot = MakeNode(Data);
    }
}

// L-W-R
void PrintInOrder(const TTreeNode* const pRoot) {
    if (pRoot != nullptr) {
        PrintInOrder(pRoot->pLeft);
        std::cout << pRoot->Data << std::endl;
        PrintInOrder(pRoot->pRight);
    }
}

// L-R-W
void PrintPostOrder(const TTreeNode* const pRoot) {
    if (pRoot != nullptr) {
        PrintPostOrder(pRoot->pLeft);
        PrintPostOrder(pRoot->pRight);
        std::cout << pRoot->Data << std::endl;
    }
}

// W-L-R
void PrintPreOrder(const TTreeNode* const pRoot) {
    if (pRoot != nullptr) {
        std::cout << pRoot->Data << std::endl;
        PrintPreOrder(pRoot->pLeft);
        PrintPreOrder(pRoot->pRight);
    }
}

void PrintTree(const TTreeNode* const pRoot, size_t const Indent) {
    if (pRoot != nullptr) {
        PrintTree(pRoot->pRight, Indent + 4);
        for (size_t i = 0; i < Indent; ++i) {
            std::cout << " ";
        }
        std::cout << pRoot->Data << std::endl;
        PrintTree(pRoot->pLeft, Indent + 4);
    }
}
