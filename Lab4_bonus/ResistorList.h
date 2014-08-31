#ifndef RESISTORLIST_H
#define	RESISTORLIST_H

#include "Resistor.h"
#include <cstring>

class ResistorList {
public:
    // constructors & de-constructor
    ResistorList();   
    ~ResistorList();
    ResistorList(const ResistorList& orig);
    
    //get & set functions
    Resistor* getHead();
    int getNumRes();

    //insert, delete, find resistors
    void insertResistor( string name_, double resistance_, int endpoints_[]);
    bool deleteResistor(string name);
    void deleteAllResistor();
    Resistor* findResistor(string name);
    
    //printing all resistor info
    void printAllResistor();
    

private:
    Resistor* head;
    int numRes; // tracking the number of resistors
};

#endif
