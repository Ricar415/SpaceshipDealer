#include "fighter.hpp"

fighter::fighter(int dmaxspeed, weapon dweapon1, weapon dweapon2, string n){
	maxspeed = dmaxspeed;
	weapon1 = dweapon1;
	weapon2 = dweapon2;
	vrn = n;
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
void fighter::modifyvrn(string nvrn) {
	vrn = nvrn;
}