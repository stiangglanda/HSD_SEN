///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 07.03.2026
// Description : BinarySearchTree Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "BinarySearchTree.h"

int main() {
    TTreeNode* pRoot = nullptr;
    int values[] = {10, 5, 15, 3, 7, 12, 18, 10}; // 10 is duplicate

    for (int v : values) {
        std::cout << "Inserting: " << v << std::endl;
        InsertSorted(pRoot, v);
    }

    std::cout << "Print Tree:" << std::endl;
    PrintTree(pRoot, 0);

    std::cout << "In-Order (Sorted): ";
    PrintInOrder(pRoot);
    std::cout << std::endl;
    std::cout << "Pre-Order: ";
    PrintPreOrder(pRoot);
    std::cout << std::endl;
    std::cout << "Post-Order: ";
    PrintPostOrder(pRoot);
    std::cout << std::endl;

    int count = CountNodes(pRoot);
    int height = Height(pRoot);
    std::cout << "Node Count (expected 7, duplicate ignored): " << count << std::endl;
    std::cout << "Height (expected 3): " << height << std::endl;

    std::cout << "ExtractToArray" << std::endl;
    int* arr = new int[count];
    ExtractToArray(pRoot, arr, count);

    std::cout << "Array Content: ";
    for(int i=0; i<count; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    delete[] arr;

    std::cout << "Contains 7 (Yes): " << (Contains(pRoot, 7) ? "true" : "false") << std::endl;
    std::cout << "Contains 99 (No): " << (Contains(pRoot, 99) ? "true" : "false") << std::endl;

    std::cout << "Delete Case 1: Leaf (3)" << std::endl;
    Delete(pRoot, 3);
    PrintInOrder(pRoot);
    std::cout << std::endl;

    std::cout << "Delete Case 2: One Child" << std::endl;
    InsertSorted(pRoot, 13);
    std::cout << "Inserted 13. Deleting 12 (right child 13)" << std::endl;
    Delete(pRoot, 12);
    PrintTree(pRoot, 0);

    std::cout << "Delete Case 3: Two Children (Root 10)" << std::endl;
    std::cout << "Deleting 10. Successor should be 13 (min of right subtree)." << std::endl;
    Delete(pRoot, 10);
    PrintTree(pRoot, 0);

    std::cout << "New Root Data: " << pRoot->Data << std::endl;

    std::cout << "Flush" << std::endl;
    Flush(pRoot);
    std::cout << "Tree flushed. Root is nullptr: " << (pRoot == nullptr ? "true" : "false") << std::endl;
    std::cout << "CountNodes: " << CountNodes(pRoot) << std::endl;

    return 0;
}

