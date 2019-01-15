//
//  main.cpp
//  HW3 String Reversal
//
//  Created by Pansy Ng on 10/15/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
#include "ListNode.h"

int main(int argc, const char * argv[]) {
    LinkedList list;
    //10 nodes
    list.add("ptr1");
    list.add("ptr2");
    list.add("ptr3");
    list.add("ptr4");
    list.add("ptr5");
    list.add("ptr6");
    list.add("ptr7");
    list.add("ptr8");
    list.add("ptr9");
    list.add("ptr10");
    
    
    cout << "print list: " << endl;
    list.print();
    // print deep copy
    cout << "print deep copy list: " << endl;
    LinkedList* list1 = new LinkedList(list);
    list1->print();
    // Recursive print
    cout << "print reverse list (recursion): " << endl;
    list.reverse_print_recursion(list.head);
    // Iterative print
    cout << "print reverse list (iteration): " << endl;
    list.reverse_print_iteration();
    cout << list.size <<endl;
};
