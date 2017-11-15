#include "vehicle.hpp"
vehicle::vehicle(int prop, int m, int p, int t, string n){
    propulsion = prop;
    maxcrew = m;
    price = p;
    type = t;
    strcpy(&vrn,n);
    *owner = new string;
    available = 1;
}
vehicle::vehicle(string n){
    strcpy(&vrn,n);
}
vehicle::~vehicle(){
    delete[] *owner;
}
void vehicle::modifyp(int){};
void vehicle::modifymc(int){};
void vehicle::modifytype(int){};
void vehicle::modifyprice(int){};
void vehicle::modifyowner(string o){
    strcpy(&owner,o);
};
void vehicle::modifyavailability(){};
void vehicle::modifylist(string n){};
