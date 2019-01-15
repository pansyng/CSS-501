//
//  main.cpp
//  HW 2 - Searching and sorting
//
//  Created by Pansy Ng on 10/8/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//


#include "LinkedList.h"
#include <iostream>

using namespace std;
/* This program uses the ListNode class and LinkedList class to create grocery list. This grocery list has two sortable property with string name and int quantity {(item, quantity), ...}
 */
int main(int argc, const char * argv[]) {
    LinkedList list;
    string item;
    
    //10 elements
    ListNode* ptr1 = new ListNode("banana", 12);
    ListNode* ptr2 = new ListNode("milk", 2);
    ListNode* ptr3 = new ListNode("bread", 6);
    ListNode* ptr4 = new ListNode("apple", 5);
    ListNode* ptr5 = new ListNode("orange", 5);
    ListNode* ptr6 = new ListNode("soda", 12);
    ListNode* ptr7 = new ListNode("cookies", 3);
    ListNode* ptr8 = new ListNode("chips", 6);
    ListNode* ptr9 = new ListNode("yogurt", 8);
    ListNode* ptr10 = new ListNode("juice", 10);
    
    // add the ListNode to the LinkedList 
    list.push_back(ptr1);
    list.push_back(ptr2);
    list.push_back(ptr3);
    list.push_back(ptr4);
    list.push_back(ptr5);
    list.push_back(ptr6);
    list.push_back(ptr7);
    list.push_back(ptr8);
    list.push_back(ptr9);
    list.push_back(ptr10);
    
    cout << "Print list: " << endl;
    list.print();
    
    cout << "Ascending Sort by quantity: " << endl;
    list.SortByQuantity();
    list.print();
    cout << "Ascending Sort by name: " << endl;
    list.SortByName();
    list.print();
    cout << "Descending Sort by quantity: " << endl;
    list.descendingSortByQuantity();
    list.print();
    cout << "Descending Sort by name: " << endl;
    list.descendingSortByName();
    list.print();
    
    cout << "Search: " << endl;
    cin >> item;
    list.search(item);
    return 0;
}
