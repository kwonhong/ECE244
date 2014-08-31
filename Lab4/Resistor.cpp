#include "Resistor.h"

// constructors
Resistor::Resistor() {
}

Resistor:: Resistor( string name_, double resistance_, Resistor* next_, int endpoints_[]) {
    name = name_;
    resistance = resistance_;
    next = next_;
    endpoints[0] = endpoints_[0];
    endpoints[1] = endpoints_[1];
}

//get & set functions
string Resistor::getName() const {
    return name;
}
 
double Resistor::getResistance() const {
    return resistance;
}

int Resistor:: getEndpoints(int arg) {
    //returning the first endpoint
    if (arg == 0) 
        return endpoints[0];
    
    //returning the second endpoint
    else if (arg == 1)
        return endpoints[1];
}

Resistor* Resistor:: getNext() {
    return next;
}

void Resistor::setResistance(double resistance_) {
    resistance = resistance_;
}

//printing 
void Resistor::print(){
    cout << setw(20) << left <<name << setw(8) << right << resistance << " Ohms " << endpoints[0] << " -> " << endpoints[1] << endl; 
}


ostream& operator<< (ostream& os, const Resistor& res) {
  os << res.name << setw(20) <<res.resistance << " Ohms " << res.endpoints[0] << " -> " << res.endpoints[1] << endl;
}

