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
#include <sstream>
#define MIN_ITERATION_CHANGE 0.0001

class NodeList {
    
private:
    Node * head;
    double solveHelper(Node * temp); // helper function for solve command  

public:
    // constructors & de-constructor
    NodeList();
    ~NodeList();
    
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
    
    //draw helper function
    void draw ();
    int getHeight();
    void set_draw_coords(float& xleft, float& ybottom, float& ytop, float& xright);

};

string MergeString_String(string str2, string str1);
string MergeString_Number(double num, string str1);
string MergeString_Number(string str1, double num);
#endif	/* NODELIST_H */

