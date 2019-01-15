//
//  Tree.cpp
//  HW 7 Tree Traversals
//
//  Created by Pansy Ng on 12/2/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include <iostream>

#include "BinaryTree.h"
#include "Node.h"

using namespace std;
// insert helper method
void BinaryTree::insert(Node* node, int value){
    if(value < node -> getData()){
        if(node -> left != NULL){
            insert(node -> left, value);
        }
        else{
            node -> left = new Node(value);
        }
    }
    else{
        if(value > node -> getData()){
            if(node -> right != NULL){
                insert(node -> right, value);
            }
            else{
                node -> right = new Node(value);
            }
        }
    }
}

//pre-order helper method
void BinaryTree::preOrder(Node* node){
    if(node == NULL){
        return;
    }
    cout << node -> getData() << " ";
    preOrder(node -> left);
    preOrder(node -> right);
}

//in-order helper method
void BinaryTree::inOrder(Node* node){
    if(node == NULL){
        return;
    }
    inOrder(node -> left);
    cout << node -> getData() << " ";
    inOrder(node -> right);
}

//post-order helper method
void BinaryTree::postOrder(Node* node){
    if(node == NULL){
        return;
    }
    postOrder(node -> left);
    postOrder(node -> right);
    cout << node -> getData() << " ";
}

//constructor
BinaryTree::BinaryTree(){
    root = NULL;
}

//insert method
void BinaryTree::insert(int value){
    if(root == NULL){
        root = new Node(value);
    }
    else{
        insert(root, value);
    }
}

//pre-order traversal
void BinaryTree::preOrder(){
    cout << "pre-Order: " << endl;
    preOrder(root);
    cout << "" << endl;
}

//in-order traversal
void BinaryTree::inOrder(){
    cout << "In-Order: " << endl;
    inOrder(root);
    cout << "" << endl;
}

//post-order traversal
void BinaryTree::postOrder(){
    cout << "post-Order: " << endl;
    postOrder(root);
    cout << "" << endl;
}

//extra credit: breadth-first search method
bool BinaryTree::breadthFirstSearch(int value){
    cout << "breadth-first Search: " << endl;
    list.push_back(root);
    while(!list.empty()){
        Node* node = list[0];
        if(node != NULL){
            if(node -> getData() == value){
                return true;
            }

            list.erase(list.begin());
            if(node -> left != NULL){
                list.push_back(node -> left);
            }
            if(node -> right != NULL){
                list.push_back(node -> right);
            }
        }
    }
    return false;
}
    
