//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here





GroupNode* shapeNameIndex(string stringIn, GroupList* gIn);
GroupNode* groupNameIndex(string stringIn, GroupList* gIn);
void errMsg(int errNum);

int xLocation, yLocation, xSize, ySize;
int errNum = 0;
bool  reservedName;
string inputName, shapeName, groupName;

int main() {
    // Create the groups list
    gList = new GroupList();
    
    // Create the poo group and add it to the group list
    //GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]); 
    gList->insert(poolGroup);
    
    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
           
        errNum = 0;
        reservedName= false;

        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
       

        if (command == "draw") {
            cout << "drawing: " << endl;
            gList->print();
        }

        while(!lineStream.eof()) {
           
             if (command == "shape") {
                    
                    lineStream >> inputName;
                    
                    if (shapeNameIndex(inputName, gList) != NULL || groupNameIndex(inputName, gList) != NULL) {
                        if (errNum != 2) {
                            errNum = 2;
                        }
                    }

                    for (int i = 0; i <= 5; ++i) {
                    if (keyWordsList[i] == inputName) {
                            errNum = 1;
                        }
                    } 
                    
                    for (int i = 0; i <= 2; ++i) {
                        if (shapeTypesList[i] == inputName) {
                            errNum = 1;
                        }
                    } 
                    
                    errMsg(errNum);
                    if (errNum != 0) {
                        break;
                    } 
                    
                    lineStream >> shapeName;
                    lineStream >> xLocation;
                    lineStream >> yLocation;
                    lineStream >> xSize;
                    lineStream >> ySize;
                    
                    if (errNum == 0) {
                        Shape* nShape = new Shape(inputName, shapeName, xLocation, yLocation, xSize, ySize);
                        ShapeNode* nShapeNode = new ShapeNode();
                        nShapeNode->setShape(nShape);
                        gList->getHead()->getShapeList()->insert(nShapeNode);
                        cout << inputName << ": " << shapeName << " " << xLocation << " " << yLocation << " " << xSize << " " << ySize << endl;
                    }
                    break;
                }

                
                
                else if(command == "move") { 
                    
                    lineStream >> inputName;
                    lineStream >> groupName;
                    
                    if (groupNameIndex(groupName, gList) == NULL) {
                        if (errNum != 4) {
                            errNum = 4;
                        }
                    } 
                    if (shapeNameIndex(inputName, gList) == NULL) { 
                        if (errNum != 3) {
                            errNum = 3;
                        }
                    } 
                    for (int i = 0; i <= 5; ++i) {
                    if (keyWordsList[i] == inputName) {
                            errNum = 1;
                        }
                    } 
                    for (int i = 0; i <= 2; ++i) {
                        if (shapeTypesList[i] == inputName) {
                            errNum = 1;
                        }
                    } 
                    
                    errMsg(errNum); if (errNum != 0) {
                        break;
                    }

                    if (errNum == 0) {
                        GroupNode* group1 = shapeNameIndex(inputName, gList);
                        GroupNode* group2 = groupNameIndex(groupName, gList);
                        ShapeNode* shape1 = group1->getShapeList()->remove(inputName);
                        shape1->setNext(NULL);
                        group2->getShapeList()->insert(shape1);

                        cout << "moved " << inputName << " to " << groupName << endl;

                    }

                    break;

                }

                else if(command == "group") {
                    lineStream >> inputName;
                    if (shapeNameIndex(inputName, gList) != NULL || groupNameIndex(inputName, gList) != NULL) {
                        if (errNum != 2) {
                            errNum = 2;
                        }
                    }

                    for (int i = 0; i <= 5; ++i) {
                    if (keyWordsList[i] == inputName) {
                            errNum = 1;
                        }
                    } 
                    for (int i = 0; i <= 2; ++i) {
                        if (shapeTypesList[i] == inputName) {
                            errNum = 1;
                        }
                    } 
                    
                    errMsg(errNum);
                    if (errNum != 0) {
                        break;
                    } 

                    if (errNum == 0) {
                        GroupNode* nGroupNode = new GroupNode(inputName);
                        gList->insert(nGroupNode);
                        cout << inputName << ": group" << endl;
                    }
                    
                    break;
                }
                
                else if(command == "draw") {
                    cout << "drawing: " << endl;
                    gList->print();
                    break;

                }

                
                else if(command == "delete") {
                    
                    bool sflag = false;
                    bool gflag = false;
                    ShapeNode* curS;
                    GroupNode* curG;

                    lineStream >> inputName;
                    

                    if (groupNameIndex(inputName, gList) == NULL) {
                        if (errNum !=4) {
                            errNum = 4;
                        }
                    }
                    if (shapeNameIndex(inputName, gList) == NULL) {
                        if (errNum !=3) {
                            errNum = 3;
                        }
                    }
                    for (int i = 0; i <= 5; ++i) {
                    if (keyWordsList[i] == inputName) {
                            errNum = 1;
                        }
                    } 
                    for (int i = 0; i <= 2; ++i) {
                        if (shapeTypesList[i] == inputName) {
                            errNum = 1;
                        }
                    } 
                    
                    if (shapeNameIndex(inputName, gList) == NULL && groupNameIndex(inputName, gList) != NULL) {         
                        errNum = 0;
                        
                    }
                    if (groupNameIndex(inputName, gList) == NULL) {
                        
                        if (shapeNameIndex(inputName, gList) != NULL) {
                            errNum = 0;
                        }
                        if (shapeNameIndex(inputName, gList) == NULL) {
                            groupName = inputName;
                        }
                    } 
                    if (inputName == "pool") {
                        cout << "error: invalid name" << endl;
                        break;
                    }
                    errMsg(errNum); if (errNum != 0) {
                        break;
                    }
                    
                    

                    if (shapeNameIndex(inputName, gList) != NULL) {
                        curG = shapeNameIndex(inputName, gList);
                        curS = curG->getShapeList()->find(inputName);
                        curG->getShapeList()->remove(inputName);
                        delete curS;
                        cout << inputName << ": deleted" << endl;
                        
                    }
                   
                    if (groupNameIndex(inputName, gList) != NULL) {
                        curG = groupNameIndex(inputName, gList);
                        GroupNode* curG = gList->remove(inputName);
                        ShapeNode* curS = curG->getShapeList()->getHead();
                        gList->getHead()->getShapeList()->insert(curS);
                        curG->getShapeList()->setHead(NULL);
                        delete curG;
                        cout << inputName << ": deleted" << endl;
                    }
                  
                    
                    break;
                }
                    
        }
        cin.clear();

        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}



void errMsg(int errNum) {
    if (errNum == 1) {
            cout << "error: invalid name" << endl;
        
    }
    else if (errNum == 2) {
            cout << "error: name " << inputName << " exists" << endl;
         
            
    }
    else if (errNum == 3) {
            cout << "error: shape " << inputName << " not found" << endl;
       
    }
     else if (errNum == 4) {
            cout << "error: group " << groupName << " not found" << endl;
         
    }
 
}

GroupNode* shapeNameIndex(string stringIn, GroupList* gIn) {
    GroupNode* ptr = gIn->getHead();
    while (ptr != NULL) {
        if (ptr->getShapeList()->find(stringIn) != NULL) {
            return ptr;
            }
        ptr = ptr->getNext();
    }
    return ptr;
}

GroupNode* groupNameIndex(string stringIn, GroupList* gIn) {
    GroupNode* ptr = gIn->getHead();
    while (ptr != NULL) {
        if (ptr->getName() == stringIn) {
            return ptr;
            }
        ptr = ptr->getNext();
    }
    return ptr;
}

