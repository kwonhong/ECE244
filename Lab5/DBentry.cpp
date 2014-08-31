#include "DBentry.h"

//Constructors & Destructors
DBentry:: DBentry(){    
}

DBentry:: DBentry (string _name, unsigned int _IPaddress, bool _active) {
    this->IPaddress = _IPaddress;
    this->active = _active;
    this->name = _name;
}

DBentry:: ~DBentry() {
    
}

//get&set functions
void DBentry:: setName(string _name) {
    this->name = _name;
}

void DBentry:: setIPaddress(unsigned int _IPaddress) {
    this->IPaddress = _IPaddress;
}

void DBentry:: setActive (bool _active) {
    this->active = _active;
}
   
string DBentry:: getName() const {
    return name;
}

unsigned int DBentry:: getIPaddress() const {
    return IPaddress;
}

bool DBentry:: getActive() const {
    return active;
}

ostream& operator<< (ostream& out, const DBentry& rhs) {

    if (rhs.active)
        out << rhs.name << " : "<< rhs.IPaddress<< " : active" <<endl;
    else 
        out << rhs.name  << " : "<< rhs.IPaddress<< " : inactive" <<endl; 
    return out;
}
