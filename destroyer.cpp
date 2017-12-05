#include "destroyer.hpp"
#include <string>
#include <iostream>

using namespace std;
destroyer::destroyer(vector<weapon> weapons,int propulsiont, int maxcrewt, int pricet, string rn){
	vrn = rn;
	weaponr = weapons;
	type = 2;
	propulsion = propulsiont;
	maxcrew = maxcrewt;
	price = pricet;
}
void destroyer::modifyweapons(int position, int type) {
	weapon a(type);
	weaponr[position] = a;
}
int destroyer::nweapons() {
	return weaponr.size();
}
void destroyer::showweapon(int position) {
	weaponr[position].show();
}
void destroyer::modifyweapon(int position, weapon w) {
	weaponr[position] = w;
}
void destroyer::addweapon(int weapontype) {
	weapon a(weapontype);
	weaponr.push_back(a);
}
void destroyer::removeweapon(int weaponposition) {
	weaponr.erase(weaponr.begin() + weaponposition);
}
void destroyer::show() {
	cout << "Register number: " << vrn << " Destroyer; Propulsion type: "<< showpropulsion() << " Maximum crew: " << maxcrew << " Price: " << price << endl;
	for (unsigned int i = 0; i < weaponr.size(); i++) {
		cout << " Weapon number " << i + 1 << " type: ";
		weaponr[i].show();
	}
}
int destroyer::ocapacity() {
	int a = 0;
	for (unsigned int i = 0; i < weaponr.size(); i++) {
		a += weaponr[i].focapacity();
	}
	return a;
}
bool destroyer::check(string cvrn) {
	if (vrn == cvrn) return 1; else return 0;
}
string destroyer::reg() {
	string temp = vrn, space = " ", t = to_string(type), p = to_string(propulsion), mc = to_string(maxcrew), pr = to_string(price), wt;
	temp += space;
	temp += t;
	temp += space;
	temp += p;
	temp += space;
	temp += mc;
	temp += space;
	temp += pr;
	temp += space;
	temp += to_string(weaponr.size());
	for (int i = 0; i < weaponr.size(); i++) {
		wt = to_string(weaponr[i].returntype());
		temp += space;
		temp += wt;
	}
	temp += space;
	return temp;
}