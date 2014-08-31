#include "Node.h"

// constructors
Node:: Node(){
    isSet = false;
    voltage = 0;
} 

Node:: Node(int nodeId_, Node* next_) {
    nodeId = nodeId_;
    next = next_;
}

Node::~Node() {
}







//get & set functions
void Node:: setVoltage(double voltage_) {
    voltage = voltage_;
}

int Node:: getNodeId() {
    return nodeId;
}

double Node:: getVoltage() {
    return voltage;
}

ResistorList& Node:: getResistorList() {
    return resistorList;
}







// adding resistor in the resistorList
bool Node:: addResistor(string name, double resistance, int endpoints[]) {
        resistorList.insertResistor(name, resistance, endpoints);
}







//printing Node Info
void Node:: print() {
    int numRes = resistorList.getNumRes(); // getting the #of resistors in the list
    
    if (numRes != 0)  {// if the resistor list is empty, don't print
        cout << "Connections at node " << nodeId << ": " << numRes << " resistor(s)" << endl;
        resistorList.printAllResistor();
    }
}








// for 'setV' and 'unsetV' function in Rparser class
void Node:: set(double voltage_) {
    voltage = voltage_;
    isSet = true;
}

void Node:: unSet() {
    isSet = false;
    voltage = 0; // optional - no need to set the voltage back to 0
}



