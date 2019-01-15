//
//  Tree.hpp
//  HW 7 Tree Traversals
//
//  Created by Pansy Ng on 12/2/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <vector>
#include "Node.h"
using namespace std;
class BinaryTree{
private:
    Node* root;
    vector<Node*> list;
    void insert(Node* node, int value);
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);
    
public:
    BinaryTree();
    void insert(int value);
    void preOrder();
    void inOrder();
    void postOrder();
    bool breadthFirstSearch(int value);
    
};
#endif /* Tree_hpp */
