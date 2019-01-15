//
//  CompressedString.cpp
//  HW 4 String Compression
//
//  Created by Pansy Ng on 10/24/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include "CompressedString.h"
#include <iostream>
#include <vector>
#include <string>
#include <locale>


using namespace std;

//Big O analysis: O(n) since only one for loop in the compress method
//Constructor
CompressedString::CompressedString(string s){
    //vector
    vector<char>data(s.begin(), s.end());
    word = compress(data);
    //print to console
    cout << "String after compression: " << word << endl;
}

//Compression method
string CompressedString:: compress(vector<char> &str2){
    int count = 0;
    int cur = 0;
    char temp = str2[0];
    for(int i = 0; i <= str2.size(); i++){
        if(str2[i] == temp){
            count++;
        }
        else{
            if(count > 1){
                str2[cur] = '0' + count;
                str2[++cur] = temp;
            }
            else if(count == 1){
                str2[cur] = temp;
            }
            cur++;
            temp = str2[i];
            count = 1;
        }
    }
    str2.erase(str2.begin()+cur, str2.end());
    string newStr(str2.begin(), str2.end());
    return newStr;
}

//Big O Analysis: O(n) since using one for loop
//overload <<
ostream& operator<<(ostream &outStream, const CompressedString &cs){
    outStream << "de-compressed string: ";
    int count = 1;
    for(int i = 0; i < cs.word.length(); i++){
        if(isdigit(cs.word.at(i))){
            count = cs.word.at(i) - '0';
        }
        else{
            if(count == 1)
                outStream << cs.word.at(i);
            else{
                outStream << string(count, cs.word.at(i));
                count = 1;
            }
        }
    }
    return outStream;
}
