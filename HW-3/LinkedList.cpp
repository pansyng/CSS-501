//
//  LinkedList.cpp
//  HW3 String Reversal
//
//  Created by Pansy Ng on 10/15/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include "LinkedList.h"
LinkedList::LinkedList(){
    head = NULL;
    size = 0;
}

//Copy constructor (deep copy)
// if the list is null, the Big O Analysis will be O(1).
// if the list is not null, the Big O Analysis will be O(n) since there is a while loop.
LinkedList::LinkedList(LinkedList &list){
    if(list.head == NULL){
        return;
    }
    else{
        head = new ListNode;
        head -> word = list.head -> word;
        ListNode* newNode = head;
        ListNode* oldNode = list.head -> next;
        while(oldNode != NULL){
            newNode -> next = new ListNode;
            newNode = newNode -> next;
            newNode -> word = oldNode -> word;
            oldNode = oldNode -> next;
        }
        newNode -> next = NULL;
        size = list.size;
    }
}

LinkedList::~LinkedList(){
    
    ListNode* current = head;
    while(head != NULL){
        current = head -> next;
        delete head;
        head = current;
    }    
}

//Big O Analysis: O(1) since there is four line
void LinkedList:: add(string w){
    ListNode* node = new ListNode(w);
    node -> next = this -> head;
    this -> head = node;
    size++;
}

void LinkedList::print(){
    if(head == NULL){
        cout << "empty list" << endl;
    }
    else{
        ListNode* current;
        current = head;
        while(current != NULL){
            //current = current -> next;
            cout << current -> word << endl;
            current = current -> next;
        }
    }
}
// The Big O analysis is O(n) because we call the function until we reach the base case.
void LinkedList::reverse_print_recursion(ListNode* node){
    if(node -> next == NULL){
        cout << node -> word << endl;
    }
    else{
        reverse_print_recursion(node -> next);
        cout << node -> word << endl;
        
    }
}

//Big O Analysis: O(n^2) since we have a for loop in the revserse_print_iteration and a while loop in countPrint(int index) function.
void LinkedList::reverse_print_iteration(){
    for(int i = size; i >= 1; i--){
        countPrint(i);
    }
}

void LinkedList:: countPrint(int index){
    int count = 1;
    ListNode* current = head;
    while(current != NULL){
        if(count == index){
            cout << current -> word << endl;
        }
        current = current -> next;
        count++;
    }
}

