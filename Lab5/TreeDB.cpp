#include "TreeDB.h"
//Constructor & Deconstructors
TreeDB::TreeDB() {
    root = NULL;
}
TreeDB:: ~TreeDB() {
	if (root == NULL)
	return;

	clearHelper(root);            
}
//insert & insertHelper
 bool TreeDB:: insert(DBentry* newEntry) {  
     TreeNode *temp = new TreeNode(newEntry);
     //base case
     if (root == NULL) {
         root = temp;
         return true;
     }
     //recursion
     return (insertHelper (root, temp));
 
 }

 bool TreeDB:: insertHelper(TreeNode* node, TreeNode *temp) {
     string newName =temp->getEntry()->getName();
     string currNodeName = node->getEntry()->getName();
     
     //if the newEntry already exists
     if (newName.compare(currNodeName) == 0) {
         delete temp;
         return false;
     }
     
     //if the newEntry's name is bigger than the current node name
     if (newName.compare(currNodeName) > 0) {
         if (node->getRight() == NULL) {
             node->setRight(temp);
             return true;
         }
         else
             return insertHelper (node->getRight(), temp);
     }
     
     // if the newEntry's name is smaller than the current node name
     else {
         if (node->getLeft() == NULL) {
             node->setLeft(temp);
             return true;
         }
         else
             return insertHelper (node->getLeft(),temp);
     }
     
 }

//find & findHelper Functions
DBentry* TreeDB:: find(string name) {
    
    //base case
    if (root == NULL) {
       return NULL;
    }
    
    probesCount = 0;
    //recursion
    return (findHelper (root, name));
}

DBentry* TreeDB:: findHelper(TreeNode *node,string name) {
    string currNodeName = node->getEntry()->getName();
    
    //if the newEntry exists
     if (name.compare(currNodeName) == 0) {
         probesCount ++;
         return node->getEntry();
     }
     
     //if the newEntry's name is bigger than the current node name
     if (name.compare(currNodeName) > 0) {
         if (node->getRight() == NULL) {
             return NULL;
         }
         else {
             probesCount ++;
             return findHelper (node->getRight(), name);
         }
     }
     
     // if the newEntry's name is smaller than the current node name
     else {
         if (node->getLeft() == NULL) {
             return NULL;
         }
        else {
             probesCount ++;
             return findHelper (node->getLeft(), name);
         }
     }
}

//remove function
bool TreeDB:: remove(string name) {
    
    if (root == NULL) {
       return false;
    }
    //remove the DBentry within 'TreeNode' class
    return root->remove(name, root);
}


void TreeDB:: clear() {
    if (root == NULL)
        return;
    
    
    clearHelper(root);
    root = NULL;
}

void TreeDB:: clearHelper(TreeNode *node) {
    if (node == NULL)
        return;
    
    clearHelper(node->getLeft());
    clearHelper(node->getRight());
    delete node;
    node = NULL; //safety
}
    
  
void TreeDB:: printProbes() const {
    cout << probesCount <<endl;;
}

//Count and CountActiveHelper function
void TreeDB:: countActive () const {
	int activeCount = 0;
	countActiveHelper(root, activeCount);
	cout << activeCount << endl;
}

void TreeDB:: countActiveHelper(TreeNode *node, int& ActiveCount) const {
	//base case	
	if (node == NULL)
		return;
	// recursion
	countActiveHelper(node->getLeft(), ActiveCount);
	countActiveHelper(node->getRight(), ActiveCount);
	//printing
	if (node->getEntry()->getActive()) ActiveCount++;
}

//printAll and Helper function
ostream& operator<< (ostream& out, const TreeDB& rhs)   {
    if (rhs.root == NULL)
        return out;
    
    rhs.printAllHelper(rhs.root);
    return out;
}

void TreeDB:: printAllHelper(TreeNode *node) const {
    if (node == NULL)
        return;
    
    printAllHelper(node->getLeft());
    cout << *(node->getEntry());
    printAllHelper(node->getRight());
}
	
