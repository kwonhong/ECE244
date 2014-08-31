/* 
 * File:   Parser.cpp
 * Author: kwonhong
 *
 * Created on September 23, 2013, 9:45 AM
 */

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

#define MAX_NODE_NUMBER 5000
#define MIN_NODE_NUMBER 0

void insertR (stringstream &linestream);
void modifyR(stringstream &linestream);
void printR(stringstream &linestream);
void printNode(stringstream &linestream);
void deleteR (stringstream &linestream);
bool invalidArg(stringstream &linestream, bool error);
bool negativeRes(double resistance);
double getResistance (stringstream &linestream); 
bool BoundError (int node); 
bool Res_all (string resistor);
bool SameNodeConnect (int node1, int node2, bool FewArg);
bool ManyArg(stringstream &linestream);
bool FewArg (stringstream &linestream);
int parser();



bool mInvalidArg = true; // Used to check if the command has any invalid arguments when printing


int main() {
    cout.setf(ios::fixed);
    cout.precision(2);
    return parser();
}

// return 0 if the parser function works perfectly
int parser() {
    
    string line, command;
    
    cout << ">";
    getline(cin, line); //Get a line from standard input.
    
    while (!cin.eof()) {
     
    if ( line != "") {   
            stringstream lineStream(line);
            lineStream >> command;

            if (command == "insertR") {
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
        cout << ">";   
        getline (cin, line);   
    } // End input loop until EOF

    return 0;
}

// Testing if the inputs are valid
bool invalidArg(stringstream &linestream) {
    
    
    // testing if the input type is wrong
    if (linestream.fail()  ) {
        
        linestream.clear();
        linestream.ignore(190000000, '\n');
        cout << "Error: invalid argument"<< endl;
    
        return true;
    }
    // testing if there is any invalid input right next to the correct input
    // ex) resistance = 100.01_, -10.2a , 1002.3
    // ex) node = 10.1, 10A
    else if (linestream.peek() != ' ' && linestream.peek() != '\n' && linestream.peek() != '\t' && linestream.peek() != 0 && linestream.peek() != -1) {
        linestream.clear();
        linestream.ignore(190000000, '\n');
        cout << "Error: invalid argument"<< endl;
    
        return true;
    
    
    }
    return false;
}

//Testing whether the resistance value is negative or not
bool negativeRes (double resistance) {
    if (resistance < 0) {
        cout << "Error: negative resistance" << endl;
        return true;
    }
    return false;
    
}


// Testing whether the node value is between 0-5000
bool BoundError (int node1) {
   
    if ( (node1 > MAX_NODE_NUMBER || node1 < MIN_NODE_NUMBER)) {
        
        cout << "Error: node "<< node1 << " is out of permitted range " << MIN_NODE_NUMBER << "-" << MAX_NODE_NUMBER<< endl;     
        return true;
        
    }
    return false;
}

//Testing whether the user input the name of resistance as "all"
bool Res_all (string resistor) {
    if (resistor == "all") {
        cout << "Error: resistor name cannot be the keyword \"all\""<< endl;
        return true;
    }
    return false;
}

// Testing if the two nodes have the same value
// Check if the user input has right amount of argument 
bool SameNodeConnect (int node1, int node2, bool FewArg) {
    if (!FewArg && (node1 == node2)) {
       cout<< "Error: both terminals of resistor connect to node "<< node1 << endl;
       return true;
    }
    
    return false;
}

//Testing for too many arguments
bool ManyArg(stringstream & linestream) {
    char c = linestream.get();
    
    // linestream.peek gives a value '-1' if no character is read.
    if (linestream.peek() != -1) {
        cout << "Error: too many arguments" << endl;
        return true;
    }
    return false;
}

//Testing for too many arguments
bool FewArg (stringstream & linestream) {
    char c = linestream.get();
    
     // linestream.peek gives a value '-1' if no character is read.
    if (linestream.peek() == -1){
        linestream.clear(); // getting "-1" from "peek()" method might turn 'linestream' into 'fail' mode
        return true;
    }
    return false;
}
// insertR command
void insertR (stringstream &linestream) 
{
    string name;
    double resistance;
    int nodeid1, nodeid2;
    mInvalidArg = true; // reset the variable to true since no error has occured
    bool printOutput = false; // to check if the input passes Res_all, negativeResistance, BoundError for nodes
    bool mFewArg = FewArg(linestream); // Used to check if the command has few arguments.
    
    if (!mFewArg) {
        linestream >> name;
        
        
        if (!Res_all(name)) { // checking if the resistor name is 'all'
            mFewArg = FewArg(linestream);   // after getting name input, checking if there are any more arguments!
            
            if (!mFewArg) {
                linestream >> resistance;
                
                if (invalidArg(linestream)) { // checking if resistance value is invalid
                    mInvalidArg = false;
                }
                    
                    if (mInvalidArg && !negativeRes(resistance)) {// checking if the resistance is negative
                    
                        mFewArg = FewArg(linestream); // after getting resistance value, checking if there are any more arguments!
                        if (!mFewArg) {
                            linestream >> nodeid1;

                                if (invalidArg(linestream)) { // checking if the first node value is invalid
                                    mInvalidArg  = false;
                                }

                                if (mInvalidArg && !BoundError(nodeid1))  { // checking if the first node is within the bound
                                    mFewArg = FewArg(linestream);  // after getting first node value, checking if there are any more arguments!

                                        if (!mFewArg) {
                                        linestream >> nodeid2;

                                            if (invalidArg(linestream)) // checking if the second node is invalid
                                                mInvalidArg = false;

                                            if (mInvalidArg && !BoundError(nodeid2)) { // checking if the second node is within the bound
                                                printOutput = true; // if the processor comes to this point, it means it passed all other cases above
                                            }

                                        }
                                }

                        }
              
                 }
            }
        }
    }
    
    
    // checking whether to print the correct output or TooMany/TooFew arguments error
    if (mInvalidArg && printOutput && !SameNodeConnect(nodeid1, nodeid2, mFewArg) && !ManyArg(linestream) ) {
       
        if (!mFewArg ) 
        cout << "Inserted: resistor " << name << " " << resistance << " Ohms "<< nodeid1 << " -> " << nodeid2 <<endl;
        
        else 
        cout << "Error: too few arguments" << endl;
        
    }
}

//modifyR command
void modifyR(stringstream &linestream) 
{
    string name;
    double resistance;
    mInvalidArg = true; // reset the variable to true since no error has occured
    bool printOutput = false; // to check if it passes NegativeResistance
    bool mFewArg = FewArg(linestream); // Used to check if the command has few arguments.       
    
    if (!mFewArg) {
        linestream >> name;
        
        if (!Res_all(name)) {
            mFewArg = FewArg(linestream);   // after getting name input, checking if there are any more arguments!

            if (!mFewArg) {
                    linestream >> resistance;

                    if (invalidArg(linestream)) { // checking whether resistance value is valid or not
                            mInvalidArg = false;
                    }
                    
                    if (mInvalidArg && !negativeRes(resistance)) {
                        printOutput = true;
                    }
                    
                    

            }
        }
    }
    
    //checking errors in priority
    if (mInvalidArg && printOutput && !ManyArg(linestream)) {
        
        if (!mFewArg) 
          cout << "Modified: resistor " << name << " to " << resistance << " Ohms" << endl;
        
        else 
            cout << "Error: too few arguments" << endl;
    }
}

//printR command
void printR(stringstream &linestream) 
{
    string arg;
    bool mFewArg = FewArg(linestream); // Used to check if the command has few arguments.
    mInvalidArg = true; // reset the variable to true since no error has occured
    
    if(!mFewArg) {
         linestream >> arg; // getting name cannot have any error other than not putting any
    
        if (invalidArg(linestream)) {
            mInvalidArg = false;
            
        }
    }
    
    if (mInvalidArg && !ManyArg(linestream)) {
        if (!mFewArg) {
                    if (arg == "all") 
                        cout << "Print: all resistors" << endl;
                    else
                        cout << "Print: resistor "<< arg << endl;
        }

        else
        cout << "Error: too few arguments"<< endl;
    
    }
}

//printNode command
void printNode(stringstream &linestream)
{
    int arg1 = 0;   // to get an integer argument
    string arg2; // to get a string argument
    mInvalidArg = true; // reset the variable to true since no error has occured
    bool mFewArg = FewArg(linestream); // Used to check if the command has few arguments.
    bool printNode = true; // 1: pringting Node , 0: printing all
    
    if (!mFewArg) {
        linestream >> arg1;
      
        if (linestream.fail()) { // if "all" or any other string entered, then it will go through this block
        linestream.clear();
        linestream >> arg2;
        printNode = false;
        }
        
        // check whether the input is valid ex: not valid when :100A or 100_
        if(invalidArg(linestream)) { 
                mInvalidArg = false;
        }
        
    }
    
    if (mInvalidArg && !BoundError(arg1) && !ManyArg(linestream)) {
       
        if (!mFewArg) {
            
            if (printNode)
            cout << "Print: node "<< arg1 << endl;
            
            else if (arg2 == "all")
                cout << "Print: all nodes" << endl;
            
            // if the argument is 'allA' or "all1' - invalid argument
            else
                cout << "Error: invalid argument" << endl;
        }
        
        else
            cout << "Error: too few arguments" << endl;
    }
        
    
}

//deleteR command
void deleteR (stringstream &linestream) 
{
    string arg; // to get a user argument
    bool mFewArg = FewArg(linestream); // Used to check if the command has few arguments.
    
    if (!mFewArg)
    linestream >> arg;
    
    if (!ManyArg(linestream)) {
        if (!mFewArg) {
            
            if (arg == "all") 
                cout << "Deleted: all resistors" << endl;
           
            else
                cout << "Deleted: resistor "<< arg << endl;
        }
        
        else 
            cout << "Error: too few arguments" << endl;
    }
    
}


