/* 
 * File:   NodeList.h
 * Author: kwonhong
 *
 * Created on November 2, 2013, 8:38 AM
 */

#ifndef NODELIST_H
#define	NODELIST_H

#include "Node.h"
#include "Resistor.h"
#include <cmath>
#define MIN_ITERATION_CHANGE 0.0001

class NodeList {
    
private:
    Node * head;
    double solveHelper(Node * temp); // helper function for solve command  

public:
    // constructors; default destructor is fine
    NodeList();
    
    //finding, printing, deleting Nodes
    Node* findOrInsert(int nodeId);
    void printAllNode();
    void deleteAllNodes(); 
    
    //find, modify, and delete resistor 
    bool modifyResistor(string name, double &oldres_, double newRes);
    Resistor* findResistor(string name);
    void deleteAllResistor();
    bool deleteResistor(string name);
    
    //checking if any Nodes are set by 'setV' command in 'Rparser' class 
    bool isOneSetV();
    
    // solve command in 'Rparser' class
    void solve();
    
    //draw helper functions
    void draw ();
    int getHeight();
    void set_draw_coords(float& xleft, float& ybottom, float& ytop, float& xright);
    

};

#endif	/* NODELIST_H */

