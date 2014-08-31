
#include "Rparser.h"
#include "easygl.h"

easygl window("Resistor display", WHITE);
NodeList* drawList;

//constructor & de-constructor
Rparser::Rparser() {
     drawList = &nodeList;
}

 Rparser:: ~Rparser() {
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
            
            else if (command == "setV") {
                setV(lineStream);
            }
           
            else if (command == "unsetV") {
                unsetV(lineStream);
            }
            
            else if (command == "solve") {
                solve(lineStream);
            }
            
            else if (command == "draw") {
                draw();
            }
            
            else {
                cout << "Error: invalid command" << endl;
            }
        }
       
        clearout(lineStream); // clearing white space, tab, new line before getting the next word
        cout << ">";   
        getline (cin, line);   
    } // End input loop until EOF
    
    
   //delete all allocated memory!!!
   stringstream stream(" end");
   deleteR (stream);
   nodeList.deleteAllNodes();
    
    return 0;
}









// User commands
//1.insertR command
void Rparser:: insertR (stringstream &linestream) 
{
    string name;
    double resistance;
    int nodeid1, nodeid2;

    //checking if the user input the correct arguments
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
    
    if (isFewArg (linestream)) 
        return;
    
    linestream >> nodeid2;
    
    if (isInvalidArg(linestream))
        return;
                   
    if (isSameNodeConnect (nodeid1, nodeid2))
        return;
    
    if (isManyArg (linestream))
        return;
    
    //after checking if the command line is valid, print
    cout << "Inserted: resistor " << name << " " << resistance << " Ohms "<< nodeid1 << " -> " << nodeid2 <<endl;
  
    int endpoints[] = {nodeid1, nodeid2};
    Node* temp1 = nodeList.findOrInsert(nodeid1);
    Node* temp2 = nodeList.findOrInsert(nodeid2);
    temp1->addResistor(name, resistance, endpoints);
    temp2->addResistor(name, resistance, endpoints);
  
}

//2. modifyR command
void Rparser:: modifyR(stringstream &linestream) 
{
    string name;
    double resistance, oldRes;
    int res_index;

    //checking if the user input the correct arguments
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
    
    //after checking the arguments, modify
    if (nodeList.modifyResistor(name, oldRes, resistance)) {
         cout << "Modified: resistor " << name << " from " << oldRes <<" Ohms to "<< resistance << " Ohms" << endl;
        return;
    }
    //if the resistor 'name' not found
        cout << "Error: resistor " << name << " not found"<< endl;
   
}

//3. printR command
void Rparser::printR(stringstream &linestream) 
{
    // "all" argument should be invalid error
    string arg;
    int res_index;

    //checking if the user input the correct arguments
    if(isFewArg(linestream)) 
        return;
    
    linestream >> arg; // getting name cannot have any error other than not putting any
    
    if (isInvalidArg(linestream)) 
        return;
            
    if (isManyArg(linestream)) 
        return;
    
    //printing
    Resistor* temp = nodeList.findResistor(arg);
    if (temp != NULL) {
        cout << "Print:" << endl;
        temp->print();
        return;
    }    
    //if the resistor 'name' not found
    cout << "Error: resistor " << arg << " not found"<< endl;
}


//4. printNode command
void Rparser::printNode(stringstream &linestream)
{
    int arg1 = 0;   // to get an integer argument
    string arg2; // to get a string argument
    bool printNode = true; // case 1: specific node
                           // case 0: all nodes
    
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
    
    if (isManyArg(linestream))
        return;
            
    if (printNode) {
        cout << "Print:" << endl;
        (nodeList.findOrInsert(arg1))->print();
    }
    
    else if (arg2 == "all") {
        cout << "Print:" << endl;
        nodeList.printAllNode();
    }
    // if the argument is 'allA' or "all1' - invalid argument
    else
        cout << "Error: invalid argument" << endl;
      
}
        
//5. deleteR command
void Rparser::deleteR (stringstream &linestream) 
{
    string arg; // to get a user argument
    int res_index;
    bool isDeleted = false;
  
    //checking if the user input the correct arguments
    if (isFewArg (linestream))
        return;
    
    linestream >> arg;
    
    if (isManyArg(linestream)) 
        return;
    
    if (arg == "all")  {
        nodeList.deleteAllResistor();
        cout << "Deleted: all resistors" << endl;    
        return;
    }
    
    if (arg == "end") {
        nodeList.deleteAllResistor();
        return;
    }
    
    isDeleted = nodeList.deleteResistor(arg);

    if (isDeleted) {
        cout << "Deleted: resistor "<< arg << endl;
        return;
    }    
    // if the resistor 'name' doesn't exist    
    cout << "Error: resistor " << arg << " not found"<< endl; 
}

//6. setV command
void Rparser::setV(stringstream& linestream)
{
    int nodeId;
    double voltage;
    
    //checking if the user input the correct arguments
    if (isFewArg(linestream))
        return;
    
    linestream >> nodeId;
    
    if (isInvalidArg(linestream))
        return;
    
    if (isFewArg(linestream))
        return;
    
    linestream >> voltage;
    
    if (isInvalidArg(linestream))
        return;
    
    if (isManyArg(linestream))
        return;
    
    //set the specified node
    nodeList.findOrInsert(nodeId)->set(voltage);
    cout << "Set: node " << nodeId << " to "<< voltage << " Volts" << endl;
    
}

//7. unsetV command
void Rparser:: unsetV (stringstream& linestream)
{
    int nodeId;
    
    //checking if the user input the correct arguments
    if (isFewArg(linestream))
        return;
    
    linestream >> nodeId;
    
    if (isInvalidArg(linestream))
        return;
    
    if (isManyArg(linestream))
        return;
    
    // unset the specified node
    nodeList.findOrInsert(nodeId)->unSet();
    cout << "Unset: the solver will determine the voltage of node " << nodeId << endl;
    
}

//8. solve command
void Rparser:: solve(stringstream& linestream) {
    //checking if the user input the correct arguments
    if (isManyArg(linestream))
        return;
    
    if (!(nodeList.isOneSetV())) {
        cout << "Error: no nodes have their voltage set" << endl;
         return;
    }
    
    //solve the voltage of the nodes
    cout << "Solve: "<< endl;
    nodeList.solve();
       
}










// Checking the validity of the arguments
// Removing all the spaces before the next input
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




void Rparser:: draw () {
        float xleft, ybottom, xright, ytop;
    
        nodeList.set_draw_coords(xleft, ybottom, xright, ytop);
        window.set_world_coordinates(xleft, ybottom, xright, ytop);
        
        window.gl_clearscreen();
        nodeList.draw();
        
        cout << "Draw: control passed to graphics window" <<endl;
        window.gl_event_loop();
        cout << "Draw: complete; responding to commands again"<< endl;
        
    
}

/** Redrawing the screen when the graphics package calls you (drawscreen callback) **/
void easygl::drawscreen () {
 
    window.gl_clearscreen();
    drawList->draw();
    
}