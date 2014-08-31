/* 
 * File:   Rparser.h
 * Author: kwonhong
 *
 * Created on October 11, 2013, 4:38 PM
 */

#ifndef RPARSER_H
#define	RPARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "Node.h"
#include "Resistor.h"
#include "NodeList.h"
#include "ResistorList.h"
#include "NodeList.h"


#define MIN_NODE_NUMBER 0
using namespace std;

class Rparser {
public:
    // constructors; default destructor is fine
    Rparser(); // Constructor 
    int parser(); // function that checks all the command line

private:
    NodeList nodeList;
    // User commands
    void maxVal (stringstream &linestream); // maxVal command
    void insertR (stringstream &linestream); // insertR command
    void modifyR(stringstream &linestream); // modifyR command
    void printR(stringstream &linestream); // printR command
    void printNode(stringstream &linestream); // printNode command
    void deleteR (stringstream &linestream); // deleteR command
    void setV(stringstream &linestream); // setV command
    void unsetV(stringstream &linestream);// unsetV command
    void solve(stringstream & linestream);// solve command
    void draw ();
    
    // Checking the validity of the arguments
    bool isInvalidArg(stringstream &linestream); // Check for invalid argument
    bool isNegativeRes(double resistance); // Check for negative resistance
    bool isRes_all (string resistor); // Check if the name of resistance is 'all'
    bool isSameNodeConnect (int node1, int node2); // check if the nodes are the same
    bool isManyArg(stringstream &linestream); // check for too many arguments
    bool isFewArg (stringstream &linestream); // check for too few arguments
    
    // Clearing any whitespace, tabs, newlines before the next command
    void clearout(stringstream &linestream);   \
};



#endif	/* RPARSER_H */

