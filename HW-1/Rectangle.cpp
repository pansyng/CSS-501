//
//  Rectangle.cpp
//  HW1 - Operator Overloading
//
//  Created by Pansy Ng on 10/4/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include "Rectangle.h"

//constructor
Rectangle::Rectangle(){
    length = 0;
    width = 0;
    area = 0;
}

//constructor takes two parameters
Rectangle::Rectangle(int len, int wid){
    //length and width cannot be negative
    if(len < 0 || wid < 0){
        length = 0;
        width = 0;
        area = 0;
    }
    else{
        length = len;
        width = wid;
        area = len*wid;
    }
}

//destructor
Rectangle::~Rectangle(){
    cout << "Destructor" << endl;
}

//getter
int Rectangle::getLength() const{
    return length;
}

int Rectangle::getWidth() const{
    return width;
}

//area cannot be negative
int Rectangle::getArea() const{
    if (area < 0){
        cout << "area cannot be negative" << endl;
        return 0;
    }
    return area;
}

//arithmetic operand +
Rectangle Rectangle::operator+(const Rectangle &rect) const{
    Rectangle result = *this;
    result += rect;
    return result;
}

// compound operand +=
Rectangle& Rectangle::operator+=(const Rectangle &rect){
    area = area + rect.area;
    return *this;
}

// arithmetic operand -
Rectangle Rectangle::operator-(const Rectangle &rect) const{
    Rectangle result = *this;
    result -= rect;
    return result;
}

// compound operand -=
Rectangle& Rectangle::operator-=(const Rectangle &rect){
    area = area - rect.area;
    return *this;
}

// comparison operand ==
bool Rectangle::operator==(const Rectangle &rect) const{
    return area == rect.area;
}

//comparison operand !=
bool Rectangle::operator!=(const Rectangle &rect) const{
    return area != rect.area;
}



