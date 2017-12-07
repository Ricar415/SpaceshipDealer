#include <string>
#include <iostream>

#include "destroyer.hpp"

using namespace std;

// -- Constructor --
destroyer::destroyer(vector<weapon> weapons,int propulsiont, int maxcrewt, int pricet, string rn) : vehicle (rn, propulsiont, maxcrewt, pricet, 2){
	weaponr = weapons;
}

// -- Modify functions --
void destroyer::modifyweapon(int position, weapon w) { weaponr[position] = w; }
void destroyer::addweapon(int weapontype) {
	weapon a(weapontype);
	weaponr.push_back(a);
}
void destroyer::removeweapon(int weaponposition) { weaponr.erase(weaponr.begin() + weaponposition); }

// -- Auxiliary functions --
int destroyer::nweapons() { return weaponr.size(); }
int destroyer::ocapacity() {
	int a = 0;
	for (unsigned int i = 0; i < weaponr.size(); i++) { a += weaponr[i].focapacity(); }
	return a;
}

// -- Show functions --
void destroyer::show() {
	cout << "Register number: " << vrn << " Destroyer; Propulsion type: "<< showpropulsion() << " Maximum crew: " << maxcrew << " Price: " << price << endl;
	for (unsigned int i = 0; i < weaponr.size(); i++) {
		cout << " Weapon number " << i + 1 << " type: ";
		weaponr[i].show();
	}
}
void destroyer::showweapon(int position) { weaponr[position].show(); }

// -- Formatting functions --
string destroyer::reg() {
	string temp, space = " ", t = to_string(type), p = to_string(propulsion), mc = to_string(maxcrew), pr = to_string(price), wt, size = to_string(weaponr.size());
	temp = vrn + space + t + space + mc + space + pr + space + size;
	for (unsigned int i = 0; i < weaponr.size(); i++) {
		wt = to_string(weaponr[i].returntype());
		temp += space;
		temp += wt;
	}
	temp += space;
	return temp;
}