//
//  LinkedList.hpp
//  HW 2 - Searching and sorting
//
//  Created by Pansy Ng on 10/11/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <stdio.h>
#include <iostream>

using namespace std;

// ListNode class
class ListNode{
public:
    string name;
    int quantity;
    ListNode* next;
    ListNode* previous;
    //constructor
    ListNode();
    ListNode(string name, int quantity);
};

// LinkedList class
class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    
    void push_back(ListNode* node);
    bool isEmpty()const;
    void print();
    void SortByQuantity();
    void SortByName();
    void swap(ListNode *x, ListNode *y);
    void descendingSortByQuantity();
    void descendingSortByName();
    ListNode* search(string name);

private:
    ListNode* head;
    ListNode* tail;
    int size;
};

#endif /* LinkedList_hpp */
