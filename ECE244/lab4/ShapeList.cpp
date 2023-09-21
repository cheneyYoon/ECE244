//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below

#include "ShapeList.h"

ShapeList::ShapeList() {
    head = NULL;
}

ShapeList::~ShapeList() {
    ShapeNode* ptr;
    ShapeNode* temp;
    
    ptr = head;
    temp = NULL;
    
    while(ptr != NULL) {
        temp = ptr->getNext();
        ptr = temp;
        delete ptr;
    }
}

ShapeNode* ShapeList::getHead() const {
    return (head);
}        

void ShapeList::setHead(ShapeNode* ptr) {
    head = ptr;
}    
    
ShapeNode* ShapeList::find(string name) const {
    ShapeNode* temp = head;
    if (head == NULL) {
        return NULL;
    }
    
    while (temp != NULL) {
        if(temp->getShape()->getName() == name) {
            return temp;
        }
        temp = temp->getNext();
        
    }
    return NULL;
} 

void ShapeList::insert(ShapeNode* s) {
    ShapeNode* temp = head;
    if (head == NULL) {
        head = s;
        return;
    } 
    
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
    }
    temp->setNext(s);
}       

ShapeNode* ShapeList::remove(string name) {
    ShapeNode* temp = head;
    ShapeNode* ptr = NULL;
    
        if (head == NULL) {
            return NULL;
    }
    
        while (temp != NULL) {
            if (temp->getShape()->getName() == name){
                break;
            }
            ptr = temp;
            temp= temp->getNext();
    }
    
        if (temp == head) {
            head = head->getNext();
            return temp; 
    }
        if (temp == NULL){
        return temp; 
    }
    ptr->setNext(temp->getNext());
    
    return temp; 
}

void ShapeList::print() const {
    ShapeNode* temp = head;
    
    while (temp != NULL) {
        temp->print();
        temp = temp->getNext();
    }
}              