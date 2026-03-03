#include <iostream>
#include "BinaryTree.h"

int main() {
    std::cout << "Eingabe: " << std::endl;
    TTreeNode* pRoot = Tree(10); //fragt 10 Elemente vom Benutzer ab
    std::cout << "PrintInOrder L-W-R" << std::endl;
    PrintInOrder(pRoot);
    std::cout << "PrintPreOrder W-L-R" << std::endl;
    PrintPreOrder(pRoot);
    std::cout << "PrintPostOrder L-R-W" << std::endl;
    PrintPostOrder(pRoot);
    std::cout << std::endl;
    Flush(pRoot);
    return 0;
}