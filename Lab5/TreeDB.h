#ifndef _TREEDB_H
#define _TREEDB_H

#include "TreeNode.h"
#include "DBentry.h"
#include "string"
#include <sstream>
#include <iostream>
using namespace std;

class TreeDB {

private:
   TreeNode* root;
   int probesCount;

// HelperFunctions	
   bool insertHelper(TreeNode *node, TreeNode *temp);
   DBentry* findHelper(TreeNode *node, string name);
   void printAllHelper(TreeNode *node) const;
   void clearHelper(TreeNode *node);
   void countActiveHelper(TreeNode *node, int& ActiveCount) const;

public:
   // constructor & destructor
   TreeDB();
   ~TreeDB();

   // inserts the entry pointed to by newEntry into the database. 
   // If an entry with the same key as newEntry's exists 
   // in the database, it returns false. Otherwise, it returns true.
   bool insert(DBentry* newEntry); 

   // searches the database for an entry with a key equal to name.
   // If the entry is found, a pointer to it is returned.
   // If the entry is not found, the NULL pointer is returned.
   // Also sets probesCount
   DBentry* find(string name);

   // deletes the entry with the specified name (key)  from the database.
   // If the entry was indeed in the database, it returns true.
   // Returns false otherwise.
   bool remove(string name);
	
   // deletes all the entries in the database.
   void clear();
    
   // prints the number of probes stored in probesCount
   void printProbes() const;
   
   // computes and prints out the total number of active entries
   // in the database (i.e. entries with active==true).
   void countActive () const;

   // Prints the entire tree, in ascending order of key/name
   friend ostream& operator<< (ostream& out, const TreeDB& rhs);
}; 

ostream& operator<< (ostream& out, const TreeDB& rhs);
#endif 

