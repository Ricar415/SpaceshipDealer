#include "fighter.hpp"
#include <iostream>

fighter::fighter(int dmaxspeed, int propulsiont, int pricet, weapon dweapon1, weapon dweapon2, string n){
	maxspeed = dmaxspeed;
	weapon1 = dweapon1;
	weapon2 = dweapon2;
	vrn = n;
	type = 3;
	maxcrew = 1;
	price = pricet;
	propulsion = propulsiont;
}
int fighter::ocapacity() {
	int a = weapon1.focapacity() + weapon2.focapacity();
	return a;
}
void fighter::modifyms(int ms) {
	maxspeed = ms;
}
void fighter::modifyw1(int type){
	weapon1.modify(type);
}
void fighter::modifyw2(int type) {
	weapon2.modify(type);
}
void fighter::showweapon(int wn) {
	if (wn == 1) {
		weapon1.show();
	}
	else if (wn == 2) {
		weapon2.show();
	}
}
void fighter::modifyweapon(int pos, weapon nw) {
	if (pos == 1) {
		weapon1 = nw;
	}
	else if (pos == 2) {
		weapon2 = nw;
	}
}
void fighter::show() {
	cout << "Register number: " << vrn << " Fighter Maximum Speed: " << maxspeed << " Propulsion type: " << showpropulsion() << " Maximum crew: 1 Price: " << price << endl <<" Weapon number 1: ";
	weapon1.show();
	cout << " Weapon number 2: ";
	weapon2.show();
}
bool fighter::check(string cvrn) {
	if (vrn == cvrn) return 1; else return 0;
}
string fighter::reg() {
	string temp, space = " ", t = to_string(type), p=to_string(propulsion), mc=to_string(maxcrew),pr=to_string(price), ms = to_string(maxspeed), wt1 = to_string(weapon1.returntype()), wt2 = to_string(weapon2.returntype());
	temp = vrn;
	temp += space;
	temp += t;
	temp += space;
	temp += p;
	temp += space;
	temp += mc;
	temp += space;
	temp += pr;
	temp += space;
	temp += ms;
	temp += space;
	temp += wt1;
	temp += space;
	temp += wt2;
	temp += space;
	return temp;
}