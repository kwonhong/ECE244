/* 
 * File:   Node.h
 * Author: kwonhong
 *
 * Created on October 11, 2013, 4:31 PM
 */

#ifndef NODE_H
#define	NODE_H
#define MAX_RESISTORS_PER_NODE 5

#include <iostream>
using namespace std;

class Node {

private: 
    int numRes; // number of resistors currently connected
    int resIDArray[MAX_RESISTORS_PER_NODE]; // stores the index of each resistor connected
    
public:
    Node();
    ~Node();
    
    bool addResistor(int rIndex);
    void print(int nodeIndex);
    void IncreaseNumRes ();
    bool isNodeFull();
    void DeleteResistors ();

};



#endif	/* NODE_H */

