//
//  Rectangle.hpp
//  HW1 - Operator Overloading
//
//  Created by Pansy Ng on 10/4/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class Rectangle{
public:
    // Constructor - Destructor
    Rectangle();
    Rectangle(int len, int wid);
    ~Rectangle();
    
    //Getters for length, width, and area 
    int getLength() const;
    int getWidth() const;
    int getArea() const;
    
    //Operator Overloads
    Rectangle operator+(const Rectangle &rect) const;
    Rectangle& operator+=(const Rectangle &rect);
    Rectangle operator-(const Rectangle &rect) const;
    Rectangle& operator-=(const Rectangle &rect);
    
    bool operator==(const Rectangle &rect) const;
    bool operator!=(const Rectangle &rect) const;

private:
    int length;
    int width;
    int area;
};

#endif /* Rectangle_hpp */
