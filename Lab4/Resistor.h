/* 
 * File:   Resistor.h
 * Author: kwonhong
 *
 * Created on October 11, 2013, 4:19 PM
 */

#ifndef RESISTOR_H
#define	RESISTOR_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Resistor {
    
private:
    double resistance;
    string name;
    int endpoints[2];
    Resistor* next;
 
public:
    // constructors; default destructor is fine
    Resistor();
    Resistor( string name_, double resistance_, Resistor* next_, int endpoints[]);
    
    //get & set functions
    string getName() const; 
    double getResistance() const;
    void setResistance(double resistance_);
    Resistor * getNext();
    int getEndpoints(int arg);
    
    //printing 
    void print();
    friend ostream& operator<< (ostream& os, const Resistor& res);
 
    // ResistorList use most of the functions in Resistor class
    friend class ResistorList;
};

ostream& operator<< (ostream& os, const Resistor& res);

#endif	/* RESISTOR_H */

