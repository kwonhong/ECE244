
#ifndef NODE_H
#define	NODE_H

#include <iostream>
#include "ResistorList.h"
using namespace std;

class Node {

private:
    ResistorList resistorList; 
    int nodeId, drawID;
    double voltage;
    Node* next; 
    bool isSet; // determined only by 'unsetV' and 'setV' function in Rparser class.
    
public:
    // constructors; default destructor is fine
    Node();
    Node(int nodeId, Node* next);
    
    //get & set functions
    void setVoltage(double voltage);
    int getNodeId();
    double getVoltage();
    ResistorList& getResistorList();
    
    // adding resistor in the resistorList
    bool addResistor(string name, double resistance, int endpoints[]);
    
    //printing Node Info
    void print();

    // for 'setV' and 'unsetV' function in Rparser class
    void set (double voltage_);
    void unSet ();
    
    // NodeList use most of the functions in Node class
    friend class NodeList;

};

#endif	/* NODE_H */

