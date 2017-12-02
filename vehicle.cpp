#include "vehicle.hpp"
#include <string>
#include <iostream>
using namespace std;

bool vehicle::check(string vrn) { cout << "nodeberiasestaraqui"; return 1; }
int vehicle::checktype() {
	return type;
}
void vehicle::modifyvrn(string nvrn) {
	vrn = nvrn;
}
string vehicle::rvrn() {
	return vrn;
}
int vehicle::nweapons() {
	return 0;
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
//^virtual^
