//
//  CompressedString.hpp
//  HW 4 String Compression
//
//  Created by Pansy Ng on 10/24/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#ifndef CompressedString_h
#define CompressedString_h


#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class CompressedString{
    friend ostream& operator<<(ostream &outStream, const CompressedString &cs);
public:
    string word;
    CompressedString(string s);
    string compress(vector<char> &str2);
    
};

#endif /* CompressedString_h */
