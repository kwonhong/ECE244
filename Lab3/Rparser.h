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
//#include "ResistorList.h"
//#include "NodeList.h"

#define MIN_NODE_NUMBER 0
using namespace std;

extern Resistor **resistorContainer ;
extern Node * nodeContainer;
extern int maxResistors;
extern int maxNodeNumber;
extern int resCount;

class Rparser {
public:
    Rparser(); // Constructor 
    ~Rparser();// De-constructor
    int parser(); // function that checks all the command line

private:
    void maxVal (stringstream &linestream); // maxVal command
    void insertR (stringstream &linestream); // insertR command
    void modifyR(stringstream &linestream); // modifyR command
    void printR(stringstream &linestream); // printR command
    void printNode(stringstream &linestream); // printNode command
    void deleteR (stringstream &linestream); // deleteR command
    bool isInvalidArg(stringstream &linestream); // Check for invalid argument
    bool isNegativeRes(double resistance); // Check for negative resistance
    bool isBoundError (int node);  // Check for node boundaries
    bool isRes_all (string resistor); // Check if the name of resistance is 'all'
    bool isSameNodeConnect (int node1, int node2); // check if the nodes are the same
    bool isManyArg(stringstream &linestream); // check for too many arguments
    bool isFewArg (stringstream &linestream); // check for too few arguments
    bool isMaxValueValid (int arg1); // check if the argument for maxVal is 0
    bool isResistorArrayFull (); // check if the resistorArray is full
    bool isNodeFull (int arg1); // check if the node is full
    int  getResistorIndex (string name);// getting the index of the resistor
    void clearout(stringstream &linestream);

};



#endif	/* RPARSER_H */

