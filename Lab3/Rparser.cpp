/* 
 * File:   Rparser.cpp
 * Author: kwonhong
 * 
 * Created on October 11, 2013, 4:38 PM
 */

#include "Rparser.h"


Rparser::Rparser() {
    resistorContainer = NULL ;
    nodeContainer = NULL;
    resCount = 0;
  //  NodeList nodeList;
  //  ResistorList resistorList;
}

Rparser::~Rparser() {
}

// return 0 if the parser function works perfectly
int Rparser:: parser() {
    
    string line, command;
    
    cout << ">";
    getline(cin, line); // Get a line from standard input.
    
    while (!cin.eof()) {
    stringstream lineStream(line);
    if ( line != "") {   
            lineStream >> command;
            
            if (command == "maxVal") {
               maxVal(lineStream);
            }
            
            else if (command == "insertR") {
                insertR(lineStream);
            }

            else if (command =="modifyR") {
                modifyR(lineStream);

            }
            
            else if (command== "printR" ) {
                printR(lineStream);

            }
            
            else if (command=="printNode" ) {
                printNode(lineStream);
            }
            
            else if (command=="deleteR") {
                deleteR(lineStream);
            }
            
            else {
                cout << "Error: invalid command" << endl;
            }
            
        }
        clearout(lineStream);
        cout << ">";   
        getline (cin, line);   
    } // End input loop until EOF
    
    if (nodeContainer != 0 || resistorContainer != 0) {
    for (int i = 0 ; i< maxResistors; i++) {
            delete resistorContainer[i];
        }
        delete[] nodeContainer;
        delete[] resistorContainer;
        resCount = 0;
    }

    return 0;
}
void Rparser:: clearout (stringstream & linestream) {
    while (linestream.peek() == '\n' || linestream.peek() == '\t' || linestream.peek() == ' ') {
        linestream.get();
    }
}
// Testing if the inputs are valid
bool Rparser:: isInvalidArg(stringstream &linestream ) {
    
    
    // Testing if the input type is wrong
    if (linestream.fail()  ) {
        
        linestream.clear();
        linestream.ignore(190000000, '\n');
        cout << "Error: invalid argument"<< endl;
    
        return true;
    }
    // Testing if there is any invalid input right next to the correct input
    else if (linestream.peek() != ' ' && linestream.peek() != '\n' && linestream.peek() != '\t' && linestream.peek() != -1) {
        
        linestream.clear();
        linestream.ignore(190000000, '\n');
        cout << "Error: invalid argument"<< endl;
    
        return true;
    
    
    }
    return false;
}

//Testing whether the resistance value is negative or not
bool Rparser:: isNegativeRes (double resistance) {
    if (resistance < 0) {
        cout << "Error: negative resistance" << endl;
        return true;
    }
    return false;
    
}


// Testing whether the node value is between 0-5000
bool Rparser:: isBoundError (int node1) {
  
    if ( (node1 > maxNodeNumber || node1 < MIN_NODE_NUMBER)) {
        
        cout << "Error: node "<< node1 << " is out of permitted range " << MIN_NODE_NUMBER << "-" << maxNodeNumber<< endl;     
        return true;
        
    }
    return false;
}

//Testing whether the user input the name of resistance as "all"
bool Rparser:: isRes_all (string resistor) {
    if (resistor == "all") {
        cout << "Error: resistor name cannot be the keyword \"all\""<< endl;
        return true;
    }
    return false;
}

// Testing if the two nodes have the same value
bool Rparser:: isSameNodeConnect (int node1, int node2) {
    if (node1 == node2) {
       cout<< "Error: both terminals of resistor connect to node "<< node1 << endl;
       return true;
    }
    
    return false;
}

//Testing for too many arguments
bool Rparser:: isManyArg(stringstream & linestream) {
    char c = linestream.get();
    
    // linestream.peek gives a value '-1' if no character is read.
    if (linestream.peek() != -1 && linestream.peek() != '\n' && linestream.peek() != '\t' && linestream.peek() != ' ') {
        cout << "Error: too many arguments" << endl;
        return true;
    }
    return false;
}

//Testing for too many arguments
bool Rparser:: isFewArg (stringstream & linestream) {
    char c = linestream.get();
    
     // linestream.peek gives a value '-1' if no character is read.
    if (linestream.peek() == -1){
        linestream.clear(); // getting "-1" from "peek()" method might turn 'linestream' into 'fail' mode
        cout << "Error: too few arguments" << endl;
        return true;
    }
    return false;
}

// checking if the argument for MaxVal function is 0
bool Rparser:: isMaxValueValid (int arg1) {
    if (arg1 <= 0 ) {
        cout << "Error: maxVal arguments must be greater than 0" << endl;
        return false;
    }
    
    return true;
}

// checking if the #of resistors = #of maximum resistors
bool Rparser:: isResistorArrayFull() {
    if (maxResistors == resCount) {
       cout << "Error: resistor array is full" << endl; 
       return true;
    }
    return false;
}

// checking if the node is full of resistors
bool Rparser:: isNodeFull(int arg1) {
    bool mIsNodeFull = nodeContainer[arg1].isNodeFull();
    if (mIsNodeFull) {
        cout << "Error: node is full" << endl;
        return true;
    } 
    return false;
       
}

//checking if the resistor(name) exists in the resistorContainer array
int Rparser:: getResistorIndex(string name) {
    for (int i=0; i< resCount; i++) {
        //comparing the name within the resistorContainer array
        string tempName = (*(resistorContainer[i])).getName();
        if (tempName == name)
            return i; 
        
    }
    cout << "Error: resistor " << name << " not found" << endl;
    return -1; // if the resistor doesn't exist
    
}

//maxVal command
void Rparser:: maxVal (stringstream & linestream) {
    int mResistor; // temporarily storing maxResistor Value
    int mNodeNumber;// temporarily storing maxNode Value

    if (isFewArg (linestream)) 
        return;
    
    linestream >> mNodeNumber;
        
    if (isInvalidArg(linestream)) 
        return;
    
    if (!isMaxValueValid (mNodeNumber) )
        return;
        
    if (isFewArg (linestream)) 
        return;
    
    linestream >> mResistor;
            
    if (isInvalidArg (linestream))
        return;
            
    if (!isMaxValueValid (mResistor)) 
        return;                                          
    
    if ( isManyArg(linestream) ) 
        return;
    
    
    // deleting all the nodes and resistors array whenever the maxVal is called
    // not the first time since both arrays are empty
    if (nodeContainer != 0 || resistorContainer != 0) {
        for (int i = 0 ; i< maxResistors; i++) {
            delete resistorContainer[i];
        }
        delete[] nodeContainer;
        delete[] resistorContainer;
        resCount = 0;
    }
    
    // after checking if the command line is valid, set maxResistors & maxNode
    maxResistors = mResistor;
    maxNodeNumber = mNodeNumber;
    cout << "New network: max node number is " << maxNodeNumber << "; max resistors is " << maxResistors << endl; 
    
    // making required # of resistor and node array
    nodeContainer = new Node[maxNodeNumber+1];
    // need Resistor pointer array since all the resistors information are not given at this point 
    resistorContainer = new Resistor* [maxResistors];
}
    


void Rparser:: insertR (stringstream &linestream) 
{
    string name;
    double resistance;
    int nodeid1, nodeid2;

    if (isFewArg (linestream)) 
        return;
    
    linestream >> name;
        
    if (isRes_all(name)) 
        return;
   
    if (isFewArg (linestream)) 
        return;
    
    linestream >> resistance;
    
    if (isInvalidArg(linestream))
        return;
    
    if (isNegativeRes (resistance))
        return;
    
    if (isFewArg (linestream)) 
        return;
               
    linestream >> nodeid1;
    
    if (isInvalidArg(linestream))
        return;
    
  /*  if (isBoundError (nodeid1))
        return; */
    
    if (isFewArg (linestream)) 
        return;
    
    linestream >> nodeid2;
    
    if (isInvalidArg(linestream))
        return;
                   
  /*  if (isBoundError (nodeid2))
        return; */
                    
    if (isSameNodeConnect (nodeid1, nodeid2))
        return;
    
    if (isManyArg (linestream))
        return;
    
    if (isResistorArrayFull()) 
        return;
    
    if (isNodeFull (nodeid1))
        return; // need to modify
    
    if (isNodeFull (nodeid2))
        return; // need to modify
    
    //after checking if the command line is valid, print
    cout << "Inserted: resistor " << name << " " << resistance << " Ohms "<< nodeid1 << " -> " << nodeid2 <<endl;
   
    // insert the resistor into the ResistorContainer array
    // insert the resistor into the connected Node
    int Nodes[] = {nodeid1, nodeid2};
    resistorContainer[resCount] = new Resistor(resCount, name, resistance, Nodes);
    nodeContainer[nodeid1].addResistor(resCount);
    nodeContainer[nodeid2].addResistor(resCount);
    resCount ++; // increase the #of resistors in the circuit
    
    
}

//modifyR command
void Rparser:: modifyR(stringstream &linestream) 
{
    string name;
    double resistance;
    int res_index;

    if (isFewArg (linestream)) 
        return;
    
    linestream >> name;
        
    if (isRes_all(name)) 
        return;
    
    if (isFewArg (linestream)) 
        return;
    
    linestream >> resistance;
               
    if (isInvalidArg(linestream))
        return;

    if (isNegativeRes (resistance))
        return;
                    
    if (isManyArg (linestream))
        return;
    
    res_index = getResistorIndex(name);
    if (res_index == -1) 
        return;
    
    double old_resistance = resistorContainer[res_index]->getResistance(); // getting an old resistance
    (*resistorContainer[res_index]).setResistance(resistance); // setting a new resistance 
    cout << "Modified: resistor " << name << " from " << old_resistance <<" Ohms to "<< resistance << " Ohms" << endl;
   
}

//printR command
void Rparser::printR(stringstream &linestream) 
{
    string arg;
    int res_index;

    if(isFewArg(linestream)) 
        return;
    
    linestream >> arg; // getting name cannot have any error other than not putting any
    
    if (isInvalidArg(linestream)) 
        return;
            
    if (isManyArg(linestream)) 
        return;
    
    if (arg == "all") {
        cout << "Print:" << endl;
        for (int i=0; i<resCount; i++)
            (*resistorContainer[i]).print();
        return;
    }
    
    res_index = getResistorIndex(arg);
    if (res_index == -1) 
        return;
    
    cout << "Print:" << endl;
    (*resistorContainer[res_index]).print();
        
    
    
}

//printNode command
void Rparser::printNode(stringstream &linestream)
{
    int arg1 = 0;   // to get an integer argument
    string arg2; // to get a string argument
    bool printNode = true;
    
    if (isFewArg(linestream)) 
        return;
    
    linestream >> arg1;
      
    
    if (linestream.fail()) { // if "all" or any other string entered, then it will go through this block
    linestream.clear();
    linestream >> arg2;
    printNode = false;
    }
        
    // check whether the input is valid ex: not valid when :100A or 100_
    if(isInvalidArg(linestream)) 
        return;
         
    if (isBoundError(arg1))
        return;
    
    if (isManyArg(linestream))
        return;
            
    if (printNode) {
        cout << "Print:" << endl;
        nodeContainer[arg1].print(arg1);
    }
    
    else if (arg2 == "all") {
        cout << "Print:" << endl;
        for (int i =0; i<= maxNodeNumber; i++) 
        nodeContainer[i].print(i);
    }
    // if the argument is 'allA' or "all1' - invalid argument
    else
        cout << "Error: invalid argument" << endl;
      
}
        
    


//deleteR command
void Rparser::deleteR (stringstream &linestream) 
{
    string arg; // to get a user argument
    int res_index;
    

    if (isFewArg (linestream))
        return;
    
    linestream >> arg;
    
    if (isManyArg(linestream)) 
        return;
    
    if (arg != "all")  {
         cout << "Error: invalid argument" << endl;
         return;
    }
    
    for (int i=0; i<resCount; i++) {
        delete resistorContainer[i];
    }
    resCount = 0;
    
    for (int i=0; i<maxNodeNumber; i++)
        nodeContainer[i].DeleteResistors();
    
    cout << "Deleted: all resistors" << endl;    
}