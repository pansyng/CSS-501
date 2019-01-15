//
//  main.cpp
//  HW 5 Set Data Structure
//
//  Created by Pansy Ng on 11/3/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include <iostream>
#include "Set.h"
#include "Animal.h"

/*instruction: This program requires the Set header file, and Animal header file.
 */
using namespace std;
int main() {
    Set<Animals<int>> set;

    //Creation of valid example object
    Animals<int> tiger = Animals<int>("tiger", 5);
    Animals<int> cat = Animals<int>("cat  ", 3);
    Animals<int> dog = Animals<int>("dog  ", 7);
    Animals<int> lion = Animals<int>("lion", 5);
    Animals<int> hippo = Animals<int>("hippo", 6);
    Animals<int> fish = Animals<int>("fish", 7);
    //Demonstration of use of Set: insert(obj), print(), top3counters()
    set.insert(tiger);
    //Adding an item that already exists in the set
    set.insert(tiger);
    set.insert(fish);
    set.insert(fish);
    set.insert(fish);
    set.insert(dog);
    set.insert(cat);
    set.insert(tiger);
    set.insert(cat);
    set.insert(tiger);
    set.insert(hippo);
    set.insert(lion);
    //Print out everything that is in the set
    set.print();
    //Obtain counters
    cout << "Number of attempts for Cat: " << set.getCounter(cat) << endl;
    //Demonstration of "top 3 in Set"
    cout << "Top 3 keys: " << endl;
    set.top3counters();
}
