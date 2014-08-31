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
using namespace std;

class Resistor {
    
private:
    double resistance;
    string name;
    int endpointNodeIDs[2];
    int index;
 
public:
    // rIdex_ is the index of this resistor in the resistor array
    // endpoints_ is the index of this resistor in the resistor array
    Resistor(int rIndex_, string name_, double resistance_, int ednpoints_[2]);
    Resistor();
    //destructor
    ~Resistor();
    
    // returns the name
    // do not change any member variable of the function
    string getName() const; 
    
    // returns the resistance
    double getResistance() const;
    
    // set the value of resistance
    void setResistance(double resistance_);
    void print();
    friend ostream& operator << (ostream&, const Resistor&);
};

ostream& operator << (ostream&, const Resistor&);


#endif	/* RESISTOR_H */

