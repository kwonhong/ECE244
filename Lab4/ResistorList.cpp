#include "ResistorList.h"

//Constructor
ResistorList::ResistorList() {
    numRes = 0;
    head = NULL;
}

//get & set functions
 Resistor* ResistorList:: getHead() {
       return head;
 }
 
 int ResistorList:: getNumRes() {
     return numRes;
 }
  
//insert, delete, find resistors
//stacking resistors in the list (not in order)
void ResistorList:: insertResistor(string name_, double resistance_, int endpoints_[]) {
    Resistor* prev = NULL;
    Resistor* curr = head;
    
    while (curr!= NULL) {
        prev = curr;
        curr = curr-> next;
    }
    
    Resistor* newResistor = new Resistor ( name_, resistance_,  curr, endpoints_);
    if (prev != NULL)
        prev->next = newResistor;
    else
        head = newResistor;
    
    numRes++;
}

Resistor* ResistorList:: findResistor( string name) {
    Resistor *ptr;

    for(ptr = head; ptr !=NULL; ptr = ptr->next) {
        if (name == ptr->name)
            return ptr;
    }
    // if the resistor 'name' doesn't exist
    return (NULL);
}

bool ResistorList::deleteResistor(string name) {
    Resistor *ptr, *prev = NULL;

    //Iterate through list
    for (ptr = head; ptr!= NULL; ptr = ptr->next) {
        if (name == ptr->getName()) {
            if (prev != NULL)
                prev->next = ptr->next;
            else // case: if the resistorlist is empty
                head = ptr->next;
        delete ptr;
        numRes --; // decrease the #of resistor if succeeded deleting
        return (true); // return true if succeded deleting
        }
    prev = ptr;
    }
    
    //if the resistor 'name' doesn't exist
    return false;
}
  
void ResistorList:: deleteAllResistor() {
    Resistor *ptr = head;

    while (head != NULL) {
        head = head->next;
        delete ptr;
        ptr = head;
    }
    numRes = 0;
}
  
//printing all resistor info
 void ResistorList::printAllResistor() {
     Resistor *curr;
     
     for (curr = head; curr != NULL; curr = curr->next) {
         (*curr).print();
     }
 }
 



