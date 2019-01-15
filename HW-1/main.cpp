//
//  main.cpp
//  HW1 - Operator Overloading
//
//  Created by Pansy Ng on 10/1/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

/* This program will take Rectangle.cpp and Rectangle.h to create an object Rectangle. This object
 will take two integer parameters as length and width to calculate the area. After that, we can adding
 and substracting(operator overloading) between Rectangle objects.
 */
#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
    // Object creation
    Rectangle rect1(3, 7), rect2(5, 10), rect7(2, 25);
    Rectangle rect3, rect4, rect5, rect6;
    
    cout << "Welcome to out rectangle area calculator" << endl;
    cout << "rect1: " << rect1.getArea() << endl;
    cout << "rect2: " << rect2.getArea() << endl;
    cout << "rect3: " << rect3.getArea() << endl;
    cout << "rect7: " << rect7.getArea() << endl;
    
    // arithmetic operand +
    rect4 = rect1 + rect2;
    cout << "rect4:" << rect4.getArea() << endl;
    // arithmetic operand - and testing when area become negative
    rect5 = rect1 - rect2;
    cout << "rect5:" << rect5.getArea() << endl;
    // arithmetic operand -
    rect6 = rect2 - rect1;
    cout << "rect6:" << rect6.getArea() << endl;
    
    // compound operand +=
    rect1 += rect2;
    cout << "rect1 += rect2; rect1: " << rect1.getArea() << endl;
    // compound operand -=
    rect1 -= rect2;
    cout << "rect1 -= rect2; rect1: " << rect1.getArea() << endl;
    
    // comparison operand ==
    if(rect7 == rect2){
        cout << "they are the same" << endl;
    }
    else{
        cout << "they are not the same" << endl;
    }
    
    // comparison operand !=
    if(rect1 != rect2){
        cout << "they are not the same" << endl;
    }
    else{
        cout << "they are the same" << endl;
    }
    
}
