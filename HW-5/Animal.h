//
//  Animal.hpp
//  HW 5 Set Data Structure
//
//  Created by Pansy Ng on 11/3/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
//header file of one example object with templated data
template <class T>
class Animals{
    friend ostream& operator<<(ostream &output, const Animals &a){
        output << a.name;
        return output;
    }
public:
    T thing;
    string name;
    Animals();
    //Constructor that takes in data for the object
    Animals(string str, T t);
    // == overload for the object 
    bool operator ==(const Animals &a)const;
};

template<class T>
Animals<T>::Animals(){
    name = "unknown";
    thing = NULL;
}

// Constructor that takes in data for the object (enforce invariants)
template<class T>
Animals<T>::Animals(string str, T t){
    //enforce invariants
    if(str != ""){
        name = str;
        thing = t;
    }
    else{
        name = "unknown";
        thing = NULL;
    }
}

// == overload for the object
template<class T>
bool Animals<T>::operator ==(const Animals &a)const{
    return name == a.name;
}
#endif /* Animal_hpp */
