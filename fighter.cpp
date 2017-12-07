#include <iostream>

#include "fighter.hpp"

// -- Constructor --
fighter::fighter(int dmaxspeed, int propulsiont, int pricet, weapon dweapon1, weapon dweapon2, string n) : vehicle (n, propulsiont, 1, pricet, 3){
	maxspeed = dmaxspeed;
	weapon1 = dweapon1;
	weapon2 = dweapon2;
}

// -- Modify functions --
void fighter::modifyms(int ms) { maxspeed = ms; }
void fighter::modifyweapon(int pos, weapon nw) {
	if (pos == 1) { weapon1 = nw; }
	else if (pos == 2) { weapon2 = nw; }
}

// -- Auxiliary funtions --
int fighter::ocapacity() {
	int a = weapon1.focapacity() + weapon2.focapacity();
	return a;
}

// -- Show functions --
void fighter::show() {
	cout << "Register number: " << vrn << " Fighter Maximum Speed: " << maxspeed << " Propulsion type: " << showpropulsion() << " Maximum crew: 1 Price: " << price << endl <<" Weapon number 1: ";
	weapon1.show();
	cout << " Weapon number 2: ";
	weapon2.show();
}
void fighter::showweapon(int wn) {
	if (wn == 1) { weapon1.show(); }
	else if (wn == 2) { weapon2.show(); }
}

// -- Formatting functions --
string fighter::reg() {
	string space = " ", t = to_string(type), p=to_string(propulsion), mc=to_string(maxcrew),pr=to_string(price), ms = to_string(maxspeed), wt1 = to_string(weapon1.returntype()), wt2 = to_string(weapon2.returntype());
	return vrn + space + t + space + p + space + mc + space + pr + space + ms + space + wt1 + space + wt2 + space;
}