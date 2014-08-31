

#include "NodeList.h"
#include "easygl.h"
extern easygl window;


//constructor
NodeList:: NodeList() {
    head == NULL;
}

NodeList::~NodeList() {
}








//finding, printing, deleting Nodes\
//inserting in order
Node* NodeList:: findOrInsert(int nodeId_) {
    
    //pointers to search through the linklist
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL && nodeId_ > curr->nodeId) {
        prev = curr;
        curr = curr->next;
    }//end of while loop

    // case1: if head is null
    if (head == NULL) {
        head = new Node(nodeId_, curr);
        return head;
    }

    // case2: if the node already exist
    if (curr != NULL && curr->nodeId == nodeId_)
        return curr;

    // case3: if the node doesn't exist && head is not null
    if (prev !=NULL) {
        prev->next = new Node(nodeId_, curr);
        return prev->next;
    }

    // case4: if head is not null && inserting the front node
    head = new Node(nodeId_, curr);
    return head;

}

void NodeList:: printAllNode() {
    Node* curr = head;

    while (curr != NULL) {
        //printing if the resistorList has at least on resistor
        if (curr->resistorList.getNumRes() != 0)
        curr->print();

        curr = curr->next;
    }
}

void NodeList:: deleteAllNodes() {
     Node *ptr = head;
       
       while (head != NULL) {
           head = head->next;
           delete ptr;
           ptr = head;
       }  
}









//find, modify, and delete resistor             
Resistor* NodeList:: findResistor(string name) {
    Node* curr = head;
    Resistor* temp1 = NULL;

    while (curr!= NULL && temp1 == NULL) {
            temp1 = curr->getResistorList().findResistor(name); 
            curr = curr->next;
    }

    return temp1;
}
    
bool NodeList:: modifyResistor(string name, double &oldRes, double newRes) {
    Node* curr = head;
    Resistor* temp1 = NULL;
    Resistor* temp2 = NULL;

    //getting the first resistor pointer
    while (curr!= NULL && temp1 == NULL) {
        temp1 = curr->getResistorList().findResistor(name); 
        curr = curr->next;
    }

    //getting the second resistor pointer
    while (curr!= NULL && temp2 == NULL ) {
        temp2 = curr->getResistorList().findResistor(name); 
        curr = curr->next;
    }

    //no resistor with the name found, return false
    if (temp1 == NULL || temp2 == NULL)
        return false;

    //modify resistance and return true
    else {
        oldRes = temp1->getResistance();
        temp1->setResistance(newRes);
        temp2->setResistance(newRes);
        return true;
    }
}   
        
bool NodeList::deleteResistor(string name) {
    Node* curr = head;
    bool tempDeleted, isDeleted;

    while (curr!= NULL ) {
        tempDeleted =  curr->getResistorList().deleteResistor(name);
        
        // if any resistor has been deleted
        if (tempDeleted) {
            isDeleted = true; 
        }
        curr = curr->next;
    }

    return isDeleted;
}
    
void NodeList:: deleteAllResistor(){
    Node* curr = head;

    while (curr!= NULL) {
        curr->getResistorList().deleteAllResistor();
        curr = curr->next;
    }
}







//checking if any Nodes are set by 'setV' command in 'Rparser' class 
bool NodeList:: isOneSetV() {
    
    Node * curr = head;
    bool isOneSet = false;
    
    while (curr != NULL) {
        // if any node is 'set'
        if (curr->isSet)
            isOneSet = true;
        curr = curr->next;
    }
    
    return isOneSet;
}







// solve command in 'Rparser' class
void NodeList:: solve() {
    bool isDone = false;

    while (!isDone) {
        isDone = true;
        for (Node *curr = head; curr != NULL; curr = curr->next ) {

            if (!(curr->isSet)) {

                double newVoltage = solveHelper(curr);
                double change = abs (newVoltage - curr->getVoltage());
                curr->setVoltage(newVoltage);
            
                // unless any change in voltage > 0.0001, isDone is kept 'true'
                if (change > MIN_ITERATION_CHANGE)
                    isDone = false;
            }
        }
    }

    Node *curr = head;
    while (curr != NULL) {
        //print if the node's resistorList has more than one resistor
        if (curr->getResistorList().getNumRes() != 0)
                cout << " Node "<< curr->nodeId << ": "<<curr->voltage<< " V"<<endl;

        curr = curr->next;
    }

}

//crash if any resistance is 0
//helping function for solve - gets the new voltage
double NodeList:: solveHelper(Node * temp) {
    
       Resistor *ptr = temp->getResistorList().getHead();
       int nodeid = temp->nodeId;
       
       double value1 = 0; // 1/ (1/Ra + 1/Rb + 1/Rc +.....)
       double value2 = 0; // V1/Ra + V2/Rb + V3/Rc + ....
       
       while (ptr != NULL) {
            
            //getting the different end node of the resistor
            if (ptr->getEndpoints(0) == nodeid)
                value2 = value2 + (this->findOrInsert(ptr->getEndpoints(1))->voltage)/ptr->getResistance();

            else if (ptr->getEndpoints(1) == nodeid)
                value2 = value2 + (this->findOrInsert(ptr->getEndpoints(0))->voltage)/ptr->getResistance();
            
            // adding all 1/resistors
            value1 = value1 + (1/(ptr->getResistance()));
            ptr = ptr->getNext();
       }
      
       return ((1/value1)*value2);
}


string MergeString_String(string str1, string str2) {

stringstream sstm;
sstm.setf(ios::fixed);
sstm.precision(2);
sstm << str1 << str2;
return sstm.str();

}

string MergeString_Number(double num, string str1) {

stringstream sstm;
sstm.setf(ios::fixed);
sstm.precision(2);
sstm << str1 << num;
return sstm.str();

}

string MergeString_Number(string str1, double num) {
    
stringstream sstm;
sstm.setf(ios::fixed);
sstm.precision(2);
sstm << num << str1;
return sstm.str();
}

void NodeList::draw () {
   
    
    Node * curr;
    Resistor * curr1;
    curr = head;
    
    int x, y, height;
    x= 50;
    y= 0;
    height = getHeight() * 50;
    
    while (curr != NULL) {
        string temp = MergeString_Number(curr->nodeId, "Node ");
        string temp1 = MergeString_Number(" V", curr->voltage);
        window.gl_setcolor(BLACK);
        window.gl_drawrect(x,20, x+10, height); // drawing the box for the node
        window.gl_drawtext(x+5,15, temp , 100); // drawing nodeID
        window.gl_drawtext(x+5,0, temp1, 100); // drawing voltage
       
        x = x+ 100;
        
        
        curr1 = (curr->getResistorList()).getHead();
        while (curr1 != NULL) {
            int nodeid1 = curr1->getEndpoints(0);
            int nodeid2 = curr1->getEndpoints(1);
        
            if (nodeid1 == curr->nodeId) {
                if (nodeid2 >curr->nodeId) {
                    int x1 = 55 + (curr->drawID*100); 
                    int x2 = ((findOrInsert(nodeid2))->drawID * 100) + 55;
                    int x3 = x1 +(x2-x1)/2;    
                    y = y+50;
                    string temp =  MergeString_String(curr1->getName(), " (");
                    string temp1 = MergeString_Number(curr1->getResistance(), temp);
                    string temp2 = MergeString_String(temp1, " Ohms)");
                    
                    // making /\/\/\/
                    window.gl_setcolor(RED);
                    window.gl_drawline(x1, y, x3-20, y);
                    window.gl_drawline(x3-20, y, x3-10, y+5);
                    window.gl_drawline(x3-10, y+5, x3, y-5 );
                    window.gl_drawline(x3, y-5, x3+10, y+5 );
                    window.gl_drawline(x3+10, y+5,x3+20, y );
                    window.gl_drawline(x3+20, y, x2, y);
                    
                    //drawing resistance
                    window.gl_drawtext((x1+x2)/2, y-10, temp2 , 200);
                    
                }
            }
        
            else if (nodeid2 == curr->nodeId ) {
                if (nodeid1 >curr->nodeId) {
                    int x1 = 55 + (curr->drawID*100);
                    int x2 = ((findOrInsert(nodeid1))->drawID * 100) + 55;
                    int x3 = x1 +(x2-x1)/2;   
                    y = y+50;
                    
                    string temp = MergeString_String(curr1->getName(), " (");
                    string temp1 = MergeString_Number(curr1->getResistance(), temp);
                    string temp2 = MergeString_String(temp1, " Ohms)");
               
                    // making /\/\/\/
                    window.gl_setcolor(RED);
                    window.gl_drawline(x1, y, x3-20, y);
                    window.gl_drawline(x3-20, y, x3-10, y+5);
                    window.gl_drawline(x3-10, y+5, x3, y-5 );
                    window.gl_drawline(x3, y-5, x3+10, y+5 );
                    window.gl_drawline(x3+10, y+5,x3+20, y );
                    window.gl_drawline(x3+20, y, x2, y);
                     
                    //drawing resistance
                    window.gl_drawtext((x1+x2)/2, y-10, temp2, 200);

                }

            }
        curr1 = curr1->getNext();
        }
        
        curr = curr->next;
    }
    

}

void NodeList::set_draw_coords (float& xleft, float& ybottom, float& xright, float& ytop) {
    int numAllNode=0;
    
    Node * curr;
    curr = head;
    
    while (curr!= NULL) {
        
        curr->drawID = numAllNode;
        numAllNode ++;
        curr = curr->next;
       
    }
    
    xleft = 0;
    ybottom = 0;
    xright = numAllNode *100;
    ytop = (getHeight()) * 50;
    
}

//getting the height of the graphic coordinate
int NodeList:: getHeight() {
    int numAllRes=0;
    
    Node * curr;
    curr = head;
    
    while (curr!= NULL) {
        numAllRes += (curr->getResistorList()).getNumRes();
        curr = curr->next;
    }
    
    return (numAllRes/2 +1);
}