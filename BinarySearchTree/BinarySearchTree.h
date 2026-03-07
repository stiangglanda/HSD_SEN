///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 07.03.2026
// Description : BinarySearchTree header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <cstddef>

struct TTreeNode {
    int Data;
    TTreeNode* pLeft;
    TTreeNode* pRight;
};

TTreeNode* MakeNode (int const Data);

// Check if a value exists in the tree
bool Contains(const TTreeNode* const pRoot, int const Data);

// Delete a node from the tree
void Delete(TTreeNode*& pRoot, int const Data);

// Delete all nodes in the tree
void Flush(TTreeNode*& pRoot);

// Get the height of the tree
int Height(const TTreeNode* const pRoot);

// Count the total nodes in the tree
int CountNodes(const TTreeNode* const pRoot);

// Extract tree elements into an array
void ExtractToArray(const TTreeNode* const pRoot, int* const pArray, size_t const Size);

// Insert a value into the tree
void InsertSorted(TTreeNode*& pRoot, int const Data);

// Print tree in in-order traversal
void PrintInOrder(const TTreeNode* const pRoot);

// Print tree in post-order traversal
void PrintPostOrder(const TTreeNode* const pRoot);

// Print tree in pre-order traversal
void PrintPreOrder(const TTreeNode* const pRoot);

// Print the tree structure with indentation
void PrintTree(const TTreeNode* const pRoot, size_t const Indent);

#endif