#include "vehicle.hpp"
#include <string>
#include <iostream>
using namespace std;

int vehicle::checktype() { return type; }
void vehicle::modifyvrn(string nvrn) { vrn = nvrn; }
string vehicle::rvrn() { return vrn; }
int vehicle::nweapons() { return 0; }
void vehicle::modifypropulsion(int npropulsion) { propulsion = npropulsion; }
void vehicle::modifymaxcrew(int nmaxcrew) { maxcrew = nmaxcrew; }
void vehicle::modifyprice(int nprice) { price = nprice; }

string vehicle::showpropulsion() {
	string a;
	if (propulsion == 1) {
		a = "Warp drive";
		return a;
	}
	else if (propulsion == 2) {
		a = "Trace compressor";
		return a;
	}
	else if (propulsion == 3) {
		a = "FTL engine";
		return a;
	}
	else if (propulsion == 4) {
		a = "Solar sails";
		return a;
	}
	else if (propulsion == 5) {
		a = "Ion engine";
		return a;
	}
	else {
		a = "Error";
		return a;
	}
}

void vehicle::modifyweapon(int pos, weapon w){}
void vehicle::showweapon(int i) {}
void vehicle::modifycs(int cs) {}
void vehicle::modifyml(int ml) {}
void vehicle::modifyms(int ms) {}
void vehicle::modifyhn(int hn) {}
void vehicle::modifymp(int mp) {}
void vehicle::modifyes(bool es) {}
void vehicle::addweapon(int weapontype) {}
void vehicle::removeweapon(int weaponposition) {}
void vehicle::show() {}
int vehicle::ocapacity() { return 0; }
int vehicle::hn() { cout << "error"; return 0; }
//^virtual^
