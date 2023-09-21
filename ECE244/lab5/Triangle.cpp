//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Shape.h"
#include "Triangle.h"

// Build a Rectangle object
Triangle::Triangle(string n, float xcent, float ycent, float x_1, float y_1, float x_2, float y_2, float x_3, float y_3):Shape(n, xcent, ycent) {
    x1 = x_1;
    y1 = y_1;
    x2 = x_2;
    y2 = y_2;
    x3 = x_3;
    y3 = y_3;
}

Triangle::~Triangle() {
    // Nothing to do
}

// Accessor
float Triangle::getx1() const {
    return x1;
}     

float Triangle::gety1() const {
    return y1;
} 

float Triangle::getx2() const {
    return x2;
}    

float Triangle::gety2() const {
    return y2;
}

float Triangle::getx3() const {
    return x3;
}    

float Triangle::gety3() const {
    return y3;
}


// Mutator
    void setx1(float x_1);   

    void sety1(float y_1); 
    
    void setx2(float x_2);   

    void sety2(float y_2);

    void setx3(float x_3);   

    void sety3(float y_3); 


void Triangle::draw() const {
    // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "triangle: " << name << " "
         << x_centre << " " << y_centre
         << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << computeArea() 
         << endl;
}

float Triangle::computeArea() const {
    return ((abs((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))))/2);
}

Shape* Triangle::clone() const {
    return (new Triangle(*this));
}