//
//  LinkedList.cpp
//  HW 2 - Searching and sorting
//
//  Created by Pansy Ng on 10/11/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include "LinkedList.h"
#include <iostream>
#include <string.h>
using namespace std;

//constructor
ListNode::ListNode(){
    name = "";
    quantity = 0;
}
ListNode::ListNode(string n, int q){
    name = n;
    quantity = q;
}

//constructor
LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}
//destructor
LinkedList::~LinkedList(){
}

//This method will print the list
void LinkedList::print(){
    if(head == NULL){
        cout << "{}" <<endl;
    }
    else{
        ListNode* current;
        current = head;
        cout << "Item\tQuantity"<<endl;
        while(current != NULL){
            cout << current -> name << "\t" << current -> quantity << "\n";
            current = current -> next;
        }
        cout << "" <<endl;
    }
}

//This method add ListNode to the back of the list
void LinkedList::push_back(ListNode* node){
    if(head == NULL){
        this -> head = node;
        this -> tail = node;
        size = 1;
    }
    else{
        this -> tail -> next = node;
        node -> previous = this -> tail;
        this -> tail = node;
        this -> tail -> next = NULL;
        size++;
    }

}

//This method checks the list is empty or not
bool LinkedList::isEmpty() const{
    return head == NULL;
}

//This method sort the quantity of the list in ascending order
// Big-O analysis: O(N^2)
void LinkedList::SortByQuantity(){
    if(head == NULL || head -> next == NULL){
        return;
    }
    else{
        bool i;
        do{
            i = false;
            ListNode *qtr = NULL, *ptr = head;
            while(ptr -> next != qtr){
                if(ptr -> quantity > ptr -> next -> quantity){
                    swap(ptr, ptr -> next);
                    i = 1;
                }
                ptr = ptr -> next;
            }
            qtr = ptr;
        }while (i);
    }
}

//This method sort the name of the list in ascending order
// Big-O analysis: O(N^2)
void LinkedList::SortByName(){
    if(head == NULL || head -> next == NULL){
        return;
    }
    else{
        bool i;
        do{
            i = false;
            ListNode *qtr = NULL, *ptr = head;
            while(ptr -> next != qtr){
                if(strcmp(ptr -> name.c_str(), ptr -> next -> name.c_str()) > 0){
                    swap(ptr, ptr -> next);
                    i = 1;
                }
                ptr = ptr -> next;
            }
            qtr = ptr;
        }while (i);
    }
}


// The method swap the x ListNode and y ListNode inside the LinkedList
void LinkedList::swap(ListNode *x, ListNode *y){
    string temp_name;
    int temp_quantity;
    temp_name = x -> name;
    temp_quantity = x -> quantity;
    x -> name = y -> name;
    x -> quantity = y -> quantity;
    y -> name = temp_name;
    y -> quantity = temp_quantity;
    
}

//This method sort the quantity of the list in descending order
// Big-O analysis: O(N^2)
void LinkedList::descendingSortByQuantity(){
    if(head == NULL || head -> next == NULL){
        return;
    }
    else{
        bool i;
        do{
            i = false;
            ListNode *qtr = NULL, *ptr = head;
            while(ptr -> next != qtr){
                if(ptr -> quantity < ptr -> next -> quantity){
                    swap(ptr, ptr -> next);
                    i = 1;
                }
                ptr = ptr -> next;
            }
            qtr = ptr;
        }while (i);
    }
}

//This method sort the name of the list in descending order 
// Big-O analysis: O(N^2) since there is two while loop
void LinkedList::descendingSortByName(){
    if(head == NULL || head -> next == NULL){
        return;
    }
    else{
        bool i;
        do{
            i = false;
            ListNode *qtr = NULL, *ptr = head;
            while(ptr -> next != qtr){
                if(strcmp(ptr -> name.c_str(), ptr -> next -> name.c_str()) < 0){
                    swap(ptr, ptr -> next);
                    i = 1;
                }
                ptr = ptr -> next;
            }
            qtr = ptr;
        }while (i);
    }
}


//Big O analysis: O(N) since I am using the while loop only
ListNode* LinkedList::search(string n){
    ListNode* temp;
    temp = head;
    while (temp != NULL){
        if (temp -> name == n){
            cout << "Item found and quantity " << temp -> quantity << endl;
            return temp;
        }
        temp = temp -> next;
    }
    cout << "Item not found" << endl;
    return NULL;
}

