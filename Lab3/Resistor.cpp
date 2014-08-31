/* 
 * File:   Resistor.cpp
 * Author: kwonhong
 * 
 * Created on October 12, 2013, 11:43 AM
 */

#include "Resistor.h"
#include "Rparser.h"

// double resistance;
   // string name;
  //  int endpointNodeIDs[2];

Resistor::Resistor() {
}

Resistor:: Resistor(int rIndex_, string name_, double resistance_, int endpoints_[2]) {
    name = name_;
    resistance = resistance_;
    endpointNodeIDs[0] = endpoints_[0];
    endpointNodeIDs[1] = endpoints_[1];
    index = rIndex_;
}

Resistor::~Resistor() {
}

string Resistor::getName() const {
    return name;
}
 
double Resistor::getResistance() const {
    return resistance;
}


void Resistor::setResistance(double resistance_) {
    resistance = resistance_;
}

void Resistor::print(){
    cout << setw(20) << left <<name << setw(8) << right << resistance << " Ohms " << endpointNodeIDs[0] << " -> " << endpointNodeIDs[1] << endl; 
}

ostream& operator << (ostream& os, Resistor& res) {
//  cout << res.name << setw(20) <<res.resistance << " Ohms " << res.endpointNodeIDs[0] << " -> " << res.endpointNodeIDs[1] << endl;
}
