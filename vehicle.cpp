#include "vehicle.hpp"

using namespace std;

vehicle::vehicle(string _vrn, owner *_vehicle_owner, int _propulsion, int _maxcrew, int _price, int _type){
	vrn = _vrn;
	vehicle_owner = _vehicle_owner;
	propulsion = _propulsion;
	maxcrew = _maxcrew;
	price = _price;
	type = _type;
}


int vehicle::checktype() { return type; }
void vehicle::modifyvrn(string nvrn) { vrn = nvrn; }
string vehicle::rvrn() { return vrn; }
void vehicle::modifyowner(owner *nvehicle_owner) { vehicle_owner = nvehicle_owner; }
void vehicle::modifypropulsion(int npropulsion) { propulsion = npropulsion; }
void vehicle::modifymaxcrew(int nmaxcrew) { maxcrew = nmaxcrew; }
void vehicle::modifyprice(int nprice) { price = nprice; }

string vehicle::showpropulsion() {

	string a;
	if (propulsion == 1) {
		a = "Warp drive       ";
		return a;
	}
	else if (propulsion == 2) {
		a = "Trace compressor ";
		return a;
	}
	else if (propulsion == 3) {
		a = "FTL engine       ";
		return a;
	}
	else if (propulsion == 4) {
		a = "Solar sails      ";
		return a;
	}
	else if (propulsion == 5) {
		a = "Ion engine       ";
		return a;
	}
	else {
		a = "Error            ";
		return a;
	}
}

string vehicle::to_string(int a){
    stringstream stream;
    stream << a;
    return stream.str();
}
