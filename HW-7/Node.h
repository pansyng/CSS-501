//
//  Node.hpp
//  HW 7 Tree Traversals
//
//  Created by Pansy Ng on 12/2/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
class Node{
private:
    int data;
public:
    Node* left;
    Node* right;
    Node();
    Node(int d);
    int getData();
    void setData(int data);
};

#endif /* Node_hpp */
