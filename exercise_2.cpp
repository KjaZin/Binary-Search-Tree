#include <iostream>
#include "BinarySearchTree.h"
#include "Node.h"

int main() 
{
    BinarySearchTree Tree(7);
    Node* root = Tree.getroot();
    Tree.insert(root,9);
    Tree.insert(root,11);
    Tree.insert(root, 8);
    Tree.insert(root, 5);
    Tree.insert(root, 1);
    Tree.insert(root, 6);
    std::cout << Tree.levelOrderTraverse() << std::endl;
    std::cout << Tree.printTree() << std::endl;

    return 0;
}