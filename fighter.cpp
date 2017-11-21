#include "fighter.hpp"

fighter::fighter(int dmaxspeed, weapon dweapon1, weapon dweapon2, string n){
	maxspeed = dmaxspeed;
	weapon1 = dweapon1;
	weapon2 = dweapon2;
	vrn = n;
	type = 3;
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