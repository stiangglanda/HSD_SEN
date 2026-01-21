#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstddef>

struct TTreeNode {
    int Data;
    TTreeNode* pLeft;
    TTreeNode* pRight;
};

//rekursives Erzeugen eines Binär-Baum(kein Suchbaum!!)
TTreeNode* Tree(size_t const Size);

//gesamter Baum freigeben
void Flush(TTreeNode*& pRoot);

void PrintInOrder(TTreeNode* pRoot);
void PrintPreOrder(TTreeNode* pRoot);
void PrintPostOrder(TTreeNode* pRoot);

#endif