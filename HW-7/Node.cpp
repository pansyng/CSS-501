//
//  Node.cpp
//  HW 7 Tree Traversals
//
//  Created by Pansy Ng on 12/2/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include "Node.h"
//constructor
Node::Node(){
    data = 0;
    left = NULL;
    right = NULL;
}

//constructor
Node::Node(int d){
    setData(d);
    left = NULL;
    right = NULL;
}

//getter of data
int Node::getData(){
    return data;
}

//setter of data 
void Node::setData(int data){
    this -> data = data;
}

