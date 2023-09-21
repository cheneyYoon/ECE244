//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below

#include "GroupList.h"

using namespace std;

GroupList::GroupList() {
    head = NULL;
}

GroupList::~GroupList() {
    GroupNode* tHead = head;
	GroupNode* temp = NULL;
	
    while (tHead != NULL) {
		temp = tHead->getNext();
		tHead = temp;
        delete tHead;
	}    
}

GroupNode* GroupList::getHead() const {
    return head;
} 

void GroupList::setHead(GroupNode* ptr) {
    head = ptr;
}    

void GroupList::insert(GroupNode* s) {
    GroupNode* tHead = head;
	s->setNext(NULL);
	
    if (head == NULL) {
		head = s;
		return;
	}
	
    while (tHead->getNext() != NULL) {
        tHead = tHead->getNext();
    }
	
    tHead->setNext(s);

}      

GroupNode* GroupList::remove(string name) {
    GroupNode* tempptr = head;
	GroupNode* prior = NULL;

	if (tempptr->getName() == name && tempptr != NULL) {
		head = tempptr->getNext();
		return tempptr;
	}
    while ( tempptr->getName() != name && tempptr != NULL) {
        prior = tempptr;
        tempptr = tempptr->getNext();
    }
    if (tempptr == NULL) {
        return NULL;
    }
    prior->setNext(tempptr->getNext());

	return tempptr;
}   

void GroupList::print() const {
    GroupNode* ptr = head;
    while (ptr != NULL) {
        ptr->print();
        ptr = ptr->getNext();
    }
}               

