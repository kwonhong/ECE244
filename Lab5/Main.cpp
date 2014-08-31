
#include <iostream>
#include <sstream>
#include <string>
#include "TreeDB.h"
#include "TreeNode.h"
#include "DBentry.h"
using namespace std;

int main(int argc, char** argv) {
    string line, command;
    TreeDB treeDB;
    
    cout << ">";
    getline(cin, line);
        
    while (!cin.eof()) {
        
        stringstream linestream (line);
        linestream >> command;
        

        //Parsing 'insert' function
        if (command == "insert") {
           
            string name,status;
            int IPaddress;
            DBentry *temp;
            linestream >> name >> IPaddress >> status;
      
            
            // active - passing "1" for the active boolean value
            // inactive - passing "0" for the active boolean value
            if (status == "active") 
            temp = new DBentry(name, IPaddress, 1);
            else
            temp = new DBentry(name, IPaddress, 0);
           
            //inserting to Tree
	    //isSucceeded = 0 when the DBentry already exists
            bool isSucceeded = treeDB.insert(temp);
            if (isSucceeded) 
                cout << "Success" << endl;
            else
                cout << "Error: entry already exists" << endl;
        }
        
	//Parsing 'find' function
        else if (command == "find") {

            string name;
            linestream >> name;
	    
	    //'find' function in treeDB class returns DBentry (if exists)	
            DBentry *temp = treeDB.find(name);
            
	    // if DBentry with 'name' doesn't exist
            if (temp == NULL)
                cout << "Error: entry does not exist" <<endl;

            //printing the DBentry information		
            else if (temp->getActive())
                cout << temp->getName() << " : "<< temp->getIPaddress()<< " : active" <<endl;
            else 
                cout << temp->getName() << " : "<< temp->getIPaddress()<< " : inactive" <<endl;
        }

	//Parsing 'remove' function        
        else if (command == "remove") {
            string name;
            linestream >> name;
	    
	// 'remove' function in treeDB class returns true if DBentry with 'name' exists
            bool isRemoved = treeDB.remove(name);
	
	// printing if the removing the DBentry was successful
            if (isRemoved)
                cout << "Success" <<endl;
            else
                cout << "Error: entry does not exist" <<endl;
        }

        //Parsing 'printall' function
        else if (command == "printall") {

	    // prints all the DBentry within the database.
            cout << treeDB ;
        }
        
	//Parsing 'printprobes' function
        else if (command == "printprobes") {
             string name;
             linestream >> name;
	     
	     //'find' function in treeDB also sets the probeCounts variable in treeDB class"	
             DBentry *temp = treeDB.find(name);
	     
 	     // printing 	
             if (temp == NULL) {
                 cout << "Error: entry does not exist" <<endl;
             }
             else 
                 treeDB.printProbes();
        }
        
	//Parsing 'removeall' function
        else if (command == "removeall") {
            treeDB.clear();
            cout << "Success" <<endl;
        }
        
	//Parsing 'countactive' function
        else if (command == "countactive") {
            
		// prints how many DBentries are set as "active"
		treeDB.countActive();
        }
        
	//Parsing 'updatestatus' function
        else if (command == "updatestatus") {
            string name, status;
            linestream >> name >> status;

            DBentry *temp = treeDB.find(name);
	
	// when DBentry with 'name' is not found
            if (temp == NULL)
                cout << "Error: entry does not exist" <<endl;

	// updating the status
            else {
                if (status == "active") 
                    temp->setActive(true);
                
                else if (status =="inactive")
                    temp->setActive(false);
                        
                cout <<"Success" <<endl;
            }
        }
        
        cout << ">";
        getline(cin, line);
    } // end of while loop
    
    
    
    
    
    
    return 0;
}

