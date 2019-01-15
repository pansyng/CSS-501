//
//  ListNode.hpp
//  HW3 String Reversal
//
//  Created by Pansy Ng on 10/15/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class ListNode{
public:
    string word;
    ListNode* next;
    ListNode();
    ListNode(string word);
    
};
#endif /* ListNode_hpp */
