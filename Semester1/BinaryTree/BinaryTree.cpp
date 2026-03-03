#include "BinaryTree.h"
#include <new>
#include <iostream>
#include <cassert>

// Hilfsfunktion
TTreeNode* MakeNode(int const Data) {
    TTreeNode* root = new (std::nothrow)TTreeNode(Data, nullptr, nullptr);
    assert(root != nullptr);
    return root;
}

//Wert einlesen
int const GetData() {
    int data = 0;
    std::cout << " Knoten: ";
    std::cin >> data;
    return data;
}

TTreeNode* Tree(size_t const Size) {
    TTreeNode* pNode = nullptr;

    if (Size > 0) {
        pNode = MakeNode(GetData());
        pNode->pLeft = Tree(Size/2);
        pNode->pRight = Tree(Size-Size/2-1);
    }
    return pNode;
}

void Flush(TTreeNode*& pRoot) {
    if (pRoot != nullptr) {
        Flush(pRoot->pLeft);
        Flush(pRoot->pRight);

        std::cout << "freeing " << pRoot->Data << std::endl;
        delete pRoot; pRoot = nullptr;
    }
}

// L-W-R
void PrintInOrder(TTreeNode* pRoot) {
    if (pRoot != nullptr) {
        PrintInOrder(pRoot->pLeft);
        std::cout << pRoot->Data << std::endl;
        PrintInOrder(pRoot->pRight);
    }
}

// W-L-R
void PrintPreOrder(TTreeNode *pRoot) {
    if (pRoot != nullptr) {
        std::cout << pRoot->Data << std::endl;
        PrintPreOrder(pRoot->pLeft);
        PrintPreOrder(pRoot->pRight);
    }
}

// L-R-W
void PrintPostOrder(TTreeNode *pRoot) {
    if (pRoot != nullptr) {
        PrintPostOrder(pRoot->pLeft);
        PrintPostOrder(pRoot->pRight);
        std::cout << pRoot->Data << std::endl;
    }
}
