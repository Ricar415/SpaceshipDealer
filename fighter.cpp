#include "fighter.hpp"
#include <iostream>

fighter::fighter(int dmaxspeed, weapon dweapon1, weapon dweapon2, string n){
	maxspeed = dmaxspeed;
	weapon1 = dweapon1;
	weapon2 = dweapon2;
	vrn = n;
	type = 3;
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
	cout << "Register number: " << vrn << " Fighter Maximum Speed: " << maxspeed << " Weapon 1: ";
	weapon1.show();
	cout << " Weapon2: ";
	weapon2.show();
	cout << endl;	
}