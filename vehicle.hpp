#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include <sstream>
#include <iostream>

#include "weapon.hpp"
#include "owner.hpp"

using namespace std;

class vehicle {

protected:

	string vrn;
	int type, propulsion, maxcrew, price; /// common parameters of all vehicle types
	owner *vehicle_owner;

public:

    // -- Constructor --
	vehicle(string _vrn, owner *_vehicle_owner, int _propulsion, int _maxcrew, int _price, int _type);

    // -- Destructor --
    virtual ~vehicle(){}

    // -- Modify functions --

	void modifyvrn(string nvrn); /// sets register number to the given one 
	void modifyowner(owner *nvehicle_owner); /// sets vehicle owner to the given one
	void modifypropulsion(int npropulsion); /// sets propulsion type to the given one
	void modifymaxcrew(int nmaxcrew); /// sets maximum crew to the given one
	void modifyprice(int nprice); /// sets price to the given one
    // - virtual modify functions -
    virtual void modifyweapon(int pos, weapon w) {}
    virtual void modifycs(int cs) {}
    virtual void modifyml(int ml) {}
    virtual void modifyms(int ms) {}
    virtual void modifymp(int mp) {}
    virtual void modifyhn(int hn) {}
    virtual void modifyes(bool es) {}
    virtual void addweapon(int weapontype) {}
    virtual void removeweapon(int weaponposition) {}


    // -- Auxiliary functions --

	string rvrn(); /// returns vehicle register number
	int checktype(); /// returns vehicle type
	/// - virtual auxiliary functions -
    virtual int nweapons() { return 0; } /// fighters and destroyers will have their own definition
    virtual int ocapacity() { return 0; } /// fighters and destroyers will have their own definition
    virtual int hn() { return 0; }

    // -- Show functions --

	string showpropulsion(); /// returns propulsion type in readable way
    // - virtual show functions -
	virtual void show() = 0;
    virtual void showweapon(int a) {}


    // -- Formatting functions --

    string to_string(int a);
	virtual string reg() = 0;

};
#endif
