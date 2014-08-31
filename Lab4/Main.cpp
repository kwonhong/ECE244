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
using namespace std;

int main() {
    
    cout.setf(ios::fixed);
    cout.precision(2);
    
    Rparser mRparser;
    return mRparser.parser(); // returns 0 if everything is good

  
}
