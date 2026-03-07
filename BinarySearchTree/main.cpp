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

int const GetData() {
    int data = 0;
    std::cout << "Enter Number: ";
    std::cin >> data;
    return data;
}

int main() {
    const int NodeCnt = 6;
    int* NodeArray = new int[NodeCnt];

    std::cout << "Eingabe: " << std::endl;
    TTreeNode* pRoot = MakeNode(GetData());
    for (int i = 0; i < NodeCnt-1; i++) {
        InsertSorted(pRoot, GetData());
    }

    std::cout << "PrintInOrder L-W-R:" << std::endl;
    PrintInOrder(pRoot);
    std::cout << "PrintPreOrder W-L-R:" << std::endl;
    PrintPreOrder(pRoot);
    std::cout << "PrintPostOrder L-R-W:" << std::endl;
    PrintPostOrder(pRoot);
    std::cout << "PrintTree:" << std::endl;
    PrintTree(pRoot,0);

    int CntNodes=CountNodes(pRoot);
    std::cout << "CountNodes: " << CntNodes << std::endl;
    ExtractToArray(pRoot, NodeArray, CntNodes);

    for (int i = 0; i < CntNodes; ++i) {
        std::cout << NodeArray[i] << " ";
    }

    std::cout << std::endl << "Height: " << Height(pRoot) << std::endl;
    std::cout << "Contains 6: " << Contains(pRoot, 6) << std::endl;
    std::cout << "Delete 6: " << std::endl;
    Delete(pRoot, 6);
    std::cout << "Contains 6: " << Contains(pRoot, 6) << std::endl;

    std::cout << std::endl;
    Flush(pRoot);
    std::cout << "CountNodes: " << CountNodes(pRoot) << std::endl;
    delete[] NodeArray;
    return 0;
}
