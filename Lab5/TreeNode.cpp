#include "TreeNode.h"

//Constructor & destructor
TreeNode:: TreeNode(DBentry* _entryPtr) {
    this->entryPtr = _entryPtr;
    this->left = NULL;
    this->right = NULL;
}

TreeNode:: ~TreeNode() {
    delete entryPtr;
}

// get&set functions
void TreeNode:: setLeft(TreeNode* newLeft) {
    this->left = newLeft;
}

void TreeNode:: setRight(TreeNode* newRight) {
    this->right = newRight;
}

TreeNode* TreeNode:: getLeft() const {
    return left;
}

TreeNode* TreeNode:: getRight() const {
    return right;
}

DBentry* TreeNode:: getEntry() const {
    return entryPtr;
}

// remove & removeHelper function 
void TreeNode:: removeHelper2(TreeNode*& node) {
// base cases
    if(right == NULL)
        return;
    
    if (right->left == NULL) {
        node = right;
        return;
    }
// recursion     
    TreeNode* temp = right->left;
    removeHelper2(right->left);

//switching the position    
    temp->right = right;
    temp->left = left;
    node = temp;
    
}

bool TreeNode:: remove(string name, TreeNode*& node) {
     string currNodeName = node->getEntry()->getName();
     
      //if the newEntry's name is bigger than the current node name
     if (name.compare(currNodeName) > 0) {
         if (right == NULL) {
             return false;
         }
         else {
             return right->remove (name, right);
         }
     }
     
     // if the newEntry's name is smaller than the current node name
     else if(name.compare(currNodeName) < 0) {
         if (left == NULL) {
             return false;
         }
         else {
             return left->remove (name,left);
         }
     }
     
     //if the newEntry exists
     if (name.compare(currNodeName) == 0) {
         // no subtree
         if (left == NULL && right == NULL) {
             node = NULL;
             delete this;
         }
         //only right subtree
         else if (left == NULL && right != NULL) {
             node = right;
             delete this;
         }
         
         //only left subtree
         else if (left != NULL && right == NULL) {
             node = left;
             delete this;
         }
         
         //two subtrees
         else {
             removeHelper2(node);
             delete this;
         } 
     
         return true;
     
     
     
     }
}
