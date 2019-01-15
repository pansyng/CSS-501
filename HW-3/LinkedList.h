//
//  LinkedList.hpp
//  HW3 String Reversal
//
//  Created by Pansy Ng on 10/15/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "ListNode.h"
#include <stdio.h>
class LinkedList{
public:
    ListNode* head;
    int size;
    LinkedList();
    LinkedList(LinkedList &list);
    ~LinkedList();
    
    void add(string w);
    void print();
    void reverse_print_recursion(ListNode* node);
    void reverse_print_iteration();
    void countPrint(int index);
    
};
#endif /* LinkedList_hpp */
