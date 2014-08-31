#include "Node.h"
#include "Rparser.h"

Node:: Node(){
    numRes = 0;
} 

Node::~Node(){
}
    
bool Node:: addResistor(int rIndex) {
  
    if (numRes >= 5 ) {
        return false;
    }
    
    else {
        resIDArray[numRes] = rIndex;
        numRes++; // increase the number of res in the nodes
        return true; 
    }
}

void Node:: print(int nodeIndex) {
    cout << "Connections at node " << nodeIndex << ": " << numRes << " resistor(s)" << endl;
    for (int i=0; i<numRes; i++) { // going through all the resistor connected to the node
        cout << "  ";
        int r_index = resIDArray[i]; // getting the index of the resistor in the resistorcontainer array
        (*resistorContainer[r_index]).print(); // printing out the resistor info
    }
}

bool Node:: isNodeFull() {
    if (numRes == 5) {
        return true;
    }
    return false;
}

void Node:: DeleteResistors () {
    for (int i=0; i<numRes; i++)
        resIDArray[i] = 0;
    numRes = 0;
}