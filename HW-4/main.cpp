//
//  main.cpp
//  HW 4 String Compression
//
//  Created by Pansy Ng on 10/24/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include <iostream>
#include "CompressedString.h"
using namespace std;

int main(int argc, const char * argv[]) {
    //Compression of a short string
    cout << CompressedString("abc")<< endl;
    //Compression of a long string 
    cout << CompressedString("aaaaadddddeeeeffwwwwazwww")<< endl;
    
}
