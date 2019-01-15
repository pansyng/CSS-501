//
//  main.cpp
//  HW 7 Tree Traversals
//
//  Created by Pansy Ng on 11/27/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include <iostream>

#include "Node.h"
#include "BinaryTree.h"
using namespace std;
int main(int argc, const char * argv[]) {
    // A "left-unbalanced" tree to traverse
    BinaryTree tree1;
    tree1.insert(9);
    tree1.insert(8);
    tree1.insert(7);
    tree1.insert(6);
    tree1.insert(5);
    tree1.insert(4);
    tree1.insert(3);
    tree1.insert(2);
    tree1.insert(1);
    tree1.insert(0);
    cout << "left-unbalanced tree "<< endl;
    tree1.preOrder();
    tree1.inOrder();
    tree1.postOrder();
    cout << tree1.breadthFirstSearch(3) << endl;
    // A "right-unbalanced" tree to traverse
    BinaryTree tree;
    tree.insert(0);
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    cout << "right-unbalanced tree "<< endl;
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    cout << tree.breadthFirstSearch(10) << endl;;
    //A "symmetrical" trees to traverse
    BinaryTree tree2;
    tree2.insert(100);
    tree2.insert(50);
    tree2.insert(25);
    tree2.insert(200);
    tree2.insert(225);
    tree2.insert(150);
    tree2.insert(75);
    tree2.insert(0);
    tree2.insert(45);
    tree2.insert(125);
    tree2.insert(175);
    cout << "symmetrical tree" << endl;
    tree2.preOrder();
    tree2.inOrder();
    tree2.postOrder();
    cout << tree2.breadthFirstSearch(25) << endl;
    return 0;
}
