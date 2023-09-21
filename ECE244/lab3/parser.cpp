//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
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

// This is the shape array, to be dynamically allocated
Shape **shapesArray;

// The number of shapes in the database, to be incremented
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

bool checkName(string name, bool fail_file, bool end_of_file, bool error);
bool typeValidity(string type, bool fail_file, bool end_of_file);
bool locationValidity(int location, bool fail_file, bool end_of_file);
bool checkshapeName(string name);
bool shapeName(string name);

int main()
{

    string line;
    string command;

    cout << "> ";       // Prompt for input
    getline(cin, line); // Get a line from standard input

    while (!cin.eof())
    {

        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream(line);

        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here

        if (command == "maxShapes") {
            lineStream >> max_shapes;
            if (lineStream.fail()) {
                if (!lineStream.eof()) {
                    cout << "Error: invalid argument" << endl;
                }
            }
            else {
                shapesArray = new Shape *[max_shapes];
                for (int i = 0; i < max_shapes; i++) {
                    shapesArray[i] = NULL;
                }
                cout << "New database: max shapes is " << max_shapes << endl;
            }
        }
        else if (command == "create") {

            string shapeName, shapeType;
            int x_loc, y_loc, x_size, y_size;

            if (lineStream.fail()) {
                if (!lineStream.eof()) {
                    cout << "Error: invalid argument" << endl;
                }
                else {
                    cout << "Error: too few arguments" << endl;
                }
            }
            else {

                lineStream >> shapeName;

                if (!checkName(shapeName, lineStream.fail(), lineStream.eof(), true)) {

                    lineStream >> shapeType;

                    if (!typeValidity(shapeType, lineStream.fail(), lineStream.eof())) {

                        lineStream >> x_loc;

                        if (locationValidity(x_loc, lineStream.fail(), lineStream.eof())) {

                            lineStream >> y_loc;

                            if (locationValidity(y_loc, lineStream.fail(), lineStream.eof())) {

                                lineStream >> x_size;

                                if (locationValidity(x_size, lineStream.fail(), lineStream.eof())) {

                                    lineStream >> y_size;

                                    if (locationValidity(y_size, lineStream.fail(), lineStream.eof())) {

                                        if (!lineStream.eof()) {
                                            cout << "Error: too many arguments" << endl;
                                        }
                                        
                                        else if (shapeCount >= max_shapes) {
                                            cout << "Error: shape array is full" << endl;
                                        }
                                        
                                        else if ((shapeType == "circle") && (x_size != y_size)) {
                                            cout << "Error: invalid value" << endl;
                                        }

                                        else {
                                            for (int i = 0; i < max_shapes; i++) {
                                                if (shapesArray[i] == NULL) {
                                                    shapesArray[i] = new Shape(shapeName, shapeType, x_loc, x_size, y_loc, y_size);
                                                    cout << "Created " << shapeName << ": " << shapeType << " " << x_loc << " " << y_loc << " " << x_size << " " << y_size << endl;
                                                    shapeCount++;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        else if (command == "move") {

            string shapeName;
            int x_loc, y_loc;
            bool namefound;

            if (lineStream.fail()) {
                if (!lineStream.eof()) {
                    cout << "Error: invalid argument" << endl;
                }
                else {
                    cout << "Error: too few arguments" << endl;
                }
            }
            else {

                lineStream >> shapeName;

                if (!checkName(shapeName, lineStream.fail(), lineStream.eof(), false)) {

                    lineStream >> x_loc;

                    if (locationValidity(x_loc, lineStream.fail(), lineStream.eof())) {

                        lineStream >> y_loc;

                        if (locationValidity(y_loc, lineStream.fail(), lineStream.eof())) {

                            if (!lineStream.eof()) {
                                cout << "Error: too many arguments" << endl;
                            }

                            for (int i = 0; i < shapeCount; i++) {
                                if (shapesArray[i]->getName() == shapeName) {
                                    namefound = true;
                                }
                            }

                            if (!namefound)  {
                                cout << "Error: shape " << shapeName << " not found" << endl;
                            }

                            for (int i = 0; i < shapeCount; i++)  {
                                if (shapesArray[i] != NULL) {
                                    if (shapesArray[i]->getName() == shapeName) {
                                        shapesArray[i]->setXlocation(x_loc);
                                        shapesArray[i]->setYlocation(y_loc);
                                        cout << "Moved " << shapeName << " to " << x_loc << " " << y_loc << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        else if (command == "rotate") {

            string shapeName;
            int angle;
            bool rotateCheck;

            if (lineStream.eof()) {
                cout << "Error: too few arguments" << endl;
            }

            lineStream >> shapeName;


            if (!checkName(shapeName, lineStream.fail(), lineStream.eof(), false)) {

                lineStream >> angle;

                if (lineStream.fail()) {
                    cout << "Error: invalid argument" << endl;
                }
                
                if (!lineStream.eof()) {
                        cout << "Error: too many arguments" << endl;
                    }
                if ((0 <= angle) && (angle <= 360)) {
                    
                    for (int i = 0; i < shapeCount; i++) {
                        if (shapesArray[i] != NULL) {
                            if (shapesArray[i]->getName() == shapeName) {
                                shapesArray[i]->setRotate(angle);
                                cout << "Rotated " << shapeName << " by " << angle << " degrees" << endl;
                                rotateCheck = false;
                            }
                        }
                    }
                    if (rotateCheck == true) {
                        cout << "Error: shape " << shapeName << " not found" << endl;
                    }
                    
                }
                else {
                    cout << "Error: invalid value" << endl;
                }
            }
        }

        else if (command == "draw") {

            if (lineStream.eof()) {
                cout << "Error: too few arguments" << endl;
            }
            else {

                string shapeName;
                lineStream >> shapeName;

                if (lineStream.fail()) {
                    cout << "Error: invalid argument" << endl;
                }
                else {

                    if (shapeName == "all") {

                        if (!lineStream.eof()) {
                            cout << "Error: too many arguments" << endl;
                        }
                        else {
                            cout << "Drew all shapes" << endl;
                            for (int i = 0; i < shapeCount; i++) {
                                shapesArray[i]->draw();
                            }
                        }
                    }
                    else {

                        if (!checkName(shapeName, lineStream.fail(), lineStream.eof(), false)) {
                        
                            if (lineStream.eof()) {
                                 for (int i = 0; shapeCount > i; i++) {
                                    if (shapesArray[i]->getName() == shapeName) {
                                        cout << "Drew ";
                                        shapesArray[i]->draw();
                               
                            }
                            else {
                                 cout << "Error: too many arguments" << endl;
                               
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        else if (command == "delete") {
            
            string shapeName;
            
            if (lineStream.eof()) {
                cout << "Error: too few arguments" << endl;
            }
            else {

                lineStream >> shapeName;

                if (lineStream.fail()) {
                    cout << "Error: invalid argument" << endl;
                }

                else {

                    if (shapeName == "all") {

                       
                        if (!lineStream.eof()) {
                            cout << "Error: too many arguments" << endl;
                        }
                        else {
                            for (int i = 0; i < max_shapes; i++) {
                                if (shapesArray[i] != NULL) {
                                    delete shapesArray[i];
                                    shapesArray[i] = NULL;
                                }
                            }

                            cout << "Deleted: all shapes" << endl;
                            shapeCount = 0;
                        }
                    }
                    else {
                        bool deleted;
                        for (int i = 0; i < max_shapes; i++) {
                            if (shapesArray[i] != NULL) {
                                if (shapeName == shapesArray[i]->getName()) {
                                    delete shapesArray[i];
                                    shapesArray[i] = NULL;
                                    cout << "Deleted shape " << shapeName << endl;
                                    shapeCount--;
                                    deleted = false;
                                }
                            }
                        }

                        if (!deleted) {
                                    cout << "Error: shape " << shapeName << " not found" << endl;
                        }
                        if (!lineStream.eof()) {
                                    cout << "Error: too many arguments" << endl;
                        }
                            
                        }
                    }
                }
            
        }
        
        else {
            cout << "Error: invalid command" << endl;
        }
    
        // Once the command has been processed, prompt for the
        // next command
        cout << "> "; // Prompt for input
        getline(cin, line);

    } // End input loop until EOF.

    return 0;
}


bool checkName(string name, bool fail_file, bool end_of_file, bool error) {

    if (fail_file) {
        if (end_of_file) {
            cout << "Error: too few arguments" << endl;
            return true;
        }
        else {
            cout << "Error: invalid argument" << endl;
            return true;
        }
    }
    else if (shapeName(name)) {
        cout << "Error: invalid shape name" << endl;
        return true;
    }
   

    if (!error) {
        cout << "Error: shape " << name << " not found" << endl;
        return true;
    }

    return false;
}

bool typeValidity(string type, bool fail_file, bool end_of_file) {

    if (fail_file) {
        if (end_of_file) {
            cout << "Error: too few arguments" << endl;
            return true;
        }
        else {
            cout << "Error: invalid argument" << endl;
            return true;
        }
    }

    else if (!shapeName(type)) {
        cout << "Error: invalid shape type" << endl;
        return true;
    }
    return false;
}

bool locationValidity(int location, bool fail_file, bool end_of_file) {
    
    if (location < 0) {
        cout << "Error: invalid value" << endl;
        return false;
    }
    if (fail_file) {
        if (!end_of_file) {
            cout << "Error: invalid argument" << endl;
            return false;
        }
        else {
            cout << "Error: too few arguments" << endl;
            return false; 
        }
    }
    return true;
}



bool shapeName(string name) {
    for (int i = 0; i < 7; i++) {
        if (name == keyWordsList[i]) {
            return true;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (name == shapeTypesList[i]) {
            return true;
        }
    }
    
    return false;
}

