//
//  Set.hpp
//  HW 5 Set Data Structure
//
//  Created by Pansy Ng on 11/3/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#ifndef Set_h
#define Set_h

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
//Set class
template <class T>
class Set{
    
public:
    vector<T> list;
    vector<int> counterList;
    int size;
    int currentPosition;
    Set();
    Set(T item);
    void insert(T item);
    void print();
    int getCounter(T item);
    void top3counters();
};


template<class T>
Set<T>::Set(){
    size = 0;
}

//insert keeps track of only unique values
//insert also keep track of how many times a user has attempted to add a "key" to the structure
//Big-O analysis: O(n^2) since the complexity of vector find method is O(n) and in the else method I also have another for loop. So, combine altogether I assume is O(n^2).
template<class T>
void Set<T>::insert(T item){
    int n = find(list.begin(), list.end(), item) == list.end();
    if(n == 1){
        list.push_back(item);
        counterList.push_back(1);
        size++;
    }
    else{
        for(int i = 0; i < size; i++){
            if(list[i] == item){
                counterList[i]++;
            }
        }
    }
}

template<class T>
void Set<T>::print(){
    cout << "KEY\tCOUNTER"<< endl;
    for(int i = 0; i < list.size(); i++){
        cout << list[i] <<"\t" << counterList[i]<<endl;
    }
    
}

// A way to obtain the "counter" for a given key
template <class T>
int Set<T> :: getCounter(T item){
    int counter = 0;
    int n = find(list.begin(), list.end(), item) == list.end();
    if(n == 1){
        counter = -1;
    }
    else{
        for(int i = 0; i < size; i++){
            if(list[i] == item){
                counter = counterList[i];
            }
        }
    }
    return counter;
}

//A way to display the "top 3" kwys in the structure (With the top 3 highest counters)
//Big-O analysis: O(n^2) since two for loop.
template <class T>
void Set<T>:: top3counters(){
    vector<int> vect2;
    for(int i = 0; i < size; i++){
        vect2.push_back(counterList[i]);
    }
    sort(vect2.begin(), vect2.end());
    T top1, top2, top3;
    for(int i = 0; i < size; i++){
        if(counterList[i] == vect2[size-1]){
            top1 = list[i];
           // cout << "Top1: " << list[i] << endl;
        }
        else if(counterList[i] == vect2[size-2]){
            top2 = list[i];
            //cout << "Top2: " << list[i] << endl;
        }
        else if(counterList[i] == vect2[size-3]){
            top3 = list[i];
            //cout << "Top3: " << list[i] << endl;
        }
    }
    cout << top1 << ", " << top2 << ", " << top3 << endl;
}
#endif /* Set_hpp */
