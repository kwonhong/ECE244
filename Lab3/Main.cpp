/* 
 * File:   Parser.cpp
 * Author: kwonhong
 *
 * Created on September 23, 2013, 9:45 AM
 */

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Node.h"
#include "Rparser.h"
#include "Resistor.h"


int maxResistors; // to store #of maximum resistors from "maxVal" command
int maxNodeNumber; // to store #of maximum node from "maxVal" command
int resCount; // to store # of resistors inserted into the circuit
Resistor **resistorContainer ; // to store all the resistors
Node * nodeContainer; // to store all the nodes


int main() {
    cout.setf(ios::fixed);
    cout.precision(2);
    
    Rparser mRparser;
    return mRparser.parser(); // returns 0 if everything is good
}




